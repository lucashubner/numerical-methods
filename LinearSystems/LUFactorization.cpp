#include "LUFactorization.h"
#include "MatrixCommons.h"
#include "Gauss.h"
#include <iostream>
#include <cstdio>

 LUFactorization:: LUFactorization(){}
 LUFactorization::~ LUFactorization(){}

void LUFactorization::getLUMatrix(double ** m, double ** l, double ** u, int x, int y, double * results, bool showSteps){
    for(int i = 0;i < x; i++){
        for(int j = 0; j < y; j++){
            u[i][j] = m[i][j];
            l[i][j] = i == j? 1 :
                      i >  j? 1 : 0;
        }
    }
    double kValues[x];
    int kValueIt= 0;
    Gauss::getUTMatrix(u, x,y-1,kValues);

    // Adiciona os resultados da matriz A na matriz L
    for(int i = 0; i < x; i++){
        l[i][y-1] = m[i][y-1];
    }
    // Adiciona os valores de K na matriz L
    for(int i = 1; i < x; i++){
        for(int j = 0; j < i; j++){
            l[i][j] = -kValues[kValueIt++];
        }
    }

    double resultsY[x];
    Gauss::getLTResult(l, x,y,resultsY,showSteps);


    if(showSteps){
        MatrixCommons::print(l, x,y);
        std::cout << std::endl <<  "Y : ";
        for(int i =0; i < x; i++){
            std::cout << resultsY[i] << " | ";
        }
        std::cout << std::endl;
    }
    // Adiciona os valores encontrados na matriz U
    for(int i = 0; i < x; i++){
        u[i][y-1] = resultsY[i];
    }

    Gauss::getUTResult(u,x,y,results,showSteps);


    if(showSteps){
        MatrixCommons::print(u,x,y);
        std::cout << "X : ";
        for(int i =0; i < x; i++){
            std::cout << results[i] << " | ";
        }
    }

}
void LUFactorization::doCalculation(double ** m, int x, int y, double * results, bool showSteps){
    // Cria matriz auxiliar;
    double ** l;
    double ** u;
    l = new double * [x];
    u = new double * [x];

    for(int i = 0;i < x; i++){
        l[i] = new double[y];
        u[i] = new double[y];
        for(int j = 0; j < y; j++){
            u[i][j] = m[i][j];

            l[i][j] = i == j? 1 :
                      i >  j? 1 : 0;
        }
    }

    LUFactorization::getLUMatrix(m, l, u, x, y, results, showSteps);

    for(int i = 0; i < x; i++){
        delete [] l[i];
        delete [] u[i];
    }
    delete [] l;
    delete [] u;

}
