#include "GaussSeidel.h"
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cmath>
GaussSeidel::GaussSeidel(){}
GaussSeidel::~GaussSeidel(){}

void GaussSeidel::doCalculation(double ** m, int x, int y, double * initValues, double * results, double acceptableError){
    double ** aux;
    aux = new double*[x];
    for(int i =0; i< x; i++){
        aux[i] = new double[y];
    }

    for(int i = 0; i < x; i++){
        for(int j = 0; j <y; j++){
            if(i!= j){
                aux[i][j] = -m[i][j]/m[i][i];
            }
            else{
                aux[i][j] = 0;
            }
            if(j==y-1){
                aux[i][j]*=-1;
            }

        }
    }
    std::cout << std::setw(12) << "K";
    for(int i =0; i < x; i++){
            std::cout << std::setw(12) << "X" << i;
    }
    std::cout << std::endl;
    int k =0;


    // Enquanto não encontrar um erro aceitavel
    while(true){
        for(int i = 0; i < x; i++){
            double sum = 0;
            for(int j = 0; j < y; j++){
                if(j != y-1)
                    sum += aux[i][j] * initValues[j];
                else
                    sum += aux[i][j];

            }
            initValues[i] = sum;
        }
        for(int i =0; i < x; i++){
            std::cout << std::fixed << std::setprecision(8) << initValues[i] << " | ";
        }
        std::cout << std::endl;


        double var[x];
        bool bWhile = true;
        std::cout << std::setw(12) << k++;
        for(int i =0; i < x; i++){
            var[i] = std::abs(initValues[i] - results[i]);
            bWhile &= var[i] <= acceptableError;
            initValues[i] = results[i];
            std::cout << std::setw(12) << std::fixed << std::setprecision(8) << initValues[i];
            results[i] = initValues[i];
        }
        std::cout << " | ";
        for(int i =0; i < x; i++){
            std::cout << std::setw(12) << std::fixed << std::setprecision(8) << var[i];
        }
        std::cout << std::endl;
        if(bWhile){
            return;
        }
    }

}
