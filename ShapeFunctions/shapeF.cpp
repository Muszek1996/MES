//
// Created by Jakub on 03.01.2019.
//

#include "shapeF.h"


shapeF::shapeF() {}

double *shapeF::Ni(double ksi, double eta) {
    double *N = new double[4];
        N[0] = N1(ksi,eta);
        N[1] = N2(ksi,eta);
        N[2] = N3(ksi,eta);
        N[3] = N4(ksi,eta);
    return N;
}
double shapeF::N1(double ksi, double eta) {
    return 0.25*(1-ksi)*(1-eta);
}

double shapeF::N2(double ksi, double eta) {
    return 0.25*(1+ksi)*(1-eta);
}

double shapeF::N3(double ksi, double eta) {
    return 0.25*(1+ksi)*(1+eta);
}

double shapeF::N4(double ksi, double eta) {
    return 0.25*(1-ksi)*(1+eta);
}

double *shapeF::dNi_dKsi(double eta) {
    double *dNi_dKsi = new double[4];
    dNi_dKsi[0] = dN1_dKsi(eta);
    dNi_dKsi[1] = dN2_dKsi(eta);
    dNi_dKsi[2] = dN3_dKsi(eta);
    dNi_dKsi[3] = dN4_dKsi(eta);
    return dNi_dKsi;

}double *shapeF::dNi_dEta(double ksi) {
    double *dNi_dEta = new double[4];
    dNi_dEta[0] = dN1_dEta(ksi);
    dNi_dEta[1] = dN2_dEta(ksi);
    dNi_dEta[2] = dN3_dEta(ksi);
    dNi_dEta[3] = dN4_dEta(ksi);
    return dNi_dEta;
}

double shapeF::dN1_dKsi(double eta) {
   return -0.25*(1-eta);
}

double shapeF::dN2_dKsi(double eta) {
    return 0.25*(1-eta);
}

double shapeF::dN3_dKsi(double eta) {
    return 0.25*(1+eta);
}

double shapeF::dN4_dKsi(double eta) {
    return -0.25*(1+eta);
}

double shapeF::dN1_dEta(double ksi) {
    return -0.25*(1-ksi);
}

double shapeF::dN2_dEta(double ksi) {
    return -0.25*(1+ksi);
}

double shapeF::dN3_dEta(double ksi) {
    return 0.25*(1+ksi);
}

double shapeF::dN4_dEta(double ksi) {
    return 0.25*(1-ksi);
}