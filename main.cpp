//
//  main.cpp
//  projetMatrice
//
//  Created by Arthur Crocquevieille on 20/03/2016.
//  Copyright © 2016 Arthur Crocquevieille. All rights reserved.
//

#include <iostream>
#include "Cmatrice.hpp"
#include "Cexception.hpp"
#include "CGestionFicherMatrice.hpp"

int main(int argc, const char * argv[]) {
    Cmatrice<double> m1(CGestionFichierMatrice::GFMLireMatriceDansFichier("/Users/arthurcrocquevieille/Documents/projetMatrice/projetMatrice/mat1.txt"));
    Cmatrice<double> m2(CGestionFichierMatrice::GFMLireMatriceDansFichier("/Users/arthurcrocquevieille/Documents/projetMatrice/projetMatrice/mat2.txt"));
    m1.T2DAffichage();
    std::cout << std::endl;
    m2.T2DAffichage();
    std::cout << std::endl;
    (m1 * m2).T2DAffichage();
    std::cout << std::endl;
    (m1 * 2).T2DAffichage();
    std::cout << std::endl;
    (2 * m1).T2DAffichage();
    return 0;
}
