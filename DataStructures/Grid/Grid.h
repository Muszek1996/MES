//
// Created by Jakub on 25.10.2018.
//

#ifndef MES_GRID_H
#define MES_GRID_H


#include "../Node/Node.h"
#include "../Element/Element.h"

class Grid {
    Node * nodes;
    Element * elements;
public:
    Grid(Node *nodes, Element *elements);
};


#endif //MES_GRID_H
