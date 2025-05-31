#include "MatrixOp.h"
#include <iostream>
using namespace std;
int main(){
    MatrixOp A(2,2), B(2,2);
    // … inicializa A y B con valores …
    A.set(0, 0, 1);
    B.set(0, 1, 2);

    MatrixOp C = A + B;
    MatrixOp D = A - B;

    // Mostrar resultados
    std::cout << "C[0,0] = " << C.get(0,0) << "\n";
    std::cout << "D[1,1] = " << D.get(1,1) << "\n";
}