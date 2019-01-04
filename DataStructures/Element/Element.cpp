//
// Created by Jakub on 25.10.2018.
//

#include "Element.h"
#include <iostream>
using namespace std;

Element::Element(int id,Node* a,Node* b,Node* c,Node* d,bool *bc) : id(id){
    node[0]= *a;
    node[1]= *b;
    node[2]= *c;
    node[3]= *d;
    for(int i =0;i<4;i++){
        this->bc[i]= bc[i];
    }

}

void Element::print() {
    cout << "Index:" << id << "\t[0]:" << node[0].getId() << "\t[1]:" << node[1].getId() << "\t[2]:" << node[2].getId() << "\t[3]:" << node[3].getId() << endl;
}

void Element::printPlus1() {
    cout << "Index:" << id+1 << "\t[0]:" << node[0].getId()+1 << "\t[1]:" << node[1].getId()+1 << "\t[2]:" << node[2].getId()+1 << "\t[3]:" << node[3].getId()+1 << endl;
}

double *Element::getXes() {
    double * Xes = new double[4];
    for(int i = 0;i<4;i++){
        Xes[i]= node[i].getX();
    }
    return Xes;
}

double *Element::getYes() {
    double * Yes = new double[4];
    for(int i = 0;i<4;i++){
        Yes[i]= node[i].getY();
    }
    return Yes;
}

const Node *Element::getNode() const {
    return node;
}

int Element::getId() const {
    return id;
}

double *Element::getTemps() {
    double * tempsVector = new double[4];
    for(int i = 0;i<4;i++){
        tempsVector[i] = node[i].getT0();
    }
    return tempsVector;
}
