//
// Created by Jakub on 25.10.2018.
//

#ifndef MES_GRID_H
#define MES_GRID_H


#include "../Node/Node.h"
#include "../Element/Element.h"

class Grid {
    int nH,nL,nodeCount,elementsCount;
    double H,L,t0;
public :Node ** nodes;
    Element ** elements;
public:
    Grid(int nH, int nL, double H, double L, double t0);

    void print();
    void printPlus1();

};


#endif //MES_GRID_H
