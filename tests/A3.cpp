#include "MatrixOp.h"
#include <iostream>
using namespace std;


double div(double a, double b){
    return a / b;
}

double mul(double a, double b){
    return a * b;
}



int main(){
    MatrixOp A(3, 3);
    MatrixOp B(3, 3);
    MatrixOp C(3, 4);
    MatrixOp D(3, 3);
    for(int i = 0; i < A.getRows(); i++) {
        for(int j = 0; j < A.getCols(); j++) {
            A.set(i, j, i + j + 1);
            B.set(i, j, (i + j + 1) * 2);
            
        }
    }

    A.apply(&A, &B, &C, div);
    A.apply(&A, &B, &D, div);
    cout << "C: " << endl;
    for(int i = 0; i < C.getRows(); i++) {
        for(int j = 0; j < C.getCols(); j++) {
            cout << C.get(i, j) << " ";
        }
        cout << endl;
    }
    cout << "D: " << endl;
    for(int i = 0; i < D.getRows(); i++) {
        for(int j = 0; j < D.getCols(); j++) {
            cout << D.get(i, j) << " ";
        }
        cout << endl;
    }
}