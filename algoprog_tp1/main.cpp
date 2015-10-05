//
//  main.cpp
//  algoprog_tp1
//
//  Created by Pierre-Antoine Porte on 30/09/2015.
//  Copyright (c) 2015 Porlat. All rights reserved.
//

// print the content of a text file.

#include "image.h"

#define IMAGE_IN_PA "/Users/portepa/development/algoprog_tp1/nils.pbm"
#define IMAGE_IN_NILS "/Users/Nils/Desktop/Bureau/Dev/C++/algoprogTP1/nils.pbm"
#define IMAGE_OUT_PA "/Users/portepa/development/algoprog_tp1/nils_out.pbm"
#define IMAGE_OUT_NILS "/Users/Nils/Desktop/Bureau/Dev/C++/algoprogTP1/nils_out.pbm"

int main () {
    Image image = Image();
    
    //image.read(IMAGE_IN_PA);
    image.read(IMAGE_IN_NILS);
    
    
    image.generer(5, 5);
    image.write(IMAGE_OUT_NILS);
    
    return 0;
}