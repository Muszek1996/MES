//
// Created by Jakub on 25.10.2018.
//

#ifndef MES_READFILE_H
#define MES_READFILE_H
#include <iostream>
#include <fstream>
#include <map>
#include <cmath>

using namespace std;

namespace FS{
    std::map<string,double> read(){
        ifstream myfile;
        myfile.open ("../dane.txt", ios::in);
        string buffer;

        std::map<string,double> data = std::map<string,double>();
        if (myfile.is_open())
        {
            while ( getline (myfile,buffer) )
            {
                string a = buffer.substr(0,(buffer.find('=')));
                string be = buffer.substr((buffer.find('=')+1),buffer.find("\n"));
                double b =  stod(be.c_str());
                //cout << a << '=' << b << endl;
                data.insert(std::pair(a,b));
            }
            myfile.close();
        }else{
            cout << "ERROR WHILE OPENING A FILE" << endl;
        }


        myfile.close();
        return data;
    }








}











#endif //MES_READFILE_H
