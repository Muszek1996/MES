#include <iostream>
#include "Utils/ReadFile.h"
#include "DataStructures/Node/Node.h"
#include "DataStructures/Element/Element.h"
#include "DataStructures/Grid/Grid.h"


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

    int nodeCount = static_cast<int>(nH*nL);
    int elementCount = static_cast<int>((nH-1)*(nL-1));
    double stepH = H/(nH-1);
    double stepL = L/(nL-1);
    int nLminus1 = nL-1;
    int nHminus1 = nH-1;



    Node** nodes = new Node*[nodeCount];


    for(int i = 0;i<nL;i++)
    for(int j = 0;j<nH;j++){
        int itr = j+(i*(nH));
        nodes[itr] = new Node(itr+1,i*stepL,j*stepH,t0);
    }


    Element ** elements = new Element*[elementCount];

    for(int i=0;i<nLminus1;i++)
    for(int j=0;j<nHminus1;j++){
        int itr = j+(i*(nHminus1));
        elements[itr] = new Element(itr,itr+i,itr+i+nH,itr+i+nH+1,itr+i+1);
    }

    Grid grid(nodes,elements,nH,nL);

    grid.print();



    return 0;
}