/* 
 * File:   PresentationFormatter.hpp
 * Author: lucas
 *
 * Created on 13 de Junho de 2017, 15:53
 */

#ifndef PRESENTATIONFORMATTER_HPP
#define PRESENTATIONFORMATTER_HPP

#include <string>


template<class Type>
class PresentationFormatter {
public:
    PresentationFormatter();
    PresentationFormatter(const PresentationFormatter& orig);
    virtual ~PresentationFormatter();
    std::string fixNumber(char signal, Type number){

    }
private:

};

#endif /* PRESENTATIONFORMATTER_HPP */

