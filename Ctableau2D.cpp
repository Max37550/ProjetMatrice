//
//  Ctableau2D.cpp
//  projetMatrice
//
//  Created by Arthur Crocquevieille on 20/03/2016.
//  Copyright © 2016 Arthur Crocquevieille. All rights reserved.
//

#include "Ctableau2D.hpp"

template <class T>
Ctableau2D<T>::Ctableau2D(){
    uiT2DNbColonnes = 0;
    uiT2DNbLignes = 0;
    pT2DContenu = NULL;
}

template <class T>
Ctableau2D<T>::Ctableau2D(Ctableau2D<T> &T2DTab){
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

template <class T>
Ctableau2D<T>::Ctableau2D(unsigned int nbLignes, unsigned int nbColonnes,T **pContenu){
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

template <class T>
Ctableau2D<T>::~Ctableau2D(){
    
}

template <class T>
unsigned int Ctableau2D<T>::T2DLireNbLignes(){
    return uiT2DNbLignes;
}

template <class T>
unsigned int Ctableau2D<T>::T2DLireNbColonnes(){
    return uiT2DNbColonnes;
}

template <class T>
T** Ctableau2D<T>::T2DLireContenu(){
    return pT2DContenu;
}

template <class T>
void Ctableau2D<T>::T2DAffichage(){
    for(int i = 0;i<uiT2DNbLignes;i++){
        for(int j = 0;j<uiT2DNbColonnes;j++){
            std::cout << pT2DContenu[i][j] << '\t';
        }
        std::cout <<std::endl;
    }
}

template <class T>
Ctableau2D<T> Ctableau2D<T>::operator=(Ctableau2D<T> &T2DTab){
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

