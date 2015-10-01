//
//  maillon.h
//  algoprog_tp1
//
//  Created by Nils Burlat on 01/10/2015.
//  Copyright (c) 2015 Porlat. All rights reserved.
//

#ifndef __algoprog_tp1__maillon__
#define __algoprog_tp1__maillon__

#include <stdio.h>


#define INDICE_ROUGE 0
#define INDICE_VERT 1
#define INDICE_BLEU 2

class Maillon {
    
private:
    int m_pixel[3];
    Maillon* m_suivant;
    Maillon* m_representant;
public:
    Maillon();
    Maillon(int pixel[3]);
    Maillon(int pixel[3], Maillon* suivant, Maillon* representant);
    ~Maillon();
    
    void setPixel(int rouge, int vert, int bleu);
    void setSuivant(Maillon* suivant);
    void setRepresentant(Maillon* representant);
    
    int* getPixel();
    Maillon* getSuivant();
    Maillon* getRepresentant();
};

#endif /* defined(__algoprog_tp1__maillon__) */
