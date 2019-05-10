/* 
 * File:   LinearInterpolation.h
 * Author: lucas
 *
 * Created on 8 de Junho de 2017, 15:26
 */

#ifndef LINEARINTERPOLATION_H
#define LINEARINTERPOLATION_Hh

class LinearInterpolation {
public:
    LinearInterpolation();
    LinearInterpolation(const LinearInterpolation& orig); 
   
    virtual ~LinearInterpolation();
    /***
     * Formula da reta
     * P(x) = ax+b 
     * @param Vetor com os valores do eixo X 
     * @param Vetor com os valores do eixo Y
     * @param Indice do vetor X utilizado para realização do calculo de Interpolação
     * @param Indice do vetor X utilizado para realização do calculo de Interpolação
     * @param Ponto a ser interpolado
     * @param Tamanho do vetor
     * @param Mostrar passos executados para realização da interpolação
     */
    static double doCalculation(double * x, double * y, int PX1, int PX2, double PI, int size, bool showSteps /* = false */);
private:
    

};

#endif /* LINEARINTERPOLATION_H */

