#include "MatrixOp.h"
#include <iostream>
using namespace std;
int main(){
    cout << "A1: " << endl;
    MatrixOp mat(3, 3);
    for(int i = 0; i < mat.getRows(); i++) {
        for(int j = 0; j < mat.getCols(); j++) {
            mat.set(i, j, i + j + 1);
        }
    }
    for(int i = 0; i < mat.getRows(); i++) {
        for(int j = 0; j < mat.getCols(); j++) {
            cout << mat.get(i, j) << " ";
        }
        cout << endl;
    }
    cout << "MatrixOp test completed." << endl;
    return 0;
}