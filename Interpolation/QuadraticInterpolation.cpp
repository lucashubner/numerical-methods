/* 
 * File:   QuadraticInterpolation.cpp
 * Author: lucas
 * 
 * Created on 12 de Junho de 2017, 16:04
 */

#include <cmath>
#include <iostream>
#include "QuadraticInterpolation.h"
#include "Gauss.h"
#include "MatrixCommons.h"
QuadraticInterpolation::QuadraticInterpolation() {
}

QuadraticInterpolation::QuadraticInterpolation(const QuadraticInterpolation& orig) {
}

QuadraticInterpolation::~QuadraticInterpolation() {
}


double QuadraticInterpolation::doCalculation(double* x, double* y, int PIX, int PFX, double PI, int sizeVet, bool showSteps) {
    double **m;
    int size = PFX-PIX+1;
    double result[size];
    double finalResult = 0;

    // Verifica se os pontos escolhidos estão no invervalo dos vetores 
    //std::cout << 
    // Cria matriz n*n+1 para resolver sistema linear
    m = new double*[size];
    for(int i = 0; i < size; i++){
        m[i] = new double[size+1];
    }
    
     for(int i = 0; i < size ; i++){
         int powVal = size-1;
         for(int j = 0; j < size; j++){
            m[i][j] = pow(x[i+PIX], powVal--);
         }
         m[i][size] = y[i+PIX];
     }
    
    
    if(showSteps){
        MatrixCommons::print(m,size, size+1);
        std::cout << "Aplicando Gauss " << std::endl;
    }
    
    Gauss::doCalculation(m, size, size+1,result,showSteps);
   
    if(showSteps){
        std::cout << "Equação: y = ";
        int size2 = size + 2;
        for(int i = 0; i < size2; i++){
            if(size != 1){
                std::cout << " + (" << result[i] << "x^" << --size2 << ")"; 
            }
            else{
                std::cout << " + (" << result[i] << ")" << std::endl;
            }   
        }
        std::cout << std::endl;
    }
    
    for(int i =0; i < size+2; i++){
        if(size != 1)
            finalResult += result[i] * pow(PI, --size);
        else
            finalResult += result[i];
    }
    
    return finalResult;
}
