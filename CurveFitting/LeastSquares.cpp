/* 
 * File:   LeastSquares.cpp
 * Author: lucas
 * 
 * Created on 22 de Junho de 2017, 01:05
 */

#include "LeastSquares.h"
#include "MatrixCommons.h"
#include <cmath>
#include <iostream>

LeastSquares::LeastSquares() {
}

LeastSquares::LeastSquares(const LeastSquares& orig) {
}

void LeastSquares::fillVandermonde(double** m, int x, int y, double * x) {
    for(int i = 0; i < x; i+){
        for(int j = y-1; j >= 0; j--){
            m[i][j] = pow(x[i], j);
        }
    }
}

void LeastSquares::mmq(double * x, double * y, int size, bool showSteps) {
    double ** result; // Vt * v
    double ** resultY; // Vt * y
    double ** finalResult; // (Vt * v) * (Vt * y)
    double ** yColumn;
    double ** vandermonde;
    double ** vandermondeT;
    
    result = new double[size];
    resultY = new double[size];
    yColumn = new double[size];
    vandermonde = new double[size];
    vandermondeT = new double[size];
    
    
    for(int i = 0; i < size; i++){
        result[i] = new double[size];
        resultY[i] = new double[1];
        yColumn[i] = new double[1];
        yColumn[i][0] = y[i];
        vandermonde[i] = new double[size];
        vandermondeT[i] = new double[size];
        
    }
    this->fillVandermonde(vandermonde, size, size, x);
    this->fillVandermonde(vandermondeT, size, size, x);
    MatrixCommons::transpose(vandermondeT, size, size);
    
    MatrixCommons::multiply(vandermondeT, size, size, 
                            vandermonde, size, size, 
                            result, size,size );
    
    MatrixCommons::inverse(result, size, size);
    
    MatrixCommons::multiply(vandermondeT, size, size, 
                            y, size, size/size, 
                            resultY, size,size/size );
    
    MatrixCommons::multiply(result, size, size, 
                            resultY, size, size/size, 
                            finalResult, size,size/size );
    
    
    std::cout << "y = " << finalResult[0];
    for(int i = 1; i < size; i+){
        std::cout << " + " << finalResult[i] << " * x^" << i;
    }
}

void LeastSquares::continuo(double* x, double* y, int size) {

}

void LeastSquares::discreto(double* x, double* y, int size) {

}

