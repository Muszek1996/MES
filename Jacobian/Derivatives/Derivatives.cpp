//
// Created by Jakub on 03.01.2019.
//

#include "Derivatives.h"
#include "../../ShapeFunctions/shapeF.h"
#include "../JacobiMatrix/J.h"

double Derivatives::dX_dKsi(double eta, double *Xes) {

    double dN1_dKsi = shapeF::dN1_dKsi(eta);
    double dN2_dKsi = shapeF::dN2_dKsi(eta);
    double dN3_dKsi = shapeF::dN3_dKsi(eta);
    double dN4_dKsi = shapeF::dN4_dKsi(eta);
    double Xes1 = Xes[0];
    double Xes2 = Xes[1];
    double Xes3 = Xes[2];
    double Xes4 = Xes[3];
    double val1 = dN1_dKsi*Xes1;
    double val2 = dN2_dKsi*Xes2;
    double val3 = dN3_dKsi*Xes3;
    double val4 = dN4_dKsi*Xes4;
    double valfinal = val1+val2+val3+val4;

    return  shapeF::dN1_dKsi(eta)*Xes[0]+
            shapeF::dN2_dKsi(eta)*Xes[1]+
            shapeF::dN3_dKsi(eta)*Xes[2]+
            shapeF::dN4_dKsi(eta)*Xes[3];
}

double Derivatives::dX_dEta(double ksi, double *Xes) {
    return shapeF::dN1_dEta(ksi)*Xes[0]+
           shapeF::dN2_dEta(ksi)*Xes[1]+
           shapeF::dN3_dEta(ksi)*Xes[2]+
           shapeF::dN4_dEta(ksi)*Xes[3];
}

double Derivatives::dY_dKsi(double eta, double *Yes) {
    return shapeF::dN1_dKsi(eta)*Yes[0]+
           shapeF::dN2_dKsi(eta)*Yes[1]+
           shapeF::dN3_dKsi(eta)*Yes[2]+
           shapeF::dN4_dKsi(eta)*Yes[3];
}

double Derivatives::dY_dEta(double ksi, double *Yes) {
    return shapeF::dN1_dEta(ksi)*Yes[0]+
           shapeF::dN2_dEta(ksi)*Yes[1]+
           shapeF::dN3_dEta(ksi)*Yes[2]+
           shapeF::dN4_dEta(ksi)*Yes[3];
}

double *Derivatives::dNi_dX(double ksi, double eta, double *Xes, double *Yes) {
    double determinant = J::determinant(ksi,eta,Xes,Yes);
    double invDet = 1/determinant;
    double ** iM = J::inverseMatrix(ksi,eta,Xes,Yes);
    double *dNi_dX = new double[4];
    double *dNi_dKsi = shapeF::dNi_dKsi(eta);
    double *dNi_dEta = shapeF::dNi_dEta(ksi);
                                                                    //[0,0][0,1]
                                                                    //[1,0][1,1]
    for(int i = 0;i<4;i++){
        dNi_dX[i]= invDet * ((iM[0][0]*dNi_dKsi[i])+(iM[0][1]*dNi_dEta[i]));
    }
    return dNi_dX;
}

double *Derivatives::dNi_dY(double ksi, double eta, double *Xes, double *Yes) {
    double determinant = J::determinant(ksi,eta,Xes,Yes);
    double invDet = 1/determinant;
    double ** iM = J::inverseMatrix(ksi,eta,Xes,Yes);
    double *dNi_dY = new double[4];
    double *dNi_dKsi = shapeF::dNi_dKsi(eta);
    double *dNi_dEta = shapeF::dNi_dEta(ksi);
    //[0,0][0,1]
    //[1,0][1,1]
    for(int i = 0;i<4;i++){
        dNi_dY[i]= invDet * ((iM[1][0]*dNi_dKsi[i])+(iM[1][1]*dNi_dEta[i]));
    }
    return dNi_dY;
}
