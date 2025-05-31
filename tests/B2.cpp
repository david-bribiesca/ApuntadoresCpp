#include "MatrixOp.h"
#include <iostream>
using namespace std;
int main(){
    MatrixOp M_(3,3);
    for(int i = 0; i < M_.getRows(); i++) {
        for(int j = 0; j < M_.getCols(); j++) {
            M_.set(i, j, i * M_.getCols() + j);
        }
    }
    double maxElem = maxValue<double>(M_.getData(), M_.getRows() * M_.getCols());
    std::cout << "Máximo elemento de M: " << maxElem << "\n";
    return 0;
}