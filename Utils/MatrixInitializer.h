//
// Created by Jakub on 03.01.2019.
//

#ifndef MES_MATRIXINITIALIZER_H
#define MES_MATRIXINITIALIZER_H

namespace MatrixInitializer{
    static double ** init(int x,int y){
        auto ** matrix = new double*[x];
        for(int i = 0;i<y;i++){
            matrix[i] = new double[4];
        }
        return matrix;
    }

}


#endif //MES_MATRIXINITIALIZER_H
