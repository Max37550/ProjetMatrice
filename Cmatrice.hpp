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
};

/**
 * Constructeur par défaut de la classe Cmatrice : Il appelle le constructeur par défaut de Ctableau2D
 * @param void
 * @exception void
 */
template <class T>
Cmatrice<T>::Cmatrice() : Ctableau2D<T>(){}

/**
 * Constructeur de recopie  de la classe Cmatrice : Il appelle le constructeur de recopie de Ctableau2D
 * @param MATmatrice, un objet de type Cmatrice
 * @exception void
 */
template <class T>
Cmatrice<T>::Cmatrice(Cmatrice<T> &MATmatrice):Ctableau2D<T>(MATmatrice){}

/**
 * Constructeur à 3 arguments de la classe Cmatrice : Il appelle le constructeur à 3 arguments de Ctableau2D
 * @param uiNbColonnes : le nombre de colonnes de la matrice, uiNbLignes : le nombre de lignes de la matrice, pContenu : un tableau à deux dimensions représentant le contenu de la matrice
 * @exception void
 */
template <class T>
Cmatrice<T>::Cmatrice(unsigned int uiNbLignes, unsigned int uiNbColonnes, T **pContenu) : Ctableau2D<T>(uiNbLignes,uiNbColonnes,pContenu){}
template <class T>

/**
 * Destructeur par défaut de la classe Cmatrice
 * @param void
 * @exception void
 */
Cmatrice<T>::~Cmatrice(){}

/**
 * Méthode permettant de transposer une matrice
 * @param void
 * @returns Un objet de type Cmatrice représentant la matrice transposée
 * @exception void
 */
template <class T>
Cmatrice<T> Cmatrice<T>::MATTranspose(){
    unsigned int uiNbLignes = this->T2DLireNbLignes();
    unsigned int uiNbColonnes = this->T2DLireNbColonnes();
    T** tabResult = new T*[uiNbLignes];
    
    for(unsigned int uiColonne = 0; uiColonne < uiNbColonnes; uiColonne++){
        tabResult[uiColonne] = new T[uiNbLignes];
        for(unsigned int uiLigne = 0; uiLigne < uiNbLignes; uiLigne++){
            tabResult[uiColonne][uiLigne] = this->T2DLireContenu()[uiLigne][uiColonne];
        }
    }
    
    Cmatrice MATresult(uiNbColonnes, uiNbLignes, tabResult);
    //Libération du tableau temporaire
    for(unsigned int uiColonne = 0; uiColonne < uiNbColonnes; uiColonne++){
        free(tabResult[uiColonne]);
    }
    free(tabResult);
    return MATresult;
}

/**
 * Surcharge de l'opérateur + : Permet d'ajouter deux objets Cmatrice entre eux
 * @param MAT1 et MAT2, les deux matrices à ajouter entre elles
 * @returns un objet Cmatrice représentant le résultat de l'addition
 * @exception Les deux matrices MAT1 et MAT2 doivent être de la même dimension
 */
template <class T>
Cmatrice<T> operator+(Cmatrice<T> &MAT1, Cmatrice<T> &MAT2){
    //Si les matrices n'ont pas la même taille
    if(MAT1.T2DLireNbLignes() != MAT2.T2DLireNbLignes() || MAT1.T2DLireNbColonnes() != MAT2.T2DLireNbColonnes()){
        //Lever une exception
    }
    
    unsigned int uiNbLignes = MAT1.T2DLireNbLignes();
    unsigned int uiNbColonnes = MAT1.T2DLireNbColonnes();
    T** tabResult = new T*[uiNbColonnes];
    T** tabMat1 = MAT1.T2DLireContenu();
    T** tabMat2 = MAT2.T2DLireContenu();
    
    for(unsigned int uiLigne = 0; uiLigne < uiNbLignes; uiLigne++){
        tabResult[uiLigne] = new T[uiNbColonnes];
        for(unsigned int uiColonne =0; uiColonne < uiNbColonnes; uiColonne++){
            tabResult[uiLigne][uiColonne] = tabMat1[uiLigne][uiColonne] + tabMat2[uiLigne][uiColonne];
        }
    }
    Cmatrice<T> MATresultat(uiNbLignes, uiNbColonnes, tabResult);
    //Libération du tableau temporaire
    for(unsigned int uiLigne = 0; uiLigne < uiNbLignes; uiLigne++){
        free(tabResult[uiLigne]);
    }
    free(tabResult);
    return MATresultat;
} 

template <class T> Cmatrice<T> operator*(Cmatrice<T> const &MAT1, Cmatrice<T> const &MAT2);
template <class T> Cmatrice<T> operator-(Cmatrice<T> const &MAT1, Cmatrice<T> const &MAT2);
template <class T> Cmatrice<T> operator/(Cmatrice<T> const &MAT1, double dNombre);
template <class T> Cmatrice<T> operator*(Cmatrice<T> const &MAT1, double dNombre);
template <class T> Cmatrice<T> operator*(double dNombre, Cmatrice<T> const &MAT1);

#endif /* Cmatrice_hpp */

