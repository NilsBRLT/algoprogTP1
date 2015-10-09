//
//  PixelPPM.h
//  algoprog_tp1
//
//  Created by Nils Burlat on 09/10/2015.
//  Copyright (c) 2015 Porlat. All rights reserved.
//

#ifndef __algoprog_tp1__PixelPPM__
#define __algoprog_tp1__PixelPPM__

#include <stdio.h>
#include "string.h"
#include <stdlib.h>
#include "Pixel.h"
#include "PixelPBM.h"

using namespace std;

class PixelPPM : public Pixel {
public:
    PixelPPM(int rouge, int vert, int bleu);
    ~PixelPPM();
    
    string getString() const;
    int getRouge();
    int getVert();
    int getBleu();
    
private:
    int m_rouge;
    int m_vert;
    int m_bleu;
    
};

bool operator== (PixelPPM const &pix1, PixelPPM const &pix2)
{
    return pix1.getString() == pix2.getString();
}

#endif /* defined(__algoprog_tp1__PixelPPM__) */
