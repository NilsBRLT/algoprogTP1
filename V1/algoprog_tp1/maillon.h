//
//  maillon.h
//  algoprog_tp1
//
//  Created by Nils Burlat on 01/10/2015.
//  Copyright (c) 2015 Porlat. All rights reserved.
//

#ifndef __algoprog_tp1__Maillon__
#define __algoprog_tp1__Maillon__

#include <stdio.h>
#include <iostream>
#include "Pixel.h"

class Maillon {
    
private:
    Pixel* m_pixel;
    Maillon* m_suivant;
    Maillon* m_representant;
public:
    Maillon();
    Maillon(Maillon* maillon);
    Maillon(Pixel* pixel);
    Maillon(Pixel* pixel, Maillon* suivant, Maillon* representant);
    ~Maillon();
    
    void setPixel(Pixel* pixel);
    void setSuivant(Maillon* suivant);
    void setRepresentant(Maillon* representant);

    bool sameEnsemble(Maillon* maillon);
    void unionSet(Maillon* reprensentant2);
    
    void afficher();

    Pixel* getPixel();
    Maillon* getSuivant();
    Maillon* getRepresentant();
};

#endif /* defined(__algoprog_tp1__Maillon__) */
