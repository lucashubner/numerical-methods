#include <iostream>
#include <cstdio>
#include "Gauss.h"
#include "MatrixCommons.h"
#include "LUFactorization.h"
#include "CholeskyFactorization.h"
#include "GaussJacobi.h"
#include "GaussSeidel.h"

using namespace std;

int main()
{
    int x;
    int y;
    double ** m;

    cout << "Entre com a quantidade de linhas da matriz" << endl;
    cin >> x;
    cout << "Entre com a quantidade de colunas da matriz" << endl;
    cin >> y;

    m = new double*[x];
    for(int i = 0; i < x; i++){
        m[i] = new double[y];
    }
    double result[x];

    cout << "Entre com os valores para a matriz " << x << " x " << y << endl;
    for(int i = 0; i < x; i++){
        cout << "Linha " << i << " | ";
        for(int j = 0; j < y; j++){
            cin >> m[i][j];
        }
    }

    Gauss::doCalculation(m, x, y, result, true);
    //LUFactorization::doCalculation(m,x,y,result,true);

    double initValues[] = {0,0,0};
    //CholeskyFactorization::doCalculation(m, x, y,result,true);
    //GaussJacobi::doCalculation(m,x,y,initValues,result,0.01);

    //GaussSeidel::doCalculation(m,x,y,initValues,result,0.01);

    for(int i = 0; i < x; i++)
        delete [] m[i];
    delete [] m;
    return 0;
}
