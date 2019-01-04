//
// Created by Jakub on 03.01.2019.
//

#ifndef MES_SHAPEFUNCTION_H
#define MES_SHAPEFUNCTION_H


class shapeF {
public:
    static double * Ni(double ksi, double eta);
    static double N1(double ksi, double eta);
    static double N2(double ksi, double eta);
    static double N3(double ksi, double eta);
    static double N4(double ksi, double eta);
    static double dN1_dKsi(double eta);
    static double dN2_dKsi(double eta);
    static double dN3_dKsi(double eta);
    static double dN4_dKsi(double eta);
    static double dN1_dEta(double ksi);
    static double dN2_dEta(double ksi);
    static double dN3_dEta(double ksi);
    static double dN4_dEta(double ksi);
    static double * dNi_dKsi(double eta);
    static double * dNi_dEta(double ksi);
    shapeF();
};


#endif //MES_SHAPEFUNCTION_H
