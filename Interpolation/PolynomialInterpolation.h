/* 
 * File:   PolynomialInterpolation.h
 * Author: lucas
 *
 * Created on 8 de Junho de 2017, 15:25
 */

#ifndef POLYNOMIALINTERPOLATION_H
#define POLYNOMIALINTERPOLATION_H


class PolynomialInterpolation {
public:
    PolynomialInterpolation();
    PolynomialInterpolation(const PolynomialInterpolation& orig);
    virtual ~PolynomialInterpolation();
    
    /***

     * @param Vetor com os valores do eixo X 
     * @param Vetor com os valores do eixo Y
     * @param Ponto a ser interpolado
     * @param Tamanho do vetor
     * @param Mostrar passos executados para realização da interpolação
     */
    static double laGrange(double * x, double * y, double PI, int size, bool showSteps /* = false */);
    
    /***
     * @param Vetor com os valores do eixo X 
     * @param Vetor com os valores do eixo Y
     * @param Ponto a ser interpolado
     * @param Grau para realização da interpolação
     * @param Tamanho do vetor
     * @param Mostrar passos executados para realização da interpolação
     */
    static double newton(double * x, double * y, double PI, int size, bool showSteps /* = false */);
private:

};

#endif /* POLYNOMIALINTERPOLATION_H */

