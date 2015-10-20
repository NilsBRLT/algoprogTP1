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
#include <time.h>       /* time_t, struct tm, difftime, time, mktime */

#define IMAGE_IN_PA "/Users/portepa/development/algoprog_tp1/V1/carte_france.pbm"
#define IMAGE_IN_NILS "/Users/Nils/Desktop/Bureau/Dev/C++/algoprogTP1/V1/carte_france.pbm"
#define IMAGE_OUT_PA "/Users/portepa/development/algoprog_tp1/V1/carte_france_out_new.ppm"
#define IMAGE_OUT_NILS "/Users/Nils/Desktop/Bureau/Dev/C++/algoprogTP1/V1/carte_france_out.ppm"

int main () {
    srand(time_t(NULL));
    
    long int debut = clock();
        
    Image image = Image();
    
    //image.read(IMAGE_IN_NILS);
//    image.read(IMAGE_IN_PA);
    image.generer(1600, 1600, 40);
    
    image.colorierImage();
    
    image.write(IMAGE_OUT_NILS);
//    image.write(IMAGE_OUT_PA);
    
    long int fin = clock();
    
    cout << "Traitement terminé en " << (fin-debut)/CLOCKS_PER_SEC << " secondes et " << ((fin-debut)%CLOCKS_PER_SEC)/1000 << " millisecondes." << endl;
    
    return 0;
}