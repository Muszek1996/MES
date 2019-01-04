//
// Created by Jakub on 03.01.2019.
//

#include "J.h"
#include "../Derivatives/Derivatives.h"

//[0,0][0,1]
//[1,0][1,1]

double **J::inverseMatrix(double ksi, double eta, double *Xes, double *Yes) {
    double ** matrix = new double*[2];
    for(int i = 0;i<2;i++) matrix[i] = new double[2];

    matrix[0][0] =  Derivatives::dY_dEta(ksi,Yes);           matrix[0][1] =  -Derivatives::dY_dKsi(eta,Yes);
    matrix[1][0] =  -Derivatives::dX_dEta(ksi,Xes);          matrix[1][1] =  Derivatives::dX_dKsi(eta,Xes);

    return matrix;
}

double **J::matrix(double ksi, double eta, double *Xes, double *Yes) {
    double ** matrix = new double*[2];
    for(int i = 0;i<2;i++) matrix[i] = new double[2];

    matrix[0][0] =  Derivatives::dX_dKsi(eta,Xes);          matrix[0][1] =  Derivatives::dY_dKsi(eta,Yes);
    matrix[1][0] =  Derivatives::dX_dEta(ksi,Xes);          matrix[1][1] =  Derivatives::dY_dEta(ksi,Yes);

    return matrix;
}

double J::determinant(double ksi, double eta, double *Xes, double *Yes) {
    double **m = J::matrix(ksi, eta,Xes,Yes);
    //[0,0][0,1]
    //[1,0][1,1]
    double determinant = (m[0][0]*m[1][1])-(m[0][1]*m[1][0]);
    return determinant;
}

