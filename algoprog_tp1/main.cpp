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
    
    
    image.generer(5, 5);
    image.write(IMAGE_OUT_NILS);
    
    
    // PARTIE DE TESTS SUR LE POLYMORPHISME PIXEL
    /*
     Erreur à la compilation : PixelPBM ne redéfinit pas correctement la méthode getValeur.
     Je sais plus faire en C++... Faut réussir à override la méthode pour pouvoir faire un tableau de Pixel (classe mère)
     
     */
    
    Pixel pix = PixelPBM(0);
    cout << "J'ai donc : " << pix.getValeur();
    vector<Pixel> v;
    v.push_back(pix);
    
    return 0;
}