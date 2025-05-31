#include "MatrixOp.h"
#include <iostream>
using namespace std;

int main(){
    MatrixOp A(3, 3);
    MatrixOp B(3, 3);
    MatrixOp C(3, 4);
    for(int i = 0; i < A.getRows(); i++) {
        for(int j = 0; j < A.getCols(); j++) {
            A.set(i, j, i + j + 1);
            B.set(i, j, (i + j + 1) * 2);
        }
    }
    A.add(&B, &C);
    for(int i = 0; i < C.getRows(); i++) {
        for(int j = 0; j < C.getCols(); j++) {
            cout << C.get(i, j) << " ";
        }
        cout << endl;
    }
    return 0;
}