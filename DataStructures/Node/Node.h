//
// Created by Jakub on 25.10.2018.
//

#ifndef MES_NODE_H
#define MES_NODE_H


class Node {
    double x,y,t0;
    int id;
public:
    Node(int id,double x, double y, double t0);

    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);

    double getT0() const;

    void setT0(double t0);

    void print();
    void printPlus1();
};


#endif //MES_NODE_H
