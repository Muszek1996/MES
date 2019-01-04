//
// Created by Jakub on 03.01.2019.
//

#include "HMatrix.h"
#include "../Utils/MatrixInitializer.h"
#include "../Jacobian/Derivatives/Derivatives.h"
#include "../Jacobian/JacobiMatrix/J.h"
#include <math.h>
#include <iostream>

double **HMatrix::count(Element el, double conductivity) {
    double val = 1/sqrt(3); /// 1/sqrt(3) value - integral point;
    double ksi[4] = {-val,val,val,-val};
    double eta[4] = {-val,-val,val,val};
    double *Xes = el.getXes();
    double *Yes = el.getYes();


     double **dNi_dX = new double*[4];
     double **dNi_dY = new double*[4];

    for(int pc = 0;pc<4;pc++){
            dNi_dX[pc] = Derivatives::dNi_dX(ksi[pc],eta[pc],Xes,Yes);
            dNi_dY[pc] = Derivatives::dNi_dY(ksi[pc],eta[pc],Xes,Yes);
        }


    double partOfMatrixH[4][4][4];
    double **matrixH = MatrixInitializer::init(4,4);

    for(int pc = 0;pc<4;pc++)
    for(int i =0;i<4;i++) {
        for (int j = 0; j < 4; j++) {
        partOfMatrixH[pc][i][j] = (dNi_dY[pc][i]*dNi_dY[pc][j]+dNi_dX[pc][i]*dNi_dX[pc][j])*J::determinant(ksi[pc],eta[pc],Xes,Yes)*conductivity;
        }
    }
    for(int pc = 0;pc<4;pc++)
        for(int i =0;i<4;i++)
            for (int j = 0; j < 4; j++)
        matrixH[i][j] += partOfMatrixH[pc][i][j];







    return matrixH;
}
