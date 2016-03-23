//
//  Cmatrice.cpp
//  projetMatrice
//
//  Created by Arthur Crocquevieille on 20/03/2016.
//  Copyright © 2016 Arthur Crocquevieille. All rights reserved.
//

#include "Cmatrice.hpp"

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
 * @exception L'addition doit être cohérente par rapport au type de la matrice
 */
template <class T>
Cmatrice<T> Cmatrice<T>::operator+(Cmatrice<T> &MAT1){
    //Si les matrices n'ont pas la même taille
    if(this->T2DLireNbLignes() != MAT1.T2DLireNbLignes() || this->T2DLireNbColonnes() != MAT1.T2DLireNbColonnes()){
        //Lever une exception
    }
    
    unsigned int uiNbLignes = this->T2DLireNbLignes();
    unsigned int uiNbColonnes = this->T2DLireNbColonnes();
    T** tabResult = new T*[uiNbColonnes];
    T** tabMat1 = this->T2DLireContenu();
    T** tabMat2 = MAT1.T2DLireContenu();
    
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

/**
 * Surcharge de l'opérateur - : Permet de soustraire deux objets Cmatrice entre eux
 * @param MAT1 et MAT2, les deux matrices à soustraire entre elles
 * @returns un objet Cmatrice représentant le résultat de la soustraction
 * @exception Les deux matrices MAT1 et MAT2 doivent être de la même dimension
 * @exception La soustraction doit être cohérente par rapport au type de la matrice
 */
template <class T>
Cmatrice<T> Cmatrice<T>::operator-(Cmatrice<T> &MAT1){
    //Si les matrices n'ont pas la même taille
    if(this->T2DLireNbLignes() != MAT1.T2DLireNbLignes() || this->T2DLireNbColonnes() != MAT1.T2DLireNbColonnes()){
        //Lever une exception
    }
    
    unsigned int uiNbLignes = this->T2DLireNbLignes();
    unsigned int uiNbColonnes = this->T2DLireNbColonnes();
    T** tabResult = new T*[uiNbColonnes];
    T** tabMat1 = this->T2DLireContenu();
    T** tabMat2 = MAT1.T2DLireContenu();
    
    for(unsigned int uiLigne = 0; uiLigne < uiNbLignes; uiLigne++){
        tabResult[uiLigne] = new T[uiNbColonnes];
        for(unsigned int uiColonne =0; uiColonne < uiNbColonnes; uiColonne++){
            tabResult[uiLigne][uiColonne] = tabMat1[uiLigne][uiColonne] - tabMat2[uiLigne][uiColonne];
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

/**
 * Surcharge de l'opérateur * : Permet de multiplier un objet Cmatrice par un double
 * @param MAT1 : la matrice à multiplier, dNombre : un double
 * @returns un objet Cmatrice représentant le résultat de la multiplication
 * @exception La multiplication doit être cohérente par rapport au type de la matrice
 */
template <class T>
Cmatrice<T> Cmatrice<T>::operator*(double dNombre){
    unsigned int uiNbLignes = T2DLireNbLignes();
    unsigned int uiNbColonnes = this->T2DLireNbColonnes();
    T** tabResult = new T*[uiNbColonnes];
    T** tabMat1 = this->T2DLireContenu();
    
    for(unsigned int uiLigne = 0; uiLigne < uiNbLignes; uiLigne++){
        tabResult[uiLigne] = new T[uiNbColonnes];
        for(unsigned int uiColonne = 0; uiColonne < uiNbColonnes; uiColonne++){
            tabResult[uiLigne][uiColonne] = tabMat1[uiLigne][uiColonne]*dNombre;
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

template <class T>
Cmatrice<T> Cmatrice<T>:: operator/(double dNombre){
    //TODO
    return *this;
}

template <class T>
Cmatrice<T> operator*(double dNombre, Cmatrice<T> &MAT1){
    return MAT1*dNombre;
}


