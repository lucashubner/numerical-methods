/* 
 * File:   LinearInterpolation.cpp
 * Author: lucas
 * 
 * Created on 8 de Junho de 2017, 15:26
 */

#include "LinearInterpolation.h"
#include "Gauss.h"
#include "MatrixCommons.h"
#include <iostream>
LinearInterpolation::LinearInterpolation() {
}

LinearInterpolation::LinearInterpolation(const LinearInterpolation& orig) {
}

LinearInterpolation::~LinearInterpolation() {
}

double LinearInterpolation::doCalculation(double* x, double* y, int PX1, int PX2, double PI, int size, bool showSteps = false) {
    double **m;
    double result[2];

    // Verifica se os pontos escolhidos estão no invervalo dos vetores 
    
    // Cria matriz 2x3 para resolver sistema linear
    m = new double*[2];
    for(int i = 0; i < 2; i++){
        m[i] = new double[3];
    }
  
    
    m[0][0] = x[PX1]; m[0][1] = 1; m[0][2] = y[PX1];
    m[1][0] = x[PX2]; m[1][1] = 1; m[1][2] = y[PX2];
    
    if(showSteps){
        MatrixCommons::print(m,2,3);
        std::cout << "Aplicando Gauss " << std::endl;
    }
    
    Gauss::doCalculation(m, 2, 3,result,showSteps);
   
    if(showSteps){
        std::cout << "Equação: " << result[0] << "x + " << result[1] << std::endl;
        std::cout << "Equação: " << result[0] << "*" << PI << " + " << result[1] << std::endl;
    }
    
    return result[0]*PI+result[1];
}

