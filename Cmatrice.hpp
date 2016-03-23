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
    
    /** Constructeur par default d'une Cmatrice
     * @param void
     * @exception none
     */
    Cmatrice<T>();
    
    /** Constructeur de recopie d'une Cmatrice
     * @param Cmatrice<T> & la référence d'une Cmatrice
     * @exception none
     */
    Cmatrice<T>(Cmatrice<T> &&MATmatrice);
    
    /** Constructeur d'une Cmatrice
     * @param unsigned int le nombre de lignes, unsgined int le nombre de colonnes, un tableau 2D
     * @exception none
     */
    Cmatrice<T>(unsigned int uiNbLignes, unsigned int uiNbColonnes, T **pContenu);
    
    /** Destructeur de la Cmatrice
     * @param void
     * @exception none
     */
    ~Cmatrice<T>();
    //Methodes
    public :
    
    /** Méthode pour obtenir la transposée d'une Cmatrice
     * @param void
     * @returns Cmatrice<T> la transposée
     * @exception none
     */
    Cmatrice<T> MATTranspose();
    //Surcharges
    
    /**Surcharge de l'opérateur +
     * @param Cmatrice<T> ...
     * @returns Cmatrice<T>
     * @exception Les matrices doivent avoir les mêmes dimensions
     */
    Cmatrice<T> operator+(Cmatrice<T> &MAT1);
    /**Surcharge de l'opérateur -
     * @param Cmatrice<T> ...
     * @returns Cmatrice<T>
     * @exception Les matrices doivent avoir les mêmes dimensions
     */
    Cmatrice<T> operator-(Cmatrice<T> &MAT1);
    
    /** Surcharge de l'opérateur *
     * @param double la valeur par laquelle on va multiplier la Cmatrice
     * @returns Cmatrice<T>
     * @exception none
     */
    Cmatrice<T> operator*(double dValeur);
    
    /** Surcharge de l'opérateur *
     * @param Cmatrice<T> & la référence d'un Cmatrice
     * @returns Cmatrice<T>
     * @exception none
     */
    Cmatrice<T> operator*(Cmatrice<T> &MAT1);
    
    /** Surcharge de l'opérateur /
     * @param double la vleur par laquelle on va diviser la Cmatrice
     * @returns Cmatrice<T>
     * @exception valeur doit être > 0 
     */
    Cmatrice<T> operator/(double dNombre);
};
#include "Cmatrice.cpp"
#endif /* Cmatrice_hpp */

