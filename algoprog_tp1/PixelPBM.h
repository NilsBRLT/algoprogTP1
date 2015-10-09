//
//  PixelPBM.h
//  algoprog_tp1
//
//  Created by Nils Burlat on 08/10/2015.
//  Copyright (c) 2015 Porlat. All rights reserved.
//

#ifndef __algoprog_tp1__PixelPBM__
#define __algoprog_tp1__PixelPBM__

#include <stdio.h>
#include <string>
#include "Pixel.h"

using namespace std;

class PixelPBM : public Pixel {
public:
    PixelPBM(int valeur);
    ~PixelPBM();
    
    string getString();
    int getValeur();
    
private:
    int m_valeur;
    
};

#endif /* defined(__algoprog_tp1__PixelPBM__) */
