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
    Cmatrice();
    Cmatrice<T>(Cmatrice<T> &MATmatrice):Ctableau2D<T>(MATmatrice){}
    Cmatrice<T>(unsigned int uiNbLignes, unsigned int uiNbColonnes, T **pContenu) : Ctableau2D<T>(uiNbLignes,uiNbColonnes,pContenu){}
    ~Cmatrice<T>(){};
    //Methodes
    public :
    Cmatrice<T> MATTranspose();
    //surcharges
    
};

template <class T>
Cmatrice<T>::Cmatrice() : Ctableau2D<T>(){
}

#endif /* Cmatrice_hpp */

