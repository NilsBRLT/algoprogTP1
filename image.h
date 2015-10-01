//
//  image.h
//  algoprog_tp1
//
//  Created by Pierre-Antoine Porte on 30/09/2015.
//  Copyright (c) 2015 Porlat. All rights reserved.
//

#ifndef __algoprog_tp1__image__
#define __algoprog_tp1__image__

#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <vector>
using namespace std;

class Image {
public:
    Image();
    ~Image();
    int read(string filepath);
    void analyseLigne(string ligne, int position);
private:
    string type;
    int largeur;
    int hauteur;
    vector<int> pixels;
};

#include <stdio.h>

#endif /* defined(__algoprog_tp1__image__) */
