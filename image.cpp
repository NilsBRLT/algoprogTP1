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
    ifs.open (filepath, ifstream::in);
    
    if (ifs.is_open()) {
//        srand(time_t(NULL));
        string bufferLigne = "";
        int numeroLigne = 0;
        
        char c = ifs.get();
        int ligne = 0;
        int colonne = 0;
        
        while (ifs.good()) {
            ligne += c;
            if (c == '\n') {
                if (numeroLigne == 0) {
                    m_type = bufferLigne;
                } else if (numeroLigne == 1) {
                    size_t pos = bufferLigne.find(" ");
                    m_largeur = stoi(bufferLigne.substr(0, pos));
                    m_hauteur = stoi(bufferLigne.substr(pos));
                }
                numeroLigne++;
                bufferLigne = "";
            }
            if ((c == '0' || c == '1') && numeroLigne >= 2) {
                int val = (int) c - '0';
                val = val*NB_COULEURS; // Gérer la couleur noir
                Pixel pix = Pixel(val, val, val);
                pix.setColonne(colonne);
                pix.setLigne(ligne);
                m_pixels.push_back(pix);
                colonne++;
                if (colonne >= m_largeur) {
                    colonne = 0;
                    ligne++;
                }
            }
            c = ifs.get();
        }
        cout << '\n';
        
        // Début affichage pour test
        
        for (unsigned i=0; i < m_hauteur; i++) {
            for (unsigned j=0; j < m_largeur; j++) {
                cout << m_pixels[j+i*m_largeur].getString() << " ";
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
            cout << pixelString << " ";
            char* pixel = (char*)malloc(sizeof(pixelString));
            strcpy(pixel, pixelString.c_str());
            
            // Espace si (i % 5) == 0
            if (i % 5 == 0 && i != 0) {
                ofs.write(retourLigne, sizeof(retourLigne));
            }
            
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

Maillon* Image::makeSet(Pixel pixel) {
    return new Maillon(pixel);
}

void Image::unionSet(Maillon* representant1, Maillon* representant2) {
    
//    if (representant1.getRepresentant()->getPixel() == reprensentant2.getRepresentant()->getPixel()) {
//        // Ensemble non disjoint
//        // Throw error (précond)
//    }
//    if (representant1.getRepresentant()->getPixel() != representant1.getPixel()
//        || representant2.getRepresentant()->getPixel() != representant2.getPixel()) {
//        // Reprensentants ne sont pas représentant (au moins un des deux
//        // Throw error ou prendre son représentant ?
//    }

    Maillon* elemS1 = new Maillon(representant1);
    Maillon* elemS2 = new Maillon(representant2);

    // On veut prendre le dernier de la liste pour lui ajouter les suivants
    while (elemS1->getSuivant() != nullptr) {
        elemS1 = elemS1->getSuivant();
    }
    elemS1->setSuivant(elemS2);
    while (elemS2->getSuivant() != nullptr) {
        elemS2->setRepresentant(representant1);
        elemS2->setPixel(representant1->getPixel());
        elemS2 = representant2->getSuivant();
    }
}

void Image::colorierImage() {
//    Boucler sur les pixels de l'image
//    pour créer l'ensemble de set et peupler m_sets
//    Unioner les sets blabla...
//    for (int l=0; l<m_largeur; l++) {
//        for (int h = 0; h<m_hauteur; h++) {
//            if (m_pixels)
//            Maillon* maillon = makeSet(m_pixels[l+h*m_largeur]);
//            m_sets.push_back(maillon);
//        }
//
    for (int i = 0; i < m_pixels.size(); i++) {
        Maillon* maillon = makeSet(m_pixels[i]);
        m_sets.push_back(maillon);
    }
    for (int i = 0; i < m_sets.size(); i++) {
        Maillon set = m_sets[i];
        if (set.getPixel().isBlanc()) {
            // gauche
            if (m_pixels[set.getPixel().getColonne() + set.getPixel().getLigne()*m_largeur-1]) {
                
            }
        }
    }
}

int Image::compteChiffresDansNombre(int nombre) {
    int nb_chiffres = 0;
    
    do {
        nb_chiffres++;
        nombre /= 10;
    } while (nombre != 0);
    return nb_chiffres;
}
