//
//  image.h
//  algoprog_tp1
//
//  Created by Pierre-Antoine Porte on 30/09/2015.
//  Copyright (c) 2015 Porlat. All rights reserved.
//

#ifndef __algoprog_tp1__image__
#define __algoprog_tp1__image__

#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>
#include <stdio.h>
#include "pixel.h"
#include "exceptionTP1.h"

using namespace std;

#define CODE_PPM "P3"
#define NB_COULEURS 255
#define TAILLE_MAX_LIGNE 70

class Image {
public:
    // Constructeur et destructeur
    Image();
    ~Image();
    
    // Méthodes utiles à la classe
    int read(string filepath) throw(ExceptionTP1);
    void generer(int largeur, int hauteur, int pourcentageNoir);
    void colorierImage(bool unionBonus);
    void write(string filepath) throw(ExceptionTP1);
    int writePixel(Pixel* pixel, ofstream& file, int lineSize) throw(ExceptionTP1);
    Pixel* findSet(Pixel* pixel);
    void makeSet(Pixel* pixel);
    
private:
    int m_largeur;
    int m_hauteur;
    vector<Pixel*> m_pixels;    
};

#endif /* defined(__algoprog_tp1__image__) */
