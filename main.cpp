#include <iostream>
#include "Utils/ReadFile.h"
#include "DataStructures/Node/Node.h"
#include "DataStructures/Element/Element.h"
#include "DataStructures/Grid/Grid.h"
#include "Jacobian/Jacobian.h"


int main() {

    std::map<string,double> inputData = FS::read();
    double H = inputData.find("H")->second;
    double L = inputData.find("L")->second;
    int nH = static_cast<int>(inputData.find("nH")->second);
    int nL = static_cast<int>(inputData.find("nL")->second);
    double t0 = inputData.find("t0")->second;
    cout << "FILE INPUT DATA \n"
    << "H=" << H << endl
    << "L=" << L << endl
    << "nH=" << nH << endl
    << "nL=" << nL << endl
    << "t0=" << t0 << endl;

    Grid grid(nH,nL,H,L,t0);

    //grid.print();

    Jacobian *jacobian = new Jacobian(*grid.nodes[0],*grid.nodes[2],*grid.nodes[3],*grid.nodes[1]);



    return 0;
}