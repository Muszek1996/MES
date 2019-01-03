//
// Created by Jakub on 25.10.2018.
//

#ifndef MES_GRID_H
#define MES_GRID_H


#include "../Node/Node.h"
#include "../Element/Element.h"

class Grid {
    Node ** nodes;
    Element ** elements;
    int nodeCount,elementsCount;
    int nH,nL;                  // nodes per Height and Length;
public:
    Grid(Node **nodes, Element **elements,int,int);
    void print();
    void printPlus1();

};


#endif //MES_GRID_H
