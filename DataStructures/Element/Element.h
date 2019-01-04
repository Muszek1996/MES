//
// Created by Jakub on 25.10.2018.
//

#ifndef MES_ELEMENT_H
#define MES_ELEMENT_H
#include "../Node/Node.h"

class Element {
  Node node[4];
  int id;
public:
    bool bc[4];
    double *getXes();
    double *getYes();
    Element(int id,Node* a,Node* b,Node* c,Node* d,bool* bc);
    void print();
    void printPlus1();
};


#endif //MES_ELEMENT_H
