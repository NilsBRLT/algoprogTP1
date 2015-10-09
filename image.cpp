//
//  tools.cpp
//  algoprog_tp1
//
//  Created by Pierre-Antoine Porte on 30/09/2015.
//  Copyright (c) 2015 Porlat. All rights reserved.
//

#include "image.h"

Image::Image() {
}

Image::~Image() {
}

int Image::read(string filepath) {
    
    std::ifstream ifs;
    // Doesn't work with relative path... Investigate later
    // This issue seems to be on Mac only.
    ifs.open (filepath, std::ifstream::in);
    
    if (ifs.is_open()) {
        srand(time_t(NULL));
        string ligne = "";
        int numeroLigne = 0;
        
        char c = ifs.get();
        while (ifs.good()) {
            ligne += c;
            if (c == '\n') {
                if (numeroLigne == 0) {
                    m_type = ligne;
                } else if (numeroLigne == 1) {
                    size_t pos = ligne.find(" ");
                    m_largeur = stoi(ligne.substr(0, pos));
                    m_hauteur = stoi(ligne.substr(pos));
                }
                numeroLigne++;
                ligne = "";
            }
            if ((c == '0' || c == '1') && numeroLigne >= 2) {
                Pixel pix = Pixel(rand() % 255, rand() % 255, rand() % 255);
                m_pixels.push_back(pix);

            }
            c = ifs.get();
        }
        
        // Début affichage pour test
        /*
        for (unsigned i=0; i < m_hauteur; i++) {
            for (unsigned j=0; j < m_largeur; j++) {
                cout << m_pixels[j+i*m_largeur].getString() << " ";
            }
            cout << '\n';
        }
        */
    }
    else {
        // show message:
        std::cout << "Error opening file";
    }
    
    ifs.close();
    
    return 0;
}


void Image::generer(int largeur, int hauteur) {
    m_largeur = largeur;
    m_hauteur = hauteur;
    m_type = CODE_PPM;
    
    m_pixels.clear();
    srand(time_t(NULL));
    
    for (int i=0; i<m_largeur*m_hauteur; i++) {
        int color = rand() % 2;
        Pixel pix = Pixel(color, color, color);
        m_pixels.push_back(pix);
    }
}

void Image::write(string filepath) {
    
    // Création d'un fichier (mode out)
    std::ofstream ofs;
    ofs.open (filepath, std::ofstream::out);
    
    if (ofs.is_open()) {
        // Préparation du type (P3) en char*
        char* type = (char*)malloc(m_type.size());
        strcpy(type, m_type.c_str());
        
        // Préparation du '\n' en char*
        char* retourLigne = (char*)malloc(1);
        string retourLigneString = "\n";
        strcpy(retourLigne, retourLigneString.c_str());
        
        // Préparation de l'espace ' ' en char*
        char* espace = (char*)malloc(1);
        string espaceString = " ";
        strcpy(espace, espaceString.c_str());
        
        // Préparation de la largeur et de la hauteur
        char* largeur = (char*)malloc(compteChiffresDansNombre(m_largeur));
        string largeurString = to_string(m_largeur);
        strcpy(largeur, largeurString.c_str());
        char* hauteur = (char*)malloc(compteChiffresDansNombre(m_hauteur));
        string hauteurString = to_string(m_hauteur);
        strcpy(hauteur, hauteurString.c_str());
        
        // Préparation du nombre de couleurs (NB_COULEURS)
        char* nbCouleurs = (char*)malloc(compteChiffresDansNombre(NB_COULEURS));
        string nbCouleursString = to_string(NB_COULEURS);
        strcpy(nbCouleurs, nbCouleursString.c_str());
        
        
        // ECRITURE DU HEADER DANS LE FICHIER
        ofs.write(type, sizeof(type));
        ofs.write(retourLigne, sizeof(retourLigne));
        ofs.write(largeur, sizeof(largeur));
        ofs.write(espace, sizeof(espace));
        ofs.write(hauteur, sizeof(hauteur));
        ofs.write(retourLigne, sizeof(retourLigne));
        ofs.write(nbCouleurs, sizeof(nbCouleurs));
        ofs.write(retourLigne, sizeof(retourLigne));
        
        // BOUCLE D'ECRITURE DES PIXELS
        
        for (int i = 0; i < m_pixels.size(); i++) {
            // Préparation de pixels
            string pixelString = m_pixels[i].getString();
            char* pixel = (char*)malloc(sizeof(pixelString));
            strcpy(pixel, pixelString.c_str());
            
            // Écriture
            ofs.write(pixel, sizeof(pixel));
            ofs.write(espace, sizeof(espace));
        }
        
        // FIN BOUCLE
        
        free(type);
        free(retourLigne);
        free(espace);
        free(largeur);
        free(hauteur);
        free(nbCouleurs);
    }
    else {
        // show message:
        std::cout << "Error creating file";
    }
    
    ofs.close();
}

Maillon* Image::findSet(Pixel pixel) {
    for (int i=0; i<m_sets.size(); i++) {
        
        for (Maillon* maillon = m_sets[i]; maillon->getSuivant() != nullptr ; maillon->getSuivant()) {
            if (maillon->getPixel().getString() == pixel.getString()) {
                return maillon;
            }
        }
//        test purpose
        cout << m_sets[i]->getRepresentant() << " ";
    }
    return nullptr;
}

Maillon* Image::makeSet(Pixel* pixel) {
    return new Maillon(*pixel);
}

void Image::colorierImage() {
//    Boucler sur les pixels de l'image
//    pour créer l'ensemble de set et peupler m_sets
//    Unioner les sets blabla...
}

int Image::compteChiffresDansNombre(int nombre) {
    int nb_chiffres = 0;
    
    do {
        nb_chiffres++;
        nombre /= 10;
    } while (nombre != 0);
    return nb_chiffres;
}
