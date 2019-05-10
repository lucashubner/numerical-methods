#include "Gauss.h"
#include "CholeskyFactorization.h"
#include "LUFactorization.h"
#include "MatrixCommons.h"
#include <iostream>
#include <cstdio>
#include <cmath>

CholeskyFactorization::CholeskyFactorization()
{
    //ctor
}

CholeskyFactorization::~CholeskyFactorization()
{
    //dtor
}
void CholeskyFactorization::doCalculation(double ** m, int x, int y, double * results, bool showSteps){
    double ** l;
    double ** u;
    // Raiz quadrada da diagonal principal de U
    double ** sqrtDU;
    double ** G;
    l  = new double*[x];
    u  = new double*[x];
    sqrtDU = new double*[x];
    G = new double*[x];
    for(int i = 0; i < x; i++){
        l[i]  = new double[y];
        u[i]  = new double[y];
        sqrtDU[i] = new double[y];
        G[i] = new double[y];
    }
    double resultLU[x];
    LUFactorization::getLUMatrix(m,l,u,x,y,resultLU);
    if(showSteps){
        std::cout << "*************************************************" << std::endl;
        std::cout << "L MATRIX" << std::endl;
        MatrixCommons::print(l,x,y);
        std::cout << "*************************************************"<< std::endl;
        std::cout << "U MATRIX" << std::endl;
        MatrixCommons::print(u,x,y);
        std::cout << "*************************************************"<< std::endl;
    }
    // Reajusta a diagonal da matriz U
    for(int i = 0; i < x; i++){
        sqrtDU[i][i] = sqrt(u[i][i]);
        l[i][i] = 1;
    }

    MatrixCommons::multiply(l, x, y-1, sqrtDU, x, y-1, G);
    if(showSteps){
        std::cout << "G = L x Raiz de D" << std::endl;
        MatrixCommons::print(G,x,y);
    }

    // Calcula Gy=b (B Está no campo de resposta da matriz!!!!!
    for(int i = 0; i < x; i++){
        G[i][y-1] = m[i][y-1];
    }
    double resultB[x];
    Gauss::getLTResult(G,x,y,resultB,showSteps);

    if(showSteps){
        std::cout << "Gy = B :";
        for(int i =0; i < x; i++){
            std::cout << resultB[i] << " | ";
        }
        std::cout << std::endl;

        std::cout << "GT x = y" << std::endl;
    }

    MatrixCommons::transpose(G,x,y-1);
    // Adiciona B a matriz G
    for(int i =0; i < x; i++){
        G[i][y-1] = resultB[i];
    }
    if(showSteps){
        MatrixCommons::print(G,x,y);
    }

    Gauss::getUTResult(G,x,y,results);
    if(showSteps){
    std::cout << "X : ";
        for(int i =0; i < x; i++){
            std::cout << results[i] << " | ";
        }
    }
}
