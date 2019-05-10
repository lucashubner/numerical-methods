#ifndef GAUSS_H
#define GAUSS_H

class Gauss
{
    public:
        Gauss();
        /***
          * Get Uppper Triangle Matrix
        */
        static void getUTMatrix(double ** m, int x, int y, double * kValue, bool showSteps = false);

        static void getUTResult(double ** m, int x, int y, double * result, bool showSteps = false);
        static void getLTResult(double ** m, int x, int y, double * result, bool showSteps = false);
        static void doCalculation(double ** m, int x, int y, double * result, bool showSteps = false);

    protected:

    private:
};

#endif // GAUSS_H
