#ifndef GAUSSJACOBI_H
#define GAUSSJACOBI_H


class GaussJacobi
{
    public:
        GaussJacobi();
        virtual ~GaussJacobi();
        static void doCalculation(double ** m, int x, int y, double * initValues, double * results, double acceptableError);
    protected:

    private:
};

#endif // GAUSSJACOBI_H
