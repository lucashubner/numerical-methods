/* 
 * File:   PolynomialInterpolation.cpp
 * Author: lucas
 * 
 * Created on 8 de Junho de 2017, 15:25
 */

#include "PolynomialInterpolation.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm> 

PolynomialInterpolation::PolynomialInterpolation() {
}

PolynomialInterpolation::PolynomialInterpolation(const PolynomialInterpolation& orig) {
}

PolynomialInterpolation::~PolynomialInterpolation() {
}

double PolynomialInterpolation::laGrange(double* x, double* y, double PI, int size, bool showSteps) {
    
    double resultSum = 0;
    
    for(int i = 0; i < size; i++){
        double r1 = 1;
        double r2 = 1;
        
        if(showSteps){
            std::cout << "Equação |  L"  << i <<  " * f(x) " << std::endl;
        }
        
        for(int j = 0; j < size; j++){
            if(i != j){
                if(showSteps){
                    std::cout << "(X-" << x[j] << "/" << x[i] << "-" << x[j] << ")";
                }
                r1 *= PI-x[j];
                r2 *= x[i] - x[j]; 
            }
        }
        
        if(showSteps){
            std::cout << " " << y[i] << std::endl << std::endl;
        }
        
        resultSum += (r1/r2) * y[i];
    }
    
    return resultSum;
}

double PolynomialInterpolation::newton(double* x, double* y, double PI, int size, bool showSteps) {
    double result[size];
    double sum;
    int space = 20;
    for(int i =0; i < size; i++){
        result[i] = y[i];
    }
    
    if(showSteps){
        std::setiosflags(std::ios::internal);
        std::cout << std::setw(space) << "Tabela de Diferênças Divididas" << std::endl;
        for(int i = 0; i < size; i ++){
            std::ostringstream oss;
            oss << "| X" << size - i -1 << "(x = " << x[size - i -1] << ")";
            std::cout <<std::setfill('.')<< std::setw(space) << std::left << oss.str();
            if(i == size-1){
                std::cout << "|";
            }
            else{
                std::cout << std::setw(space)  << "|";
            }
        }
        std::cout << std::endl;


        for(int i = 0; i < size ; i++){
            std::ostringstream oss;
            oss << "|" << result[size- i -1];
            std::cout << std::setw(space) << std::left << oss.str();
            if(i == size-1){
                std::cout << "|";
            }
            else{
                std::cout << std::setw(space)  << "|";
            }
        }
        std::cout << std::endl;
    }
    
    for(int j = 0; j < size-1;j++){
        for(int emptyCell = 0; emptyCell < j; emptyCell++){
                std::cout << std::setw(space)  << "|";
        }
        for(int i = size-1 ;i > j ;i--){
            if(showSteps){    
                std::cout << std::setw(space)  << "|";

                std::ostringstream oss;
                oss << "|" <<  "(" << result[i];
                if(result[i-1]>0){
                    oss << "-" << result[i-1];
                }
                else{
                    oss << "+" << result[i-1]*-1;
                }
                 oss << ")/(" << x[i];
                 if(x[i-j-1] > 0){
                     oss << "-" << x[i-j-1] << ")";
                     
                 }
                 else{
                     oss << "+" << x[i-j-1]*-1 << ")";
                 }
                std::cout << std::setw(space) << std::left << oss.str();
            }
            result[i] = (result[i] - result[i-1])/(x[i] - x[i-j-1]);

            
        }
        if(showSteps){
            for(int emptyCell = 0; emptyCell < j+1; emptyCell++){
                std::cout << std::setw(space)  << "|";
            }
            std::cout << "|" << std::endl;
        }
    }
    
    if(showSteps){
        std::cout << "Polinomio formado: ";
    }
    
    for(int i = size-1; i>=0; i--){       
        double mult=1;
        for(int j = 0; j < i; j++){
            
            if(showSteps){
                std::cout << "(X";
                
                if(x[j] > 0){
                    std::cout << "-" << x[j] << ")";
                }
                if(x[j] < 0){
                    std::cout << "+" << x[j]*-1 << ")";
                }
                else{
                    //std::cout << ")";
                    
                }
                
            }
            mult*=PI-x[j];
        }
        if(showSteps){
            if(i == 0){
                std::cout << "+(" << result[i] << ")";          
            }
            else{
                std::cout << "*(" << result[i] << ")";          
            }
            if(i>1){
                std::cout << "+";
            }
        }
        
        mult*=result[i];
        sum+= mult;
    }
    if(showSteps){
        std::cout << std::endl;
    }
    
    return sum;
}
