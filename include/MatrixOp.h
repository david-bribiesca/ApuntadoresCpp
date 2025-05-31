#ifndef MATRIXOP_H
#define MATRIXOP_H

#include <stdexcept>


class IMatrix {
public:
    virtual ~IMatrix() = default;
    virtual double determinant() const = 0;
};



class MatrixOp: public IMatrix{

private:
    int rows_, cols_;
    double *data_;

public:
    //A1
    MatrixOp(int rows, int cols);

    ~MatrixOp();

    int getRows() const{ return rows_;}
    int getCols() const{ return cols_;}
    const double* getData() const { return data_; }
    int getSize() const { return rows_ * cols_; }


    void set(int i, int j, double v);

    double get(int i, int j) const;
    //A2
    void add(const MatrixOp *other, MatrixOp *result)const;

    // Puntero a una funcion
    using OpFunc = double(*)(double, double);

    void apply(const MatrixOp* A, const MatrixOp* B, MatrixOp* out, OpFunc op) const;

    void forEachDiagonal(void (MatrixOp::*fn)(int i, int j) const) const;


    void printAt(int i, int j) const;


    MatrixOp operator+(const MatrixOp &other) const;
    MatrixOp operator-(const MatrixOp &other) const;

    // Implementacion de determinade desde IMatrix
    double determinant() const override;
};


template<typename T>
T maxValue(const T*arr, int n){
    if(n <= 0) throw std::invalid_argument("El arrego debe tener al menos dos elementos");
    T max = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] > max) max = arr[i];
    }
    return max;
}

#endif // MATRIXOP_H