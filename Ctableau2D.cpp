//
//  Ctableau2D.cpp
//  projetMatrice
//
//  Created by Arthur Crocquevieille on 20/03/2016.
//  Copyright © 2016 Arthur Crocquevieille. All rights reserved.
//

#include "Ctableau2D.hpp"

/**
 * Constructeur par défaut de la classe Ctableau2D : Met le nombre de lignes et colonnes à 0 et le tableau à NULL
 * @param void
 * @exception aucune
 */
template <class T>
Ctableau2D<T>::Ctableau2D(){
    uiT2DNbColonnes = 0;
    uiT2DNbLignes = 0;
    pT2DContenu = NULL;
}

/**
 * Constructeur de recopie de la classe Ctableau2D : Recopie l'objet de type Ctableau2D passé en paramètre dans un nouvel objet
 * @param T2DTab : l'objet Ctableau2D à recopier
 * @exception aucune
 */
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

/**
 * Constructeur à 3 arguments de la classe Ctableau2D
 * @param nbLignes : le nombre de ligne de la matrice, nbColonnes : le nombre de colonnes, pContenu : le tableau
 * @exception Le tableau doit avoir nbLignes lignes et nbColonnes colonnes
 */
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

/**
 * Destructeur par défaut de la classe Ctableau2D
 * @param void
 * @exception aucune
 */
template <class T>
Ctableau2D<T>::~Ctableau2D(){
    
}

/**
 * Méthode qui retourne le nombre de lignes d'un Ctableau2D
 * @param void
 * @returns le nombre de lignes de type unsigned int
 * @exception aucune
 */
template <class T>
unsigned int Ctableau2D<T>::T2DLireNbLignes(){
    return uiT2DNbLignes;
}

/**
 * Méthode qui retourne le nombre de colonnes d'un Ctableau2D
 * @param void
 * @returns le nombre de colonnes de type unsigned int
 * @exception aucune
 */
template <class T>
unsigned int Ctableau2D<T>::T2DLireNbColonnes(){
    return uiT2DNbColonnes;
}

/**
 * Méthode qui retourne le contenu du Ctableau2D
 * @param void
 * @returns un tableau à 2 dimensions de type <T>
 * @exception aucune
 */
template <class T>
T** Ctableau2D<T>::T2DLireContenu(){
    return pT2DContenu;
}

/**
 * Méthode qui affiche un Ctableau2D dans la console
 * @param void
 * @returns void
 * @exception aucune
 */
template <class T>
void Ctableau2D<T>::T2DAffichage(){
    for(int i = 0;i<uiT2DNbLignes;i++){
        for(int j = 0;j<uiT2DNbColonnes;j++){
            std::cout << pT2DContenu[i][j] << '\t';
        }
        std::cout <<std::endl;
    }
}

/**
 * Surcharge de l'opérateur = : Permet d'affectionner un Ctableau2D à un autre
 * @param T2DTab, un objet de type Ctableau2D
 * @returns un objet de type Ctableau2D
 * @exception aucune
 */
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

