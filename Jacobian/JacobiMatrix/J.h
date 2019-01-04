//
// Created by Jakub on 03.01.2019.
//

#ifndef MES_J_H
#define MES_J_H


class J {
public:
    static double ** inverseMatrix(double ksi,double eta,double *Xes,double*Yes);
    static double ** matrix(double ksi,double eta,double *Xes,double*Yes);
    static double determinant(double ksi,double eta,double *Xes,double*Yes);
};


#endif //MES_J_H
