#include "MatrixOp.h"
#include <iostream>

using namespace std;

double sub(double a, double b){
    return a - b;
}

double mul(double a, double b){
    return a * b;
}



int main() {
    cout << "A1: " << endl;
    MatrixOp mat(3, 3);
    for(int i = 0; i < mat.getRows(); i++) {
        for(int j = 0; j < mat.getCols(); j++) {
            mat.set(i, j, i + j);
        }
    }
    for(int i = 0; i < mat.getRows(); i++) {
        for(int j = 0; j < mat.getCols(); j++) {
            cout << mat.get(i, j) << " ";
        }
        cout << endl;
    }
    cout << "MatrixOp test completed." << endl;


    cout << "A2: " << endl;
    MatrixOp A(3, 3);
    MatrixOp B(3, 3);
    MatrixOp C(3, 3);
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


    cout << "A3: " << endl;
    MatrixOp D(3, 3);
    A.apply(&A, &B, &C, sub);
    A.apply(&A, &B, &D, mul);
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
    cout << "A4: " << endl;
    MatrixOp M(3, 3);
    for(int i = 0; i < A.getRows(); i++) {
        for(int j = 0; j < A.getCols(); j++) {
            M.set(i, j, i * M.getCols() + j);
        }
    }
    M.forEachDiagonal(&MatrixOp::printAt);
    cout << "B1: " << endl;
    // … inicializa A y B con valores …
    A.set(0, 0, 1);
    B.set(0, 1, 2);

    MatrixOp O = A + B;
    MatrixOp P = A - B;

    // Mostrar resultados
    std::cout << "C[0,0] = " << P.get(0,0) << "\n";
    std::cout << "D[1,1] = " << P.get(1,1) << "\n";

    cout << "B2: " << endl;
    MatrixOp M_(3,3);
    for(int i = 0; i < M_.getRows(); i++) {
        for(int j = 0; j < M_.getCols(); j++) {
            M_.set(i, j, i * M_.getCols() + j);
        }
    }
    double maxElem = maxValue<double>(M_.getData(), M_.getRows() * M_.getCols());
    std::cout << "Máximo elemento de M: " << maxElem << "\n";

    cout << "B3: " << endl;


    /*IMatrix* mat = new MatrixOp(2, 2);
    MatrixOp* realMat = dynamic_cast<MatrixOp*>(mat);
    realMat->set(0, 0, 1.0);
    realMat->set(0, 1, 2.0);
    realMat->set(1, 0, 3.0);
    realMat->set(1, 1, 4.0);
    delete mat; // Asegúrate de liberar la memoria

    No pude resolver el problema de la matriz dinámica.

    */

    return 0;
}