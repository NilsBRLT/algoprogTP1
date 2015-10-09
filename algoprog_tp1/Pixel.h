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
#include <string>

using namespace std;

class Pixel {
public:
    Pixel();
    Pixel(int rouge, int vert, int bleu);
    ~Pixel();
    
    string getString() const;
    int getRouge();
    int getVert();
    int getBleu();
    
private:
    int m_rouge;
    int m_vert;
    int m_bleu;
    
};

#endif /* defined(__algoprog_tp1__Pixel__) */
