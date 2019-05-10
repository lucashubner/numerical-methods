#include "Gauss.h"
#include <iostream>
#include "MatrixCommons.h"
Gauss::Gauss()
{
    //ctor
}
/*
*
*/
void Gauss::getUTMatrix(double ** m, int x, int y, double *kValues, bool showSteps /*=false*/){
    int kValueIt =0;
    // Para cada linha base
    for(int k = 0; k < x-1; k++){
        // para cada linha a ser modificada
        for(int i = k+1; i < x; i++){
            double mult = -m[i][k]/m[k][k];
            kValues[kValueIt++] = mult;

            // Para cada coluna da linha a ser modificada
            m[i][k] = 0;
            for(int j=k+1; j < y; j++){
                m[i][j] += m[k][j] * mult;
            }
            if(showSteps){
                std::cout << std::endl << "##################################################################################" << std::endl;
                std::cout << "Iteracao      :"  << k << std::endl;
                std::cout << "Linha         :" << i << std::endl;
                std::cout << "Multiplicador : " << mult << std::endl;
                MatrixCommons::print(m, x, y);
            }
        }
    }
}
void Gauss::getLTResult(double ** m, int x, int y, double * result, bool showSteps /*=false*/){
    for(int i = 0; i < x; i++){
        result[i] = m[i][y-1];
        if(showSteps){
            std::cout << "(" << m[i][y-1];
        }
        double sum = 0;
        for(int j = 0; j < i; j++){
            sum -= result[j] * m[i][j];
            if(showSteps){
                std::cout << "+" << result[j] << " x " << m[i][j];
            }
        }
        result[i] += sum;
        result[i] /= m[i][i];
        if(showSteps)
            std::cout << ")/" << m[i][i] << " = " << result[i] << std::endl;
    }

    if(showSteps){
        std::cout << std::endl << "##################################################################################" << std::endl;
        for(int i =0; i < x;i++){
            std::cout << "Resultado " << (char)('a'+i) << " = " << result[i] << std::endl;
        }
    }
}

void Gauss::getUTResult(double ** m, int x, int y, double * result, bool showSteps /*= false*/){
    for(int i = 1; i <= x; i++){
        result[x-i] = m[x-i][y-1];
        double sum = 0;
        for(int j = 1; j < i; j++){
            sum -= result[x-j] * m[x-i][y-j-1];
        }
        result[x-i] += sum;
        result[x-i] /= m[x-i][y-i-1];
    }

    if(showSteps){
        std::cout << std::endl << "##################################################################################" << std::endl;
        for(int i =0; i < x;i++){
            std::cout << "Resultado " << (char)('a'+i) << " = " << result[i] << std::endl;
        }
    }
}

void Gauss::doCalculation(double ** m, int x, int y, double * result, bool showSteps /*= false*/){
    double kValues[x*x/2];
    Gauss::getUTMatrix(m,x,y,kValues,showSteps);
    Gauss::getUTResult(m,x,y,result,showSteps);

}
