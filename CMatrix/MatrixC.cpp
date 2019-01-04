//
// Created by Jakub on 03.01.2019.
//

#include "MatrixC.h"
#include "../ShapeFunctions/shapeF.h"
#include "../Utils/MatrixInitializer.h"
#include "../Jacobian/JacobiMatrix/J.h"
#include <math.h>
#include <iostream>

double **MatrixC::count(Element el, double c, double ro) {
    double val = 1/sqrt(3); /// 1/sqrt(3) value - integral point;
    double ksi[4] = {-val,val,val,-val};
    double eta[4] = {-val,-val,val,val};
    double *Xes = el.getXes();
    double *Yes = el.getYes();

    double **dNi__pcI;
    for(int pc = 0;pc<4;pc++){
        dNi__pcI[pc] = shapeF::Ni(ksi[pc],eta[pc]);
    }



    double partOfMatrixC[4][4][4];

    for(int pc = 0;pc<4;pc++)
        for(int i =0;i<4;i++) {
            for (int j = 0; j < 4; j++) {
                partOfMatrixC[pc][i][j] = dNi__pcI[pc][i]*dNi__pcI[pc][j]*J::determinant(ksi[pc],eta[pc],Xes,Yes)*ro*c;
            }
        }
    double **matrixC = MatrixInitializer::init(4,4);

    for(int pc = 0;pc<4;pc++)
        for(int i =0;i<4;i++)
            for (int j = 0; j < 4; j++)
                matrixC[i][j] += partOfMatrixC[pc][i][j];




    return matrixC;
}
