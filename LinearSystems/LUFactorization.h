#ifndef  LUFACTORIZATION_H
#define  LUFACTORIZATION_H


class  LUFactorization
{
    public:
         LUFactorization();
        virtual ~ LUFactorization();
        /***
        * @param Matriz para realização dos calculos
        * @param Quantidade de linhas da matriz
        * @param Quantidade de colunas da matriz (Incluindo resposta)
        * @param Vetor de tamanho igual a quantidade de linhas da matriz para armazenamento das respostas
        * @param Imprimir passo a passo na tela (Opcional) default: false
        */
        static void doCalculation(double ** m, int x, int y,double * results, bool showSteps = false);
        /***
        * @param Matriz para realização dos calculos
        * @param Quantidade de linhas da matriz
        * @param Quantidade de colunas da matriz (Incluindo resposta)
        * @param Vetor de tamanho igual a quantidade de linhas da matriz para armazenamento das respostas
        * @param Imprimir passo a passo na tela (Opcional) default: false
        */
        static void getLUMatrix(double ** m, double ** l, double ** u, int x, int y,double *results, bool showSteps = false);
    protected:

    private:
};

#endif //  LUFACTORIZATION_H
