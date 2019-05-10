#ifndef GAUSSSEIDEL_H
#define GAUSSSEIDEL_H


class GaussSeidel
{
    public:
        GaussSeidel();
        virtual ~GaussSeidel();
        static void doCalculation(double ** m, int x, int y, double * initValues, double * results, double acceptableError);

    protected:

    private:
};

#endif // GAUSSSEIDEL_H
