//
//  Cexception.hpp
//  projetMatrice
//
//  Created by Arthur Crocquevieille on 20/03/2016.
//  Copyright © 2016 Arthur Crocquevieille. All rights reserved.
//

#ifndef Cexception_hpp
#define Cexception_hpp

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
class Cexception{
    private :
    //Attributs
    unsigned int uiEXCCode;
    char *pcEXCDescription;
    //Constructeurs et destructeur
    public :
    
    /** Constructeur par defaut la classe Cexception
     * @param void
     * @exception none
     */
    Cexception();
    
    /** Constructeur de la Cexception permettant de spécifier un code d'erreur et une description
     * @param unsigned int le code d'erreur, char * la description
     * @exception none
     */
    Cexception(unsigned int uiCode, char *pcDescription);
    
    /**Desctructeur par defaut de la classe Cexception, il libère la place mémoire prise par la description
     * @param void
     * @exception none
     */
    ~Cexception();
    public :
    //Attributs
    
    /** Accesseur en lecture de la description
     * @param void
     * @returns char *
     * @exception none
     */
    char *EXCLireDescription(){return pcEXCDescription;}
    
    /** Accesseur en lecture de la description
     * @param char * la nouvelle description
     * @returns void
     * @exception void
     */
    void EXCModifierDescription(char *pcNouvelleDescription){
        //SI non null
        if(pcEXCDescription!=NULL)
            free(pcEXCDescription);
        pcEXCDescription = (char *)malloc(1000);
        if(pcEXCDescription!=NULL)
            strcpy(pcEXCDescription, pcNouvelleDescription);
        else
            exit(-1);
    }
    
    /** Accesseur en lecture du code d'erreur
     * @param void
     * @returns unsigned int
     * @exception none
     */
    unsigned int EXCLireCode(){return uiEXCCode;}
    
    /** Accesseur en écriture u code d'erreur
     * @param unsigned int le nouveau code d'erreur
     * @returns void
     * @exception none
     */
    void EXCModifierCode(unsigned int uiNouveauCode){uiEXCCode  = uiNouveauCode;}
    
};

#endif /* Cexception_hpp */
