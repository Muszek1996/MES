//
// Created by Jakub on 25.10.2018.
//

#include "Element.h"
#include <iostream>
using namespace std;

Element::Element(int id,int a,int b,int c,int d) : id(id){
    ID[0]= a;
    ID[1]= b;
    ID[2]= c;
    ID[3]= d;
}

void Element::print() {
    cout << "Index:" << id << "\t[0]:" << ID[0] << "\t[1]:" << ID[1] << "\t[2]:" << ID[2] << "\t[3]:" << ID[3] << endl;
}

void Element::printPlus1() {
    cout << "Index:" << id+1 << "\t[0]:" << ID[0]+1 << "\t[1]:" << ID[1]+1 << "\t[2]:" << ID[2]+1 << "\t[3]:" << ID[3]+1 << endl;
}
