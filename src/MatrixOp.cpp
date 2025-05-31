#include "MatrixOp.h"
#include <iostream>

using namespace std;


MatrixOp::MatrixOp(int rows, int cols) : rows_(rows), cols_(cols) {
    data_ = new double[rows * cols]{};
}


MatrixOp::~MatrixOp(){
    delete[] data_;
}


void MatrixOp::set(int i, int j, double v){
    if(0 <= i && i < rows_ && 0 <= j && j < cols_){
        int k = i * cols_ + j;
        data_[k] = v;
    }
    else{
        throw std::out_of_range("Index exceeds the dimension of the matrix");
    }
}


double MatrixOp::get(int i, int j) const{
    if(0 <= i && i < rows_ && 0 <= j && j < cols_){
        int k = i * cols_ + j;
        return data_[k];
    }
    else{
        throw std::out_of_range("Index exceeds the dimension of the matrix");
    }
}


void MatrixOp::add(const MatrixOp *other, MatrixOp *result)const{
    if(other->cols_ == this->cols_ && other->rows_== this->rows_){
        for(int k = 0; k < rows_ * cols_; k++){
            result->data_[k] = this->data_[k] + other->data_[k];
        }
    }
    else{
        throw std::invalid_argument("Matrix don't have the same lenght");    
    }
}

void MatrixOp::apply(const MatrixOp* A, const MatrixOp* B, MatrixOp* out, OpFunc op) const{
    for(int k = 0; k < rows_ * cols_; k++){
        out->data_[k]=op(A->data_[k], B->data_[k]);
    }
}


void MatrixOp::forEachDiagonal(void (MatrixOp::*fn)(int i, int j) const) const{
    for(int i = 0; i < min(rows_, cols_); i++){
        (this->*fn)(i, i);
    }
}


void MatrixOp::printAt(int i, int j) const{
    cout << get(i, j) << endl;
}

MatrixOp MatrixOp::operator+(const MatrixOp &other) const{
    if(other.rows_ == this->rows_ && other.cols_ == this->cols_){
        MatrixOp result(rows_, cols_);
        for(int k = 0; k < rows_ * cols_; k++){
            result.data_[k] = this->data_[k] + other.data_[k];
        }
        return result;
    }
    throw std::invalid_argument("Matrix don't have the same lenght");
}

MatrixOp MatrixOp::operator-(const MatrixOp &other) const{
    if(other.rows_ == this->rows_ && other.cols_ == this->cols_){
        MatrixOp result(rows_, cols_);
        for(int k = 0; k < rows_ * cols_; k++){
            result.data_[k] = this->data_[k] - other.data_[k];
        }
        return result;
    }
    throw std::invalid_argument("Matrix don't have the same lenght");
}

double MatrixOp::determinant() const{
    if(this->rows_ == 2 && this->cols_ == 2){
        return get(0,0)*get(1,1)-get(0,1)*get(1, 0);    
    }
    else if(this->rows_ == 3 && this->cols_ == 3){
        double a = get(0,0), b = get(0,1), c = get(0,2);
        double d = get(1,0), e = get(1,1), f = get(1,2);
        double g = get(2,0), h = get(2,1), i = get(2,2);
        return a*e*i + b*f*g + c*d*h - c*e*g - b*d*i - a*f*h;
    }
    else{
        throw std::logic_error("Implementar para 2x2 o 3x3");
    }
}
