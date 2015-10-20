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
#include <time.h>

#define IMAGE_IN_PA "/Users/portepa/development/algoprog_tp1/V1/carte_france.pbm"
#define IMAGE_IN_NILS "/Users/Nils/Desktop/Bureau/Dev/C++/algoprogTP1/V1/carte_france.pbm"
#define IMAGE_OUT_PA "/Users/portepa/development/algoprog_tp1/V1/carte_france_out_new.ppm"
#define IMAGE_OUT_NILS "/Users/Nils/Desktop/Bureau/Dev/C++/algoprogTP1/V1/carte_france_out_new.ppm"

int main () {
    // Initialisation de l'aléatoire
    srand(time_t(NULL));
    
        
    Image image = Image();
    
    // Récupération du nombre inital de clocks
    long int debut = clock();
    
    // Lecture de l'image...
    image.read(IMAGE_IN_NILS);
//    image.read(IMAGE_IN_PA);
    
    // ... ou génération de l'image
    //image.generer(1600, 1600, 40);
    
    // Coloriage de l'image
    image.colorierImage();
    
    // Ecriture de l'image
    image.write(IMAGE_OUT_NILS);
//    image.write(IMAGE_OUT_PA);
    
    // Récupération du nombre final de clocks
    long int fin = clock();
    
    // Affichage du temps du traitement
    cout << "Traitement terminé en " << (fin-debut)/CLOCKS_PER_SEC << " secondes et " << ((fin-debut)%CLOCKS_PER_SEC)/1000 << " millisecondes." << endl;
    
    return 0;
}