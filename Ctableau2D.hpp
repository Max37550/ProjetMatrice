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
    }
    Ctableau2D<T>(Ctableau2D<T> &T2DTab){
        uiT2DNbLignes = T2DTab.T2DLireNbLignes();
        uiT2DNbColonnes = T2DTab.T2DLireNbColonnes();
        
        pT2DContenu = new T*[uiT2DNbLignes];
        for(unsigned int uiLigne = 0; uiLigne < uiT2DNbLignes; uiLigne++){
            pT2DContenu[uiLigne] = new T[uiT2DNbColonnes];
            for(unsigned int uiColonne =0; uiColonne <= uiT2DNbColonnes; uiColonne++){
                pT2DContenu[uiLigne][uiColonne] = T2DTab.T2DLireContenu()[uiLigne][uiColonne];
            }
        }
    }
    Ctableau2D<T>(unsigned int nbLignes, unsigned int nbColonnes,T **pContenu){
        uiT2DNbLignes = nbLignes;
        uiT2DNbColonnes = nbColonnes;
        
        pT2DContenu = new T*[nbLignes];
        for(unsigned int uiLigne = 0; uiLigne < nbLignes; uiLigne++){
            pT2DContenu[uiLigne] = new T[nbColonnes];
            for(unsigned int uiColonne =0; uiColonne <= nbColonnes; uiColonne++){
                pT2DContenu[uiLigne][uiColonne] = pContenu[uiLigne][uiColonne];
            }
        }
    }
    ~Ctableau2D<T>(){}
    //Méthodes
    public :
    unsigned int T2DLireNbLignes(){return uiT2DNbLignes;}
    unsigned int T2DLireNbColonnes(){return uiT2DNbColonnes;}
    T** T2DLireContenu(){return pT2DContenu;}
    void T2DAffichage(){
        for(int i = 0;i<uiT2DNbLignes;i++){
            for(int j = 0;j<uiT2DNbColonnes;j++){
                std::cout << pT2DContenu[i][j];
            }
            std::cout <<std::endl;
        }
    }
    
    //Surcharge
    public :
    Ctableau2D<T> operator=(Ctableau2D<T> &T2DTab){
        uiT2DNbLignes = T2DTab.T2DLireNbLignes();
        uiT2DNbColonnes = T2DTab.T2DLireNbColonnes();
        
        pT2DContenu = new T*[uiT2DNbLignes];
        for(unsigned int uiLigne = 0; uiLigne < uiT2DNbLignes; uiLigne++){
            pT2DContenu[uiLigne] = new T[uiT2DNbColonnes];
            for(unsigned int uiColonne = 0; uiColonne <= uiT2DNbColonnes; uiColonne++){
                pT2DContenu[uiLigne][uiColonne] = T2DTab.T2DLireContenu()[uiLigne][uiColonne];
            }
        }
        return *this;
    }

    
};
#endif /* Ctableau2D_hpp */
