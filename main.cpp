#include <iostream>
#include "Utils/ReadFile.h"


int main() {

    std::map<string,double> inputData = FS::read();
    double H = inputData.find("H")->second;
    double L = inputData.find("L")->second;
    double nH = inputData.find("nH")->second;
    double nL = inputData.find("nL")->second;
    double t0 = inputData.find("t0")->second;
    cout << "FILE INPUT DATA \n"
    << "H=" << H << endl
    << "L=" << L << endl
    << "nH=" << nH << endl
    << "nL=" << nL << endl
    << "t0=" << t0 << endl;







    return 0;
}