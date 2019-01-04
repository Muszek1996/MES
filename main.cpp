#include <iostream>
#include "Utils/ReadFile.h"
#include "DataStructures/Node/Node.h"
#include "DataStructures/Element/Element.h"
#include "DataStructures/Grid/Grid.h"
#include "Jacobian/Jacobian.h"
#include "HMatrix/HMatrix.h"
#include "CMatrix/MatrixC.h"
#include "BoundaryConditions/BoundC.h"
#include "VectorP/VectorP.h"
#include "TempVector/TVector.h"
#include "Utils/GausianElimination.h"
#include "Utils/MatrixInitializer.h"


int main() {

    std::map<string,double> inputData = FS::read();
    double t0 = inputData.find("t0")->second;
    double simulation_time = inputData.find("simulation_time")->second;
    double simulation_step = inputData.find("simulation_step")->second;
    double ambient_temp = inputData.find("ambient_temp")->second;
    double alfa = inputData.find("alfa")->second;
    double H = inputData.find("H")->second;
    double L = inputData.find("L")->second;
    int nH = static_cast<int>(inputData.find("nH")->second);
    int nL = static_cast<int>(inputData.find("nL")->second);
    double specific_heat = inputData.find("specific_heat")->second;
    double conductivity = inputData.find("conductivity")->second;
    double density = inputData.find("density")->second;

    cout << "FILE INPUT DATA \n"
    << "t0=" << t0 << endl
    << "simulation_time=" << simulation_time << endl
    << "simulation_step=" << simulation_step << endl
    << "ambient_temp=" << ambient_temp << endl
    << "alfa=" << alfa << endl
    << "H=" << H << endl
    << "L=" << L << endl
    << "nH=" << nH << endl
    << "nL=" << nL << endl
    << "specific_heat=" << specific_heat << endl
    << "conductivity=" << conductivity << endl
    << "density=" << density << endl;




    int nodeCount = static_cast<int>(nH*nL);
    int elementCount = static_cast<int>((nH-1)*(nL-1));
    double stepH = H/(nH-1);
    double stepL = L/(nL-1);
    int nLminus1 = nL-1;
    int nHminus1 = nH-1;



    Node** nodes = new Node*[nodeCount];

    for(int i = 0;i<nL;i++)
    for(int j = 0;j<nH;j++){
        int itr = j+(i*(nH));
        nodes[itr] = new Node(itr+1,i*stepL,j*stepH,t0);
    }

    Element ** elements = new Element*[elementCount];

    for(int i=0;i<nLminus1;i++)
    for(int j=0;j<nHminus1;j++){
        int itr = j+(i*(nHminus1));
        bool bc[4] = {0,0,0,0};
        if(j==0)bc[0] = 1;
        if(j==nHminus1-1) bc[2] = 1;
        if(i==0)bc[3]=1;
        if(i==nLminus1-1) bc[1] = 1;

        elements[itr] = new Element(itr,nodes[itr+i],nodes[itr+i+nH],nodes[itr+i+nH+1],nodes[itr+i+1],bc);
    }

    Grid grid(nodes,elements,nH,nL);

   // grid.print();


    double cMatrixGlobal[nodeCount][nodeCount];
    double **hMatrixGlobal = MatrixInitializer::init(nodeCount,nodeCount);

    for(int i = 0;i<nodeCount;i++)
        for(int j = 0;j<nodeCount;j++) {
            cMatrixGlobal[i][j] = 0;
            hMatrixGlobal[i][j] = 0;
        }

    double pVector[nodeCount];



    for(int i = 0;i<elementCount;i++){
        Element el = *elements[i];
        double ** matrixHandBC = HMatrix::count(*elements[i],conductivity);
        double ** matrixC_dT = MatrixC::count(*elements[i],specific_heat,density);
        double ** matrixH_BC = BoundC::count(*elements[i],alfa);
        double * vectorP = VectorP::count(*elements[i],alfa,ambient_temp);
        double * vectorT = TVector::count(*elements[i]);
        double * t0Vector = el.getTemps();


        // matrixHandBC = MatrixH + H_BC + C/dT

        for (int k = 0; k < 4; k++) {
            for (int j = 0; j < 4; j++) {
                matrixHandBC[k][j] += matrixH_BC[k][j];
                matrixC_dT[k][j] /= simulation_step;
                matrixHandBC[k][j] += matrixC_dT[k][j];
            }
        }



        double *pCTauT0 = new double[4];
        for (int k = 0; k < 4; k++) {
            pCTauT0[k] = 0;
            for (int j = 0; j < 4; j++) {
                pCTauT0[k]+=matrixC_dT[k][j]*t0Vector[k];
            }
            pCTauT0[k]+=vectorP[k];
        }




        for (int k = 0; k < 4; k++) {
            for (int j = 0; j < 4; j++) {
                int node1ID = el.getNode()[k].getId()-1;
                int node2ID = el.getNode()[j].getId()-1;

                double valC = matrixC_dT[k][j];
                double valH = matrixHandBC[k][j];
                cMatrixGlobal[node1ID][node2ID] += valC;
                hMatrixGlobal[node1ID][node2ID] += valH;
            }
            pVector[el.getNode()[k].getId()-1] += pCTauT0[k];
        }
    }

    double * x = GausianElimination::solve(hMatrixGlobal,pVector,nodeCount);

    for (int k = 0; k < 16; k++)
        cout << x[k]<< '\t';

    for(double tau = simulation_step;tau<=simulation_time;tau+=simulation_step){

        for(int j = 0;j<nodeCount;j++)
            pVector[j] = 0;

            for (int i = 0; i < elementCount; i++) {
                Element el = *elements[i];
                double **matrixC_dT = MatrixC::count(*elements[i], specific_heat, density);
                double *vectorP = VectorP::count(*elements[i], alfa, ambient_temp);
                double *vectorT = TVector::count(*elements[i]);
                double *t0Vector = el.getTemps();


                // matrixHandBC = MatrixH + H_BC + C/dT

                for (int k = 0; k < 4; k++) {
                    for (int j = 0; j < 4; j++) {
                        matrixC_dT[k][j] /= tau;
                    }
                }


                double *pCTauT0 = new double[4];
                for (int k = 0; k < 4; k++) {
                    pCTauT0[k] = 0;
                    for (int j = 0; j < 4; j++) {
                        pCTauT0[k] += matrixC_dT[k][j] * t0Vector[k];
                    }
                    pCTauT0[k] += vectorP[k];
                }


                for (int k = 0; k < 4; k++) {
                    for (int j = 0; j < 4; j++) {
                        int node1ID = el.getNode()[k].getId() - 1;
                        int node2ID = el.getNode()[j].getId() - 1;
                        double valC = matrixC_dT[k][j];
                    }
                    el.getNode()->print();
                    int id = el.getNode()[k].getId()-1;
                    pVector[id] += pCTauT0[k];
                }
            }



//    cout << endl << endl;
//    for (int k = 0; k < 16; k++) {
//        for (int j = 0; j < 16; j++) {
//            cout << hMatrixGlobal[k][j] << ' ';
//        }
//        cout << endl;
//    }
//    cout << endl << endl;
//    for (int k = 0; k < 16; k++)
//        cout << pVector[k]<< '\t';

    cout << endl;
    double * x = GausianElimination::solve(hMatrixGlobal,pVector,nodeCount);

    for (int k = 0; k < 16; k++)
        cout << x[k]<< '\t';


    for (int k = 0; k < nodeCount; k++)
        nodes[k]->setT0(x[k]);

    //grid.print();

    }
    return 0;
}
