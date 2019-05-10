/* 
 * File:   Menu.cpp
 * Author: lucas
 * 
 * Created on 16 de Junho de 2017, 15:17
 */

#include "Menu.h"
#include <iostream>

#include "LinearInterpolation.h"
#include "QuadraticInterpolation.h"
#include "PolynomialInterpolation.h"
#include "SplineInterpolation.h"
Menu::Menu() {
}

Menu::Menu(const Menu& orig) {
}

Menu::~Menu() {
}

int Menu::showMethods() {
    int menu = 0;
    std::cout << "1 - Interpolação Linear" << std::endl;
    std::cout << "2 - Interpolação Quadrática" << std::endl;
    std::cout << "3 - Interpolação Polinomial - Polinomio de Newton" << std::endl;
    std::cout << "4 - Interpolação Polinomial - Polinomio de Lagrange" << std::endl;
    std::cout << "5 - Interpolação SpLine - Linear" << std::endl;
    std::cout << "6 - Interpolação SpLine - Cubica" << std::endl;
    while(menu < 1 || menu > 6){
        std::cin >> menu;
        if(menu < 1 || menu > 6){
            std::cout << "Menu invalido!!" << std::endl;
        }
    }
    
    return menu;
}

int Menu::askSize(int * n) {
    std::cout << "Entre com a quantidade de valores a serem lidos" << std::endl;
    std::cin >> *n;
    return *n;
}

void Menu::askVectors(double* x, double* y, int n) {
    std::cout << "Por favor, entre com os valores do vetor X separados por espaços" << std::endl;
    std::cout << "Use pontos para informar valores reais. Ex: 10.2" << std::endl;
    std::cout << "X | ";
    for(int i = 0; i < n; i++){
        std::cin >> x[i];
    }
    std::cout << std::endl << "Y | ";
    for(int i = 0; i < n; i++){
        std::cin >> y[i];
    }
    std::cout << std::endl;
}

void Menu::askPoints(int * P1, int * P2) {
    std::cout << "Entre com indice dos dois pontos para interpolação linear" << std::endl;
    std::cout << "Ponto 1: "; std::cin >> *P1;
    std::cout << "Ponto 2: "; std::cin >> *P2;
}
void Menu::askPointsBeginEnd(int* PB, int* PE) {
    std::cout << "Entre com o indice dos pontos inicial e final do vetor X para utilizar na interpolação";
    std::cout << "Ex:" << std::endl;
    std::cout << "________________________"  << std::endl;
    std::cout << "|x1|x2|x3|x4|x5|x6|x7|x8|" << std::endl;
    std::cout << "|__|__|__|__|__|__|__|__|" << std::endl;
    std::cout << " /\\      /\\ " << std::endl;
    std::cout << " |PIni   | PFim" << std::endl;
    std::cout << "Neste caso, utilizam-se os pontos x1,x2,x3 e x4 para o calculo de interpolação" << std::endl;
    
            
    std::cout << "Ponto Inicial: "; std::cin >> *PB;
    std::cout << "Ponto Final  : "; std::cin >> *PE;
}

void Menu::askPointToInterpolate(double * PI){
    std::cout << "Entre com o ponto a ser interpolado" << std::endl;
    std::cout << "PI: "; std::cin >> *PI;
}



void Menu::gotoMethod(int method) {
    int size;
    this->askSize(&size);
    double x[size];
    double y[size];
    double result = 0;
    double PI;
    this->askVectors(x,y,size);
    
    switch(method){
        
        case 1:
            int P1,P2;
            askPoints(&P1, &P2);
            askPointToInterpolate(&PI);
            result = LinearInterpolation::doCalculation(x,y,P1,P2, PI, size, true);
            break;
            
        case 2:
            int PB, PE;
            askPointsBeginEnd(&PB, &PE);
            askPointToInterpolate(&PI);
            result = QuadraticInterpolation::doCalculation(x,y,PB,PE,PI,size,true);
            break;
            
        case 3:
            askPointToInterpolate(&PI);
            result = PolynomialInterpolation::newton(x,y,PI,size, true);
            break;
            
        case 4:
            askPointToInterpolate(&PI);
            result = PolynomialInterpolation::laGrange(x,y,PI,size, true);
            break;
            
        case 5:
            askPointToInterpolate(&PI);
            result = SplineInterpolation::linear(x,y,PI, size, true);
            break;
            
        case 6:
            askPointToInterpolate(&PI);
            result = SplineInterpolation::cubic(x,y,PI, size, true);
            
            break;
            
        default:
            break;

    }
    
    std::cout << "f(x) = " << result << std::endl;
    
}
    
