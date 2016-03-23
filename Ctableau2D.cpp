//
//  Ctableau2D.cpp
//  projetMatrice
//
//  Created by Arthur Crocquevieille on 20/03/2016.
//  Copyright © 2016 Arthur Crocquevieille. All rights reserved.
//


#include "Ctableau2D.hpp"

/** Constructeur par default d'un Ctableau2D
 * @param void
 * @exception none
 */
template<class T>
Ctableau2D<T>::Ctableau2D(){
    uiT2DNbLignes = 0;
    uiT2DNbColonnes = 0;
    pT2DContenu = NULL;
}

/** Constructeur de recopie d'un Ctableau2D
 * @param Ctableau2D<T>& la référence d'un Ctableau2D
 * @exception none
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
/** Constructeur d'un Ctableau2D
 * @param unsigned int le nombre de lignes, unsigned int le nombre de colonnes, le contenu
 * @exception none
 */
template<class T>
Ctableau2D<T>::Ctableau2D(unsigned int nbLignes, unsigned int nbColonnes,T **pContenu){
    uiT2DNbLignes = nbLignes;
    uiT2DNbColonnes = nbColonnes;
    
    pT2DContenu = (T**)malloc(nbLignes*sizeof(T*));
    for(unsigned int uiLigne = 0; uiLigne < nbLignes; uiLigne++){
        pT2DContenu[uiLigne] = (T*)malloc(nbColonnes*sizeof(T));
        for(unsigned int uiColonne =0; uiColonne <= nbColonnes; uiColonne++){
            pT2DContenu[uiLigne][uiColonne] = pContenu[uiLigne][uiColonne];
        }
    }
}
/** Méthode d'affichage d'un Ctableau2D
 * @param void
 * @returns void
 * @exception none
 */
template<class T>
void Ctableau2D<T>::T2DAffichage(){
    for(int i = 0;i<uiT2DNbLignes;i++){
        for(int j = 0;j<uiT2DNbColonnes;j++){
            std::cout << pT2DContenu[i][j] << '\t';
        }
        std::cout <<std::endl;
    }
}
/** Surchage de l'opérateur =
 * @param Ctableau2D<T> & référence d'un Ctableau2D
 * @returns Ctableau2D<T>
 * @exception none
 */
template<class T>
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
/** Destructeur d'un Ctableau2D
 * @param void
 * @exception none
 */
template<class T>
Ctableau2D<T>::~Ctableau2D(){
    if(pT2DContenu!=NULL){
        for(unsigned int uiBoucle = 0; uiBoucle < uiT2DNbLignes;uiBoucle++)
            free(pT2DContenu[uiBoucle]);
        free(pT2DContenu);
    }
}
