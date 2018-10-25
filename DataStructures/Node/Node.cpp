//
// Created by Jakub on 25.10.2018.
//

#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(int id,double x, double y, double z) : id(id), x(x), y(y), t0(z) {

}

double Node::getX() const {
    return x;
}

void Node::setX(double x) {
    Node::x = x;
}

double Node::getY() const {
    return y;
}

void Node::setY(double y) {
    Node::y = y;
}

double Node::getT0() const {
    return t0;
}

void Node::setT0(double t0) {
    Node::t0 = t0;
}

void Node::print() {
    cout << "Index: "<< id << "\t(" << x << "\t,\t"<< y << ")\t\tt0:" << t0 << endl;
}

void Node::printPlus1() {
    cout << "Index: "<< id+1 << "\t(" << x << "\t,\t"<< y << ")\t\tt0:" << t0 << endl;
}
