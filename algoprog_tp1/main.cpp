//
//  main.cpp
//  algoprog_tp1
//
//  Created by Pierre-Antoine Porte on 30/09/2015.
//  Copyright (c) 2015 Porlat. All rights reserved.
//

// print the content of a text file.

#include "image.h"
#include "PixelPBM.h"
#include "PixelPPM.h"
#include "Pixel.h"
#include <vector>

#define IMAGE_IN_PA "/Users/portepa/development/algoprog_tp1/nils.pbm"
#define IMAGE_IN_NILS "/Users/Nils/Desktop/Bureau/Dev/C++/algoprogTP1/nils.pbm"
#define IMAGE_OUT_PA "/Users/portepa/development/algoprog_tp1/nils_out.pbm"
#define IMAGE_OUT_NILS "/Users/Nils/Desktop/Bureau/Dev/C++/algoprogTP1/nils_out.pbm"

int main () {
    Image image = Image();
    
    //image.read(IMAGE_IN_PA);
    image.read(IMAGE_IN_NILS);
    
    
    image.generer(2, 2);
    image.write(IMAGE_OUT_NILS);
    
    
    
    // TESTS DES CLASSES DE PIXELS
    
    PixelPBM pix = PixelPBM(0);
    PixelPPM pix2 = PixelPPM(0,0,0);
    cout << "J'ai donc : " << pix.getString() << endl;
    cout << "J'ai donc : " << pix2.getString() << endl;
    vector<Pixel> v;
    v.push_back(pix);
    v.push_back(pix2);
    
    return 0;
}