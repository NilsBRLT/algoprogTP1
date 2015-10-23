//
//  main.cpp
//  algoprog_tp1
//
//  Created by Pierre-Antoine Porte on 30/09/2015.
//  Copyright (c) 2015 Porlat. All rights reserved.
//

// print the content of a text file.

#include "image.h"
#include "test.h"
#include <vector>
#include <time.h>
#include <string.h>

#define RANDOM "RANDOM"
#define UNION "BONUS"
#define TEST "test"


/**
 * Précise les cas d'utilisation du programme à l'utilisateur
 **/
void usageApplication() {
    cout << "Usage 1 (via fichier .pbm) : algoprog image_entrée image_sortie [BONUS]" << endl;
    cout << "Usage 2 (aléatoire) : algoprog RANDOM X L H image_sortie [BONUS] (avec X le pourcentage de pixel noir, compris entre 0 et 100 / L > 0 la largeur de l'image, H > 0 la hauteur de l'image )" << endl;
    cout << "L'ordre des paramètres ne peut être modifié." << endl;
}


/**
 * Fonction principale du programme
 **/
int main (int argc, char *argv[]) {
    
    if (argc >= 2) {
        if (strcmp(argv[1], TEST) == 0) {
            Test test = Test();
            test.run();
            return 0;
        }
    }
        
    string fichierEntree;
    string fichierSortie;
    int pourcentagePixelsNoirs = 0;
    int largeur = 0;
    int hauteur = 0;
    bool unionBonus = false;
    bool random = false;
    
    if (argc < 3) {
        // Il n'y a pas assez d'arguments pour traiter la demande
        usageApplication();
        return 0;
    } else {
        // Il y a assez d'arguments
        try {
        
            // On vérifie la demande d'union bonus
            if (strcmp(argv[argc-1], UNION) == 0) {
                unionBonus = true;
            }
            
            if (strcmp(argv[1], RANDOM) == 0) {
                // Si le mode RANDOM est demandé
                random = true;
                
                // On vérifie le nombre d'arguments dans le cas de l'union
                if (argc < 6) {
                    usageApplication();
                    return 0;
                }
                
                // On récupère le pourcentage de pixels noirs demandé
                pourcentagePixelsNoirs = stoi(argv[2]);
                
                // On récupère la largeur de l'image
                largeur = stoi(argv[3]);
                
                // On récupère la hauteur
                hauteur = stoi(argv[4]);
                
                if (hauteur < 0 || largeur < 0 || pourcentagePixelsNoirs < 0 || pourcentagePixelsNoirs > 100) {
                    usageApplication();
                    return 0;
                }
                
                // On lit le nom du fichier de sortie
                fichierSortie = argv[5];
                
            } else {
                // Si le mode RANDOM n'est pas demandé
                
                // On lit le nom du fichier d'entrée
                fichierEntree = argv[1];
                
                // On lit le nom du fichier de sortie
                fichierSortie = argv[2];
            }
        } catch (exception e) {
            usageApplication();
            return 0;
        }
    }
    
    // Informations pour l'utilisateur
    if (random) {
        cout << "Génération d'une image aléatoire." << endl;
    } else {
        cout << "Génération à partir d'une image existante." << endl;
    }
    if (unionBonus) {
        cout << "Traitement avec union bonus." << endl;
    } else {
        cout << "Traitement avec union classique." << endl;
    }
        
    Image image = Image();
    
    // Récupération du nombre inital de clocks
    long int debut = clock();
    
    try {
        
        if (random) {
            // Génération de l'image...
            image.generer(largeur, hauteur, pourcentagePixelsNoirs);
        } else {
            // ... ou lecture de l'image
            image.read(fichierEntree);
        }

        // Coloriage de l'image
        image.colorierImage(unionBonus);

        // Ecriture de l'image
        image.write(fichierSortie);

        // Récupération du nombre final de clocks
        long int fin = clock();

        // Affichage du temps du traitement
        cout << "Traitement terminé en " << (fin-debut)/CLOCKS_PER_SEC << " secondes et " << ((fin-debut)%CLOCKS_PER_SEC)/1000 << " millisecondes." << endl << endl;
        
    } catch (ExceptionTP1 const& e) {
        cout << "Erreur : " << e.what() << endl << endl;
    }
    catch (exception const& e) {
        cout << "Erreur non traitée : " << e.what() << endl << endl;
    }
    
    return 0;
}
