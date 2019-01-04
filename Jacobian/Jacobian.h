//
// Created by Jakub on 15.11.2018.
//

#ifndef MES_JACOBIAN_H
#define MES_JACOBIAN_H
#include <math.h>
#include "../DataStructures/Node/Node.h"
#include "../DataStructures/Element/Element.h"

class Jacobian {
    double val = 1/sqrt(3); /// 1/sqrt(3) value - integral point;
    double ksi[4] = {-val,val,val,-val};


private:
    double eta[4] = {-val,-val,val,val};
    double *N[4]; /// Funkcje kształtu N1,N2,N3,N4 dla 4 różnych punktów całkowania o współrzędnych ksi[i],eta[i] i = 0,1,2,3 (1 - 4);
    double Xp[4],Yp[4];
    double dN_dksi[4][4],dN_deta[4][4];
    double macierzJakobiego[4][4];
    double detJ[4];
    double macierzJakobiego2[4][4];
    double dN_dx[4][4],dN_dy[4][4];
    double dN_dxT[4][4][4],dN_dyT[4][4][4];
    double dN_dxTConduvitiy[4][4][4];
    double conductivityK = 30;
    double MacierzH[4][4];

public:
    Jacobian(Node a,Node b,Node c, Node d);

    Jacobian(Element el);


};


#endif //MES_JACOBIAN_H
