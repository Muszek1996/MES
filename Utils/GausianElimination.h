//
// Created by Jakub on 04.01.2019.
//

#ifndef MES_GAUSIANELIMINATION_H
#define MES_GAUSIANELIMINATION_H
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>
#include "MatrixInitializer.h"

using namespace std;

namespace GausianElimination {

    void print(double **A,int n) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n+1; j++) {
                cout << A[i][j] << "\t";
                if (j == n-1) {
                    cout << "| ";
                }
            }
            cout << "\n";
        }
        cout << endl;
    }

    double *solve(double **Mat,double *P,int n) {
        double ** A = MatrixInitializer::init(n,n+1);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n+1;j++){
                if(j<n)
                A[i][j] = Mat[i][j];
                else
                A[i][j] = P[i];
            }
        }


        for (int i=0; i<n; i++) {
            // Search for maximum in this column
            double maxEl = abs(A[i][i]);
            int maxRow = i;
            for (int k=i+1; k<n; k++) {
                if (abs(A[k][i]) > maxEl) {
                    maxEl = abs(A[k][i]);
                    maxRow = k;
                }
            }

            // Swap maximum row with current row (column by column)
            for (int k=i; k<n+1;k++) {
                double tmp = A[maxRow][k];
                A[maxRow][k] = A[i][k];
                A[i][k] = tmp;
            }

            // Make all rows below this one 0 in current column
            for (int k=i+1; k<n; k++) {
                double c = -A[k][i]/A[i][i];
                for (int j=i; j<n+1; j++) {
                    if (i==j) {
                        A[k][j] = 0;
                    } else {
                        A[k][j] += c * A[i][j];
                    }
                }
            }
        }

        // Solve equation Ax=b for an upper triangular matrix A
        double *x = new double[n];
        for (int i=n-1; i>=0; i--) {
            x[i] = A[i][n]/A[i][i];
            for (int k=i-1;k>=0; k--) {
                A[k][n] -= A[k][i] * x[i];
            }
        }
        return x;
    }


}

#endif //MES_GAUSIANELIMINATION_H
