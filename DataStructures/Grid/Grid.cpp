//
// Created by Jakub on 25.10.2018.
//

#include <iostream>
#include "Grid.h"


void Grid::print() {
    for(int i = 0;i<nodeCount;i++){
        nodes[i]->print();
    }
    for(int i = 0;i<elementsCount;i++){
        elements[i]->print();
    }

}

void Grid::printPlus1() {
    for(Node **a = &nodes[0];*a!= nullptr;++a){
        a[0]->printPlus1();
    }

    for(Element **a = &elements[0];*a!= nullptr;++a){
        a[0]->printPlus1();
    }
}



/*!
 *
 * @param nH -  count of nodes per Height
 * @param nL -  -       ||       - Width
 * @param H     Height
 * @param L     Width
 * @param t0    temperature
 */
Grid::Grid(int nH, int nL, double H, double L, double t0) : nH(nH), nL(nL), H(H), L(L), t0(t0) {
    this->nodeCount = static_cast<int>(nH*nL);
    this->elementsCount = static_cast<int>((nH-1)*(nL-1));
    double stepH = H/(nH-1);
    double stepL = L/(nL-1);
    int nLminus1 = nL-1;
    int nHminus1 = nH-1;

    this->nodes = new Node*[nodeCount];

    for(int i = 0;i<nL;i++)
        for(int j = 0;j<nH;j++){
            int itr = j+(i*(nH));
            nodes[itr] = new Node(itr,i*stepL,j*stepH,t0);
        }

    this->elements = new Element*[elementsCount];

    for(int i=0;i<nLminus1;i++)
        for(int j=0;j<nHminus1;j++){
            int itr = j+(i*(nHminus1));
            elements[itr] = new Element(itr,itr+i,itr+i+nH,itr+i+nH+1,itr+i+1);
        }
}
