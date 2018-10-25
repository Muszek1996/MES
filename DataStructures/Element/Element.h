//
// Created by Jakub on 25.10.2018.
//

#ifndef MES_ELEMENT_H
#define MES_ELEMENT_H


class Element {
  int ID[4];
  int id;
public:
    Element(int id,int a,int b,int c,int d);
    void print();
    void printPlus1();
};


#endif //MES_ELEMENT_H
