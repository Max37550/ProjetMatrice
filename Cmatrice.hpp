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
    Cmatrice<T>(unsigned int uiNbLignes, unsigned int uiNbColonnes, T **pContenu);
    ~Cmatrice<T>();
    //Methodes
    public :
    Cmatrice<T> MATTranspose();
    //Surcharges
    Cmatrice<T> operator+(Cmatrice<T> &MAT1);
    Cmatrice<T> operator-(Cmatrice<T> &MAT1);
    Cmatrice<T> operator*(double dValeur);
    Cmatrice<T> operator*(Cmatrice<T> &MAT1);
    Cmatrice<T> operator/(double dNombre);
};
#include "Cmatrice.cpp"
#endif /* Cmatrice_hpp */

