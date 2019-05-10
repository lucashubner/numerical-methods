/* 
 * File:   SplineInterpolation.cpp
 * Author: lucas
 * 
 * Created on 8 de Junho de 2017, 15:25
 */

#include "SplineInterpolation.h"
#include <iostream>

SplineInterpolation::SplineInterpolation() {
}

SplineInterpolation::SplineInterpolation(const SplineInterpolation& orig) {
}

SplineInterpolation::~SplineInterpolation() {
}

double SplineInterpolation::linear(double* x, double* y, int size, int PI, bool showSteps) {
    for(int i = 0; i < size-1; i++){
        if(showSteps){
            std::cout << "S" << i+1 << " : ";
            std::cout << y[i-1] << "+" << "(" << y[i] << "-" << y[i-1] << ")";
            std::cout << "/(" << x[i] << "-" << x[i-1] << ")*(X-" << x[i-1] << ")" << std::endl;
            std::cout << "    | Dominio ( " << x[i] << "..." << x[i+1] << ")" << std::endl;
        }
    }
    for(int i = 1; i < size; i++){
        if(x[i-1] < PI && x[i] > PI){
            double result = y[i-1] + (y[i] - y[i-1])/(x[i]-x[i-1])*(PI-x[i-1]);
            std::cout << "Resolução: " << std::endl << "\t f("<< PI << ") = ";
            std::cout << y[i-1] << "+" << "(" << y[i] << "-" << y[i-1] << ")";
            std::cout << "/(" << x[i] << "-" << x[i-1] << ")*(" << PI << "-" << x[i-1] << ")";
            std::cout << " = " << result;
            std::cout << std::endl;
            return result;
        }
    }
}

double SplineInterpolation::cubic(double* x, double* y, int size, int PI, bool showSteps) {
    // h = espaçamento entre os X respectivos
    // Distancia entre xi e xi+1
    double h[size];
    for(int i = 0; i < size; i++){
        h[i] = x[i+1]-x[i];
    }
    
    double alfa[size];
    
    for(int i = 0; i < size; i++){
        alfa[i] = ((3/h[i])*(y[i+1] - y[i] ) - (3/h[i-1]) * ( y[i] - y[i-1]));
    }
    
    double l[size], u[size], z[size];
    l[0] = 1; u[0] = 0; z[0] = 0;
    
    for(int i = 1; i < size; i++){
        l[i] = ((2*(x[i+1]-x[i-1])) - (h[i-1]*u[i-1]));
        u[i] = h[i]/l[i];
        z[i] = ((alfa[i]-(h[i-1]*z[i-1]))/l[i]);
    }
    
    l[size] = 1;
    z[size] = 0;
    
    
    //
    double c[size], b[size], d[size];
    c[size] = 0;
    for(int i = size-1; i>=0; i--){
        c[i] = z[i] - (u[i]*c[i+1]);
        b[i] = (((y[i+1]-y[i])/h[i])-((h[i]*(c[i+1]+2*c[i]))/3));
        d[i] = ((c[i+1] - c[i])/(3*h[i]));
    }
    
    // Encontra indices que cercam o ponto a ser interpolado
    //   1  2  3  4
    // | .  . |.  .
    // |______|____
    //        PI     Pos = 3
    
    int pos = 1;
    while(!( (x[pos-1]) < PI && x[pos] > PI))
        pos++;
    double result =0;

    int i = 0;
    if(pos > 2){
        i = pos-2;
    }
    for(int j = 0; j < 5; j++, i++){
        
        if(showSteps){
            std::cout << "S(" << j << ") =";
            std::cout << y[i];
            std::cout << "+";
            std::cout << b[i] << "*(x-" << x[i] << ")";

            std::cout << "+";
            std::cout << c[i] << "*(x-" << x[i] << ")^2 ";

            std::cout << "+";
            std::cout << d[i] << "*(x-" << x[i] << ")^3" << std::endl;
            std::cout << std::endl;
        }
        
    }
    
    
}