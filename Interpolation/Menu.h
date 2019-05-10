/* 
 * File:   Menu.h
 * Author: lucas
 *
 * Created on 16 de Junho de 2017, 15:17
 */

#ifndef MENU_H
#define MENU_H

class Menu {
public:
    int showMethods();
    int askSize(int * n);
    void askVectors(double * x, double * y, int i);
    void askPoints(int * P1, int * P2);
    void gotoMethod(int method);
    void askPointToInterpolate(double * PI);
    void askPointsBeginEnd(int *PB, int *PE);
    Menu();
    Menu(const Menu& orig);
    virtual ~Menu();
private:

};

#endif /* MENU_H */

