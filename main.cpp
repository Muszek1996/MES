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


int main() {

    std::map<string,double> inputData = FS::read();
    double H = inputData.find("H")->second;
    double L = inputData.find("L")->second;
    int nH = static_cast<int>(inputData.find("nH")->second);
    int nL = static_cast<int>(inputData.find("nL")->second);
    double t0 = inputData.find("t0")->second;
    cout << "FILE INPUT DATA \n"
    << "H=" << H << endl
    << "L=" << L << endl
    << "nH=" << nH << endl
    << "nL=" << nL << endl
    << "t0=" << t0 << endl;

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

    grid.print();

   // Jacobian jcb = Jacobian(Node(0,0,0,20),Node(0,0.25,0,20),Node(0,0.25,0.25,20),Node(0,0,0.25,20));


    Element *el = new Element(0,new Node(0,0,0,20),new Node(0,0.025,0,20),new Node(0,0.025,0.025,20),new Node(0,0,0.025,20),new bool[4]{1,0,0,0});
    double ** matrixH = HMatrix::count(*el,30);
    double ** matrixC = MatrixC::count(*el,700,7800);


   double**matrixH_BC =  BoundC::count(*el,25);

    for(int i =0;i<4;i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << matrixH_BC[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    double *vectorP = VectorP::count(*el,25,t0);
    double vectorrP[4] = {vectorP[0],vectorP[1],vectorP[2],vectorP[3]};
    return 0;
}