/* 
 * File:   SplineInterpolation.h
 * Author: lucas
 *
 * Created on 8 de Junho de 2017, 15:25
 */

#ifndef SPLINEINTERPOLATION_H
#define SPLINEINTERPOLATION_H

class SplineInterpolation {
public:
    SplineInterpolation();
    SplineInterpolation(const SplineInterpolation& orig);
    virtual ~SplineInterpolation();
    
    static double linear(double * x, double * y, int size, int PI, bool showSteps);
    static double cubic(double * x, double * y, int size, int PI, bool showSteps);
private:

};

#endif /* SPLINEINTERPOLATION_H */

