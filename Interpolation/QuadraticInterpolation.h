/* 
 * File:   QuadraticInterpolation.h
 * Author: lucas
 *
 * Created on 12 de Junho de 2017, 16:04
 */

#ifndef QUADRATICINTERPOLATION_H
#define QUADRATICINTERPOLATION_H

class QuadraticInterpolation {
public:
    QuadraticInterpolation();
    QuadraticInterpolation(const QuadraticInterpolation& orig);
    virtual ~QuadraticInterpolation();
    /***
     * @param Vetor com os valores do eixo X 
     * @param Vetor com os valores do eixo Y
     * @param Indice do vetor X do primeiro valor utilizado para realização do calculo de Interpolação
     * @param Indice do vetor X do ultimo valor utilizado para realização do calculo de Interpolação
     * @param Ponto a ser interpolado
     * @param Tamanho do vetor
     * @param Mostrar passos executados para realização da interpolação
     */
    static double doCalculation(double * x, double * y, int PIX, int PFX, double PI, int size, bool showSteps /* = false */);
private:

};

#endif /* QUADRATICINTERPOLATION_H */

