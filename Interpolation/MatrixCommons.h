#ifndef MATRIXCOMMONS_H
#define MATRIXCOMMONS_H


class MatrixCommons
{
    public:
        MatrixCommons();
        virtual ~MatrixCommons();
        /***
        * @param Matriz para ser impressa
        * @param Quantidade de linhas da matriz
        * @param Quantidade de colunas da matriz (Incluindo as respostas)
        */
        static void print(double ** m, int x, int y);
        static void multiply(double ** m1, int x1, int y1, double ** m2, int x2, int y2, double ** r);
        static void transpose(double ** m, int x, int y);
        static void swap(double * x, double * y);
        static void inverse(double ** m, int x, int y);
    protected:

    private:
};

#endif // MATRIXCOMMONS_H
