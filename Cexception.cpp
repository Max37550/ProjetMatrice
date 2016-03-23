//
//  Cexception.cpp
//  projetMatrice
//
//  Created by Arthur Crocquevieille on 20/03/2016.
//  Copyright © 2016 Arthur Crocquevieille. All rights reserved.
//

#include "Cexception.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/** Constructeur par defaut la classe Cexception
 * @param void
 * @exception none
 */
Cexception::Cexception(){
    uiEXCCode = 0;
   pcEXCDescription = NULL;
}

/** Constructeur de la Cexception permettant de spécifier un code d'erreur et une description
 * @param unsigned int le code d'erreur, char * la description
 * @exception none
 */
Cexception::Cexception(unsigned int uiCode, char *pcDescription){
    uiEXCCode = uiCode;
    if(pcDescription == NULL)
        pcEXCDescription = NULL;
    else
        {
            pcEXCDescription = (char *) malloc(1000);
            if(pcEXCDescription!=NULL)
                strcpy(pcEXCDescription, pcDescription);
            else
                exit(-1);
        }
}

/**Desctructeur par defaut de la classe Cexception, il libère la place mémoire prise par la description
 * @param void
 * @exception none
 */
Cexception::~Cexception(){
    if(pcEXCDescription!=NULL)
        free(pcEXCDescription);
}