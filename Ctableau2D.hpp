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
    
    /** Constructeur par default d'un Ctableau2D
     * @param void
     * @exception none
     */
    Ctableau2D<T>();
    
    /** Constructeur de recopie d'un Ctableau2D
     * @param Ctableau2D<T>& la référence d'un Ctableau2D
     * @exception none
     */
    Ctableau2D<T>(Ctableau2D<T> &T2DTab);
    
    /** Constructeur d'un Ctableau2D
     * @param unsigned int le nombre de lignes, unsigned int le nombre de colonnes, le contenu
     * @exception none
     */
    Ctableau2D<T>(unsigned int nbLignes, unsigned int nbColonnes,T **pContenu);
    
    /** Destructeur d'un Ctableau2D
     * @param void
     * @exception none
     */
    ~Ctableau2D<T>();
    //Méthodes
    public :
    
    /** Accesseur en lecture du nombre de lignes d'un Ctableau2D
     * @param void
     * @returns unsigned int le nombre de lignes
     * @exception none
     */
    unsigned int T2DLireNbLignes(){return uiT2DNbLignes;}
    /** Accesseur en lecture du nombre de colonnes d'un Ctableau2D
     * @param void
     * @returns unsigned int le nombre de colonnes
     * @exception none
     */
    unsigned int T2DLireNbColonnes(){return uiT2DNbColonnes;}
    
    /** Accesseur en lecture du contenu d'un Ctableau2D
     * @param void
     * @returns tableau 2D générique
     * @exception none
     */
    T** T2DLireContenu(){return pT2DContenu;}
    
    /** Méthode d'affichage d'un Ctableau2D
     * @param void
     * @returns void
     * @exception none
     */
    void T2DAffichage();
    //Surcharge
    public :
    
    /** Surchage de l'opérateur =
     * @param Ctableau2D<T> & référence d'un Ctableau2D
     * @returns Ctableau2D<T>
     * @exception none
     */
    Ctableau2D<T> operator=(Ctableau2D<T> &T2DTab);
};

#include "Ctableau2D.cpp"
#endif /* Ctableau2D_hpp */
