//
// Created by Jakub on 03.01.2019.
//

#ifndef MES_XY_DKSIETADERIVATIVES_H
#define MES_XY_DKSIETADERIVATIVES_H


class Derivatives {
public:
    static double dX_dKsi(double eta,double *Xes);
    static double dX_dEta(double ksi,double *Xes);
    static double dY_dKsi(double eta,double *Yes);
    static double dY_dEta(double ksi,double *Yes);
    static double* dNi_dX(double ksi, double eta,double *Xes, double *Yes);
    static double* dNi_dY(double ksi, double eta,double *Xes, double *Yes);

};


#endif //MES_XY_DKSIETADERIVATIVES_H
