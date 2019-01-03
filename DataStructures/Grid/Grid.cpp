//
// Created by Jakub on 25.10.2018.
//

#include <iostream>
#include "Grid.h"

Grid::Grid(Node **nodes, Element **elements,int nH,int nL) : nodes(nodes), elements(elements), nH(nH),nL(nL) {
    this->nodeCount = nH*nL;
    this->elementsCount = (nH-1)*(nL-1);
}

void Grid::print() {
    
    
    for(int iH=nH;iH>0;iH--) {
        for (int iL = 1; iL <= nL; iL++) {
            this->nodes[(iL * iH) - 1]->print();
        }
        std::cout << std::endl;
    }


}

void Grid::printPlus1() {

}
