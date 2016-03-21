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
    Ctableau2D(){
        uiT2DNbColonnes = 0;
        uiT2DNbLignes = 0;
        pT2DContenu = NULL;
    };
    Ctableau2D<T>(Ctableau2D<T> &T2DTab){
        
    };
    Ctableau2D<T>(unsigned int nbLignes, unsigned int nbColonnes,T **pContenu){
        uiT2DNbLignes =nbLignes;
        uiT2DNbColonnes = nbColonnes;
        pT2DContenu = pContenu;
    };
    ~Ctableau2D<T>();
    //Méthodes
    public :
    unsigned int T2DLireNbLignes(){return uiT2DNbLignes;}
    unsigned int T2DLireNbColonnes(){return uiT2DNbColonnes;}
    void T2DAffichage(){
        for(int i = 0;i<uiT2DNbLignes;i++){
            for(int j = 0;j<uiT2DNbColonnes;j++){
                std::cout << pT2DContenu[i][j];
            }
            std::cout <<std::endl;
        }
    };
    
    //Surcharge
    public :
    Ctableau2D<T> operator=(Ctableau2D<T> &TD2Tab);

    
};
#endif /* Ctableau2D_hpp */
