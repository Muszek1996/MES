//
// Created by Jakub on 15.11.2018.
//

#include <iostream>
#include "Jacobian.h"
using namespace std;


/*!
* Definicja 4 funkcji kształtu w każdym z 4 punktów całkowania;
* 𝑁1=0.25(1−𝜀)(1−𝜇)
* 𝑁2=0.25(1+𝜀)(1−𝜇)
* 𝑁3=0.25(1+𝜀)(1+𝜇)
* 𝑁4=0.25(1−𝜀)(1+𝜇)
*/
Jacobian::Jacobian(Node a,Node b,Node c, Node d) {
    double x[4] = {a.getX(),b.getX(),c.getX(),d.getX()};
    double y[4] = {a.getY(),b.getY(),c.getY(),d.getY()};

    cout << "\t"<< "x" << "\t" << "y"<< endl;
    for(int i =0;i<4;i++){
        cout << i+1 << "\t" << x[i] << "\t" << y[i]<< endl;
    }cout << endl;


    for(int punktCalkowania = 0;punktCalkowania<4; punktCalkowania++){
        N[punktCalkowania][0] = 0.25*(1-ksi[punktCalkowania])*(1-eta[punktCalkowania]);
        N[punktCalkowania][1] = 0.25*(1+ksi[punktCalkowania])*(1-eta[punktCalkowania]);
        N[punktCalkowania][2] = 0.25*(1+ksi[punktCalkowania])*(1+eta[punktCalkowania]);
        N[punktCalkowania][3] = 0.25*(1-ksi[punktCalkowania])*(1+eta[punktCalkowania]);
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


    for(int i = 0;i<4;i++){
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


}
