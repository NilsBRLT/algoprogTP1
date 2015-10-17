//
//  main.cpp
//  algoprog_tp1
//
//  Created by Pierre-Antoine Porte on 30/09/2015.
//  Copyright (c) 2015 Porlat. All rights reserved.
//

// print the content of a text file.

#include "image.h"
#include "Pixel.h"
#include <vector>

#define IMAGE_IN_PA "/Users/portepa/development/algoprog_tp1/nils.pbm"
#define IMAGE_IN_NILS "/Users/Nils/Desktop/Bureau/Dev/C++/algoprogTP1/V1/biang.pbm"
#define IMAGE_OUT_PA "/Users/portepa/development/algoprog_tp1/nils_out.ppm"
#define IMAGE_OUT_NILS "/Users/Nils/Desktop/Bureau/Dev/C++/algoprogTP1/V1/biang.ppm"

int main () {
    
    // FAKE FAKE FAKE ANDY DIS MOI OUI AICHA ECOUTE MOI BWAALALALALALALLALALALAAH

    srand(time_t(NULL));
        
    Image image = Image();
    
        
    image.read(IMAGE_IN_NILS);
//    image.read(IMAGE_IN_PA);
    
    image.colorierImage();
    //image.testerUnion();
    
//    image.generer(5, 5);
    image.write(IMAGE_OUT_NILS);
//    image.write(IMAGE_OUT_PA);
    
    
    return 0;
}