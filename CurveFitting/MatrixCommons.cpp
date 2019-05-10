#include "MatrixCommons.h"
#include <iostream>
#include <cstdio>

using namespace std;

MatrixCommons::MatrixCommons()
{
    //ctor
}

MatrixCommons::~MatrixCommons()
{
    //dtor
}
/**
*
*/
void MatrixCommons::print(double ** m, int x, int y){
    // Deixa um espa�o em branco
    cout.width(16); cout << ' ';
    // Nomeia colunas das variaveis
    for(int i = 0; i < y-1; i++){
        cout.width(15);
        cout << (char)('a'+i) << ' ';
    }
    // Nomeia coluna dos resultados
    cout.width(15); cout << "Resultado" << endl;
    for(int i = 0; i < x; i++){
        cout.width(14);
        cout << 'L' << i << '|';
        for(int j =0; j<y; j++){
            cout.width(15);
            cout <<  m[i][j] << '|';
        }
        cout << endl;;
    }
}
/*
*/
void MatrixCommons::multiply(double ** m1, int x1, int y1, double ** m2, int x2, int y2, double ** r){
    for(int i1 = 0; i1 < x1; i1++){
        for(int j1 = 0; j1 < y1; j1++){
            double sum = 0;
            for(int i2 = 0; i2 < x2; i2++){
                sum += m1[i1][j1] * m2[i2][j1];
            }
            r[i1][j1] = sum;
        }
    }
}

void MatrixCommons::swap(double * x, double * y){
    double z = *x;
    *x = *y;
    *y = z;
}

void MatrixCommons::transpose(double ** m, int x, int y){
    for(int i = 0; i< x; i++){
        for(int j = i+1; j < y ; j++){
            swap(&m[i][j], &m[j][i]);
        }
    }
}

void MatrixCommons::inverse(double** m, int x, int y) {
    double pivo;
    double p;
    double ident[x][y];
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            ident[i][j] = i==j? 1 : 0;
        }
    }
    
    for(int j = 0; j < y; j++){
        pivo = m[j][j];
        p = pivo/pivo;
        for(int k = j; k < y; k++){
            m[j][k] = (m[j][k])/(pivo);
            ident[j][k] = (ident[j][k])/(pivo);
        }
        
        for(int i = 0; i < x; i++){
             if(i != j){
                  m = m[i][j]/p;
                  
                  for(int k = 0; k < y; k++){
                      m[i][k] = (m[i][k]) - (m * m[j][k]);
                      ident[i][k] = (ident[i][k]) - (m * ident[j][k]);
                  }
              }
        }
    }

}
