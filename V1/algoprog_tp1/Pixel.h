//
//  Pixel.h
//  algoprog_tp1
//
//  Created by Nils Burlat on 08/10/2015.
//  Copyright (c) 2015 Porlat. All rights reserved.
//

#ifndef __algoprog_tp1__Pixel__
#define __algoprog_tp1__Pixel__

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class Pixel {
public:
    // Constructeurs et destructeur
    Pixel();
    Pixel(int rouge, int vert, int bleu);
    ~Pixel();
    
    // Accesseurs
    int getRouge();
    int getVert();
    int getBleu();
    Pixel* getRepresentant();
    Pixel* getSuivant();
    int getSetSize();    
    
    // Mutateurs
    void setRepresentant(Pixel* pixel);
    void setSuivant(Pixel* pixel);
    
    // Méthodes utiles à la classe
    bool nEstPasNoir();
    void unionChaines(Pixel* representant2);
    void incrementSize(int size);
    
private:
    int m_rouge;
    int m_vert;
    int m_bleu;
    Pixel* m_representant;
    Pixel* m_suivant;
    int m_setSize;
    
};

#endif /* defined(__algoprog_tp1__Pixel__) */
