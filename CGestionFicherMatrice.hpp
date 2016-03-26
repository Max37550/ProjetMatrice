//
//  CGestionFicherMatrice.hpp
//  projetMatrice
//
//  Created by Arthur Crocquevieille on 25/03/2016.
//  Copyright © 2016 Arthur Crocquevieille. All rights reserved.
//

#ifndef CGestionFicherMatrice_hpp
#define CGestionFicherMatrice_hpp

#include <stdio.h>
#include "Cmatrice.hpp"
#include "Cexception.hpp"
#include <iostream>
#include <fstream>
class CGestionFichierMatrice {
    //Attributs
    //Constructeur
    public:
    CGestionFichierMatrice();
    static Cmatrice<double> GFMLireMatriceDansFichier(char * chemin);
};

Cmatrice<double> CGestionFichierMatrice::GFMLireMatriceDansFichier(char * chemin){
    std::ifstream f(chemin, std::ios::in);
    if(f){
        char ctype[1024];
        char ctemp = 'x';
        unsigned int uiNbLignes,uiNbColonnes;
        //Type matrice
        while(ctemp !='='){
            f.get(ctemp);
        }
        ctemp = 'x';
        f >> ctype;
        //NbLignes
        while(ctemp !='='){
            f.get(ctemp);
        }
        ctemp = 'x';
        f>> uiNbLignes;
        //NbColonnes
        while(ctemp !='='){
            f.get(ctemp);
        }
        ctemp = 'x';
        f>> uiNbColonnes;
        //Matrice
        while(ctemp !='['){
            f.get(ctemp);
        }
        double **dtab = (double**)malloc(uiNbLignes*sizeof(double*));
        for(unsigned int uiBoucle = 0;uiBoucle < uiNbLignes;uiBoucle++){
            dtab[uiBoucle] = (double*)malloc(uiNbColonnes*sizeof(double));
            for(unsigned int uiBoucle2 = 0;uiBoucle2 < uiNbColonnes;uiBoucle2++){
                f >> dtab[uiBoucle][uiBoucle2];
            }
        }
        //VERIFIER si c'est un double
        
        f.close();
        Cmatrice<double> m(uiNbLignes,uiNbColonnes,dtab);
        return m;
    }else{
        Cexception e(1);
        throw e;
    }
}

#endif /* CGestionFicherMatrice_hpp */
