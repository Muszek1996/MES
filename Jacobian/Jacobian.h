//
// Created by Jakub on 15.11.2018.
//

#ifndef MES_JACOBIAN_H
#define MES_JACOBIAN_H
#include <math.h>
#include "../DataStructures/Node/Node.h"

class Jacobian {
    double val = 1/sqrt(3); /// 1/sqrt(3) value - integral point;
    double ksi[4] = {-val,val,val,-val};
    double eta[4] = {-val,-val,val,val};
    double N[4][4]; /// Funkcje kształtu N1,N2,N3,N4 dla 4 różnych punktów całkowania o współrzędnych ksi[i],eta[i] i = 0,1,2,3 (1 - 4);
    double Xp[4],Yp[4];
    double dN_dksi[4][4],dN_deta[4][4];
    double macierzJakobiego[4][4];
    double detJ[4];
    double macierzJakobiego2[4][4];
public:
    Jacobian(Node a,Node b,Node c, Node d);


};


#endif //MES_JACOBIAN_H
