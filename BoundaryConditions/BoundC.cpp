//
// Created by Jakub on 03.01.2019.
//

#include "BoundC.h"
#include "../ShapeFunctions/shapeF.h"
#include "../Jacobian/JacobiMatrix/J.h"
#include "../Utils/MatrixInitializer.h"
#include <math.h>
#include <iostream>

double **BoundC::count(Element el, double alfa) {
    double val = 1/sqrt(3); /// 1/sqrt(3) value - integral point;
    double ksi[8] = {-val,val,1,1,val,-val,-1,-1};
    double eta[8] = {-1,-1,-val,val,1,1,val,-val};
    double *Xes = el.getXes();
    double *Yes = el.getYes();

    bool bc[4] = {el.bc[0],el.bc[1],el.bc[2],el.bc[3]};
    double length[4];

    length[0] = abs(Xes[0] - Xes[1]);
    length[1] = abs(Yes[1] - Yes[2]);
    length[2] = abs(Xes[2] - Xes[3]);
    length[3] = abs(Yes[3] - Yes[0]);



    double ** pow1 = new double*[4];
    double ** pow2 = new double*[4];
    double ** pow3 = new double*[4];
    double ** pow4 = new double*[4];

    for(int pc = 0;pc<2;pc++){
        pow1[pc] = shapeF::Ni(ksi[pc],eta[pc]);
        pow2[pc] = shapeF::Ni(ksi[pc+2],eta[pc+2]);
        pow3[pc] = shapeF::Ni(ksi[pc+4],eta[pc+4]);
        pow4[pc] = shapeF::Ni(ksi[pc+6],eta[pc+6]);
    }

    double partOfMatrixH_BC[4][4][4];

//    0,788675135	0,211324865 	0	    0
//    0,211324865	0,788675135	    0	    0

    double **matrixH_BC = MatrixInitializer::init(4,4);

    for(int i =0;i<4;i++) {
        for (int j = 0; j < 4; j++) {
            matrixH_BC[i][j] = 0;
            double val1 = (pow1[0][j]*pow1[0][i]+pow1[1][j]*pow1[1][i])*alfa*(length[0]/2);
            double val2 = (pow2[0][j]*pow2[0][i]+pow2[1][j]*pow2[1][i])*alfa*(length[1]/2);
            double val3 = (pow3[0][j]*pow3[0][i]+pow3[1][j]*pow3[1][i])*alfa*(length[2]/2);
            double val4 = (pow4[0][j]*pow4[0][i]+pow4[1][j]*pow4[1][i])*alfa*(length[3]/2);
            val1*=(int)bc[0];
            val2*=(int)bc[1];
            val3*=(int)bc[2];
            val4*=(int)bc[3];


            matrixH_BC[i][j] += val1+val2+val3+val4;

            partOfMatrixH_BC[0][i][j] = (pow1[0][j]*pow1[0][i]+pow1[1][j]*pow1[1][i])*alfa*(length[0]/2);
            partOfMatrixH_BC[1][i][j] = (pow2[0][j]*pow2[0][i]+pow2[1][j]*pow2[1][i])*alfa*(length[1]/2);
            partOfMatrixH_BC[2][i][j] = (pow3[0][j]*pow3[0][i]+pow3[1][j]*pow3[1][i])*alfa*(length[2]/2);
            partOfMatrixH_BC[3][i][j] = (pow4[0][j]*pow4[0][i]+pow4[1][j]*pow4[1][i])*alfa*(length[3]/2);
        }
    }





    return matrixH_BC;
}
