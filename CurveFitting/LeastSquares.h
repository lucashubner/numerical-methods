/* 
 * File:   LeastSquares.h
 * Author: lucas
 *
 * Created on 22 de Junho de 2017, 01:05
 */

#ifndef LEASTSQUARES_H
#define LEASTSQUARES_H

class LeastSquares {
public:
    LeastSquares();
    LeastSquares(const LeastSquares& orig);
    virtual ~LeastSquares();
    //static void continuo(double * x, double * y, int size);
    //static void discreto(double * x, double * y, int size);
    static void mmq(double * y, double * y, int size, bool showSteps);
private:
    
    static void fillVandermonde(double ** m, int x, int y, double * x);
    

};

#endif /* LEASTSQUARES_H */

