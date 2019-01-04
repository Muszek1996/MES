//
// Created by Jakub on 15.11.2018.
//

#include <iostream>
#include "Jacobian.h"
#include "../ShapeFunctions/shapeF.h"
#include <math.h>
#include "../DataStructures/Node/Node.h"
#include "../DataStructures/Element/Element.h"
using namespace std;



Jacobian::Jacobian(Node a,Node b,Node c, Node d) {

    double x[4] = {a.getX(),b.getX(),c.getX(),d.getX()};
    double y[4] = {a.getY(),b.getY(),c.getY(),d.getY()};

    cout << "\t"<< "x" << "\t" << "y"<< endl;
    for(int i =0;i<4;i++){
        cout << i+1 << "\t" << x[i] << "\t" << y[i]<< endl;
    }cout << endl;


    for(int pc = 0;pc<4; pc++){
        N[pc] = shapeF::Ni(ksi[pc], eta[pc]);
    }

    for(int i =0;i<4;i++){
        for(int j =0;j<4;j++){
            std::cout << N[i][j] << "\t";
        }
        std::cout << std::endl;
    }cout << endl;

    cout  << "Xp" << "\t" << "Yp" << std::endl;
    for(int i =0;i<4;i++) { /// Interpolacja współrzędnej (suma Ni * Xi );
        Xp[i] = 0;
        Yp[i] = 0;
        for (int j = 0; j < 4; j++) {
            Xp[i]+= N[i][j]*x[j];
            Yp[i]+= N[i][j]*y[j];
        }
        std::cout << Xp[i] << "\t" << Yp[i]<< std::endl;
    }std::cout << endl << endl;


    for(int i = 0;i<4;i++){ /// Pochodne funkcji kształtu względem eta i ksi
        dN_dksi[0][i] = -0.25*(1-eta[i]);
        dN_dksi[1][i] = 0.25*(1-eta[i]);
        dN_dksi[2][i] = 0.25*(1+eta[i]);
        dN_dksi[3][i] = -0.25*(1+eta[i]);
                                                dN_deta[0][i] = -0.25*(1-ksi[i]);
                                                dN_deta[1][i] = -0.25*(1+ksi[i]);
                                                dN_deta[2][i] = 0.25*(1+ksi[i]);
                                                dN_deta[3][i] = 0.25*(1-ksi[i]);
    }

    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            cout << dN_dksi[i][j] << "\t";
        }cout << endl;
    }cout << endl;

    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            cout << dN_deta[i][j] << "\t";
        }cout << endl;
    }cout << endl;

        for (int j = 0; j < 4; j++) {
            macierzJakobiego[0][j] = 0;
            macierzJakobiego[1][j] = 0;
            macierzJakobiego[2][j] = 0;
            macierzJakobiego[3][j] = 0;
            for(int k=0;k<4;k++){
                macierzJakobiego[0][j]+= x[k]*dN_dksi[k][j];
                macierzJakobiego[1][j]+= y[k]*dN_dksi[k][j];
                macierzJakobiego[2][j]+= x[k]*dN_deta[k][j];
                macierzJakobiego[3][j]+= y[k]*dN_deta[k][j];
            }
        }

    for(int i = 0;i<4;i++) {
        for (int j = 0; j < 4; j++) {
              cout <<  macierzJakobiego[i][j] << "\t";
        }cout << endl;
    }cout << endl;

    for(int i=0;i<4;i++){
        detJ[i] = macierzJakobiego[0][i]*macierzJakobiego[3][i]-macierzJakobiego[1][i]*macierzJakobiego[2][i];
        cout << detJ[i] << "\t";
    }cout << endl << endl;

        for (int j = 0; j < 4; j++) {
        macierzJakobiego2[0][j] = macierzJakobiego[3][j]/detJ[j];
        macierzJakobiego2[1][j] = macierzJakobiego[1][j]/detJ[j];
        macierzJakobiego2[2][j] = macierzJakobiego[2][j]/detJ[j];
        macierzJakobiego2[3][j] = macierzJakobiego[0][j]/detJ[j];
        }

    for(int i = 0;i<4;i++) {
        for (int j = 0; j < 4; j++) {
        cout << macierzJakobiego2[i][j] << "\t";
        }cout << endl;
    }cout << endl;

    for(int i = 0;i<4;i++) {
        for (int j = 0; j < 4; j++) {
        dN_dx[i][j] = dN_dksi[i][j]*macierzJakobiego2[0][i] + dN_deta[i][j]*macierzJakobiego2[1][i];
        dN_dy[i][j] = dN_dksi[i][j]*macierzJakobiego2[2][i] + dN_deta[i][j]*macierzJakobiego2[3][i];
        }
    }

    for(int i = 0;i<4;i++) {
        for (int j = 0; j < 4; j++) {
            cout << dN_dx[j][i] << "\t\t"; //zamienione indeksy do wypisania
        }cout << endl;
    }cout << endl;

    for(int i = 0;i<4;i++) {
        for (int j = 0; j < 4; j++) {
            cout << dN_dy[j][i] << "\t\t";//zamienione indeksy do wypisania
        }cout << endl;
    }cout << endl;

    cout << "1 2 3 4pc dx" << endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                dN_dxT[i][j][k] = dN_dx[j][i]*dN_dx[k][i]*detJ[i];
                dN_dyT[i][j][k] = dN_dy[j][i]*dN_dy[k][i]*detJ[i];
                cout << dN_dxT[i][j][k] << "\t";
            }cout << endl;
        }cout << endl;
    }

    cout << "1 2 3 4pc dy" << endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                cout << dN_dyT[i][j][k] << "\t";
            }cout << endl;
        }cout << endl;
    }

    cout << "1 2 3 4pc conductivity" << endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                dN_dxTConduvitiy[i][j][k] = (dN_dxT[i][j][k]+dN_dyT[i][j][k])*conductivityK;
                cout <<  dN_dxTConduvitiy[i][j][k] << "\t";
            }cout << endl;
        }cout << endl;
    }


    cout << "MACIERZ H" << endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            MacierzH[i][j]=0;
            for(int k=0;k<4;k++){
               MacierzH[i][j] += dN_dxTConduvitiy[k][j][i];

            }cout << MacierzH[i][j]<< "\t";
        }cout << endl;
    }


}

Jacobian::Jacobian(Element el){



}
