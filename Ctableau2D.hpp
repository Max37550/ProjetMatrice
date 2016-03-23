//
//  Ctableau2D.hpp
//  projetMatrice
//
//  Created by Arthur Crocquevieille on 20/03/2016.
//  Copyright © 2016 Arthur Crocquevieille. All rights reserved.
//

#ifndef Ctableau2D_hpp
#define Ctableau2D_hpp

#include <iostream>
#include <stdio.h>

template <class T>
class Ctableau2D {
    //Attributs
    private :
    unsigned int uiT2DNbLignes;
    unsigned int uiT2DNbColonnes;
    T **pT2DContenu;
    
    //Constructeurs et destructeur
    public :
    Ctableau2D<T>();
    Ctableau2D<T>(Ctableau2D<T> &T2DTab);
    Ctableau2D<T>(unsigned int nbLignes, unsigned int nbColonnes,T **pContenu);
    ~Ctableau2D<T>();
    
    //Méthodes
    public :
    unsigned int T2DLireNbLignes();
    unsigned int T2DLireNbColonnes();
    T** T2DLireContenu();
    void T2DAffichage();
    
    //Surcharge
    public :
    Ctableau2D<T> operator=(Ctableau2D<T> &T2DTab);
};
#include "Ctableau2D.cpp"
#endif /* Ctableau2D_hpp */
