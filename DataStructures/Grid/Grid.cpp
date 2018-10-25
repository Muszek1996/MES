//
// Created by Jakub on 25.10.2018.
//

#include "Grid.h"

Grid::Grid(Node **nodes, Element **elements) : nodes(nodes), elements(elements) {

}

void Grid::print() {
    for(Node **a = &nodes[0];*a!= nullptr;++a){
        a[0]->print();
    }
    for(Element **a = &elements[0];*a!= nullptr;++a){
        a[0]->print();
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
