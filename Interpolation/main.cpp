/* 
 * File:   main.cpp
 * Author: lucas
 *
 * Created on 6 de Junho de 2017, 19:52
 */

#include <cstdlib>
#include <iostream>
#include <cstdio>

#include "LinearInterpolation.h"
#include "QuadraticInterpolation.h"
#include "PolynomialInterpolation.h"
#include "Menu.h"
#include "SplineInterpolation.h"
/*
 * 
 */
int main(int argc, char** argv) {
    
    Menu menu;
    menu.gotoMethod(menu.showMethods());
    
    // Para os metodos linear e quadratico
    //double x[] ={0,1,2,3,4,5,6};
    //double y[] = {5,40,67,95,129,130,143};
    //std::cout << LinearInterpolation::doCalculation(x,y,2,3,2.8,7,true) << std::endl;
    //std::cout << QuadraticInterpolation::doCalculation(x,y,2,4,2.8,7,true) << std::endl;
    
    // Para o método de la grange
//    double x[] = {-2, 0, 4};
//    double y[] = {2, -2 ,1};
    //double x[] = {1,3,4,5};
    //double y[] = {0,6,24,60};
//    double x[] = {0, 10,     15,     20,     22.5,  30 };
//    double y[] = {0, 227.04, 362.78, 517.35, 602.97, 901.67 };
//    
//    std::cout << PolynomialInterpolation::laGrange(x,y,1,4,true) << std::endl;
//    
//    std::cout << "Interpolando para x = " << 1 << std::endl;
//    std::cout << PolynomialInterpolation::newton(x,y,1,4,true) << std::endl;
    
    //std::cout << SplineInterpolation::linear(x,y,6,16, true) << std::endl;
    //std::cout << SplineInterpolation::cubic(x,y,6, 16, true) << std::endl;
    return 0;
}

