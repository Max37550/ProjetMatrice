//
//  Cmatrice.hpp
//  projetMatrice
//
//  Created by Arthur Crocquevieille on 20/03/2016.
//  Copyright © 2016 Arthur Crocquevieille. All rights reserved.
//

#ifndef Cmatrice_hpp
#define Cmatrice_hpp

#include <stdio.h>
#include "Ctableau2D.hpp"
template <class T>
class Cmatrice : public Ctableau2D<T> {
    //Constructeurs et destructeur
    public :
    Cmatrice<T>();
    Cmatrice<T>(Cmatrice<T> &MATmatrice);
    Cmatrice<T>(unsigned int uiNbLignes, unsigned int uiNbColonnes, T **pContenu) : Ctableau2D<T>(uiNbLignes,uiNbColonnes,pContenu){}
    ~Cmatrice<T>(){};
    //Methodes
    public :
    Cmatrice<T> MATTranspose();
    //surcharges
    
};

template <class T> Cmatrice<T>::Cmatrice() : Ctableau2D<T>(){}
template <class T> Cmatrice<T>::Cmatrice(Cmatrice<T> &MATmatrice):Ctableau2D<T>(MATmatrice){}

template <class T> Cmatrice<T> operator+(Cmatrice<T> MAT1, Cmatrice<T> MAT2);
template <class T> Cmatrice<T> operator*(Cmatrice<T> MAT1, Cmatrice<T> MAT2);
template <class T> Cmatrice<T> operator-(Cmatrice<T> MAT1, Cmatrice<T> MAT2);
template <class T> Cmatrice<T> operator/(Cmatrice<T> MAT1, double dNombre);
template <class T> Cmatrice<T> operator*(Cmatrice<T> MAT1, double dNombre);
template <class T> Cmatrice<T> operator*(double dNombre, Cmatrice<T> MAT1);

#endif /* Cmatrice_hpp */

