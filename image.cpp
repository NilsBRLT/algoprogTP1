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
        string ligne = "";
        int positionFichierLigne = 0;
        
        char c = ifs.get();
        while (ifs.good()) {
            ligne += c;
            if (c == '\n') {
                analyseLigne(ligne, positionFichierLigne);
                positionFichierLigne++;
                ligne = "";
            }
            c = ifs.get();
        }
        
        // Début affichage pour test
        for (unsigned i=0; i < m_hauteur; i++) {
            for (unsigned j=0; j < m_largeur; j++) {
                cout << m_pixels[j+i*m_largeur] << " ";
            }
            cout << '\n';
        }
    }
    else {
        // show message:
        std::cout << "Error opening file";
    }
    
    ifs.close();
    
    return 0;
}

void Image::analyseLigne(string ligne, int position) {
    if (position == 0) {
        m_type = ligne;
        return;
    } else if (position == 1) {
        size_t pos = ligne.find(" ");
        m_largeur = stoi(ligne.substr(0, pos));
        m_hauteur = stoi(ligne.substr(pos));
        return;
    } else {
        for (unsigned int i = 0; i < ligne.length(); i++) {
            char c = ligne[i];
            if (c == '0' || c == '1')
                m_pixels.push_back(ligne[i] - '0');
        }
    }
}

void Image::generer(int largeur, int hauteur) {
    m_largeur = largeur;
    m_hauteur = hauteur;
    m_type = CODE_PPM;
    
    m_pixels.clear();
    srand(time_t(NULL));
    
    for (int i=0; i<m_largeur*m_hauteur; i++) {
        // Création d'un chiffre aléatoire (0 ou 1)
        m_pixels.push_back(rand() % 2);
    }
}

