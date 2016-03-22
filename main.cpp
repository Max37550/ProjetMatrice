//
//  main.cpp
//  projetMatrice
//
//  Created by Arthur Crocquevieille on 20/03/2016.
//  Copyright © 2016 Arthur Crocquevieille. All rights reserved.
//

#include <iostream>
#include "Cmatrice.hpp"
int main(int argc, const char * argv[]) {
    int **tab = new int*[3];
    for(int i = 0;i<3;i++){
        tab[i] = new int[4];
        for(int j = 0;j<4;j++){
            tab[i][j] = j;
        }
    }
    Cmatrice<int> m1(3,4,tab);
    Cmatrice<int> m2(3,4,tab);
    (m1+m2).T2DAffichage();
    //m1->T2DAffichage();
    return 0;
}
