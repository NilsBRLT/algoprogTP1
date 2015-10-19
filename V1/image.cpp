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
            bufferLigne += c;
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
            if ((c == '0' || c == '1' ) && numeroLigne >= 2) {
                int val = 0;
                if (c == '0') {
                    val = NB_COULEURS; // Blanc
                }
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
        
        for (int i=0; i<m_largeur*m_hauteur; i++) {

                    int color = rand() % 2;
                    Pixel pix = Pixel(color, color, color);
                    m_pixels.push_back(pix);
        }
    }

void Image::write(string filepath) {
    // Création d'un fichier (mode out)
    ofstream ofs;
//    ofs.open (filepath, std::ofstream::out);
    
    ofs.open(filepath);
    if (ofs.is_open()) {
        
        // ECRITURE DU HEADER DANS LE FICHIER
        ofs << m_type;
        ofs << '\n';
        ofs << m_largeur;
        ofs << " ";
        ofs << m_hauteur;
        ofs << '\n';
        ofs << NB_COULEURS;
        ofs << '\n';
        
        // BOUCLE D'ECRITURE DES PIXELS
        int ligneSize = 0;
        for (int i = 0; i < m_pixels.size(); i++) {
            // Préparation de pixels
//            string pixelString = m_pixels[i].getString();
            string rouge = to_string(m_pixels[i].getRouge()) + " ";
            if ((ligneSize+rouge.size())/70 >= 1) {
                ligneSize = 0;
                ofs << '\n';
            }
            ofs << rouge;
            ligneSize+= rouge.size();
            string vert = to_string(m_pixels[i].getVert()) + " ";
            if ((ligneSize+vert.size())/70 >= 1) {
                ligneSize = 0;
                ofs << '\n';
            }
            ofs << vert;
            ligneSize+= vert.size();
            string bleu = to_string(m_pixels[i].getBleu()) + " ";
            if ((ligneSize+bleu.size())/70 >= 1) {
                ligneSize = 0;
                ofs << '\n';
            }
            ofs << bleu;
            ligneSize+= bleu.size();
        }
    
        // FIN BOUCLE
    }
    else {
        // show message:
        cout << "Error creating file";
    }
    
    ofs.close();
}

void Image::writeColor(Pixel pixel, ofstream file) {
    
}

Maillon* Image::findSet(Pixel* pixel) {
    for (int i = 0; i < m_sets.size(); i++) {
        
        Maillon* maillon = m_sets[i];
        do {
            if (maillon->getPixel()->estEgal(pixel)) {
                return maillon->getRepresentant();
            }
            maillon = maillon->getSuivant();
        } while(maillon != nullptr);
    }
    return nullptr;
}

Maillon* Image::makeSet(Pixel* pixel) {
    pixel->setCouleur(rand()%255, rand()%255, rand()%255);
    return new Maillon(pixel);
}

void Image::colorierImage() {

    m_type = CODE_PPM;
    
    // ETAPE 1 - Créer un ensemble pour chaque pixel blanc de l'image
    /*
    for (int i = 0; i < m_pixels.size(); i++) {
        if (m_pixels[i].nEstPasNoir()) {
            Maillon* maillon = makeSet(&m_pixels[i]);
            m_sets.push_back(maillon);
        }
    }
    */
    for (int i = 0; i < m_pixels.size(); i++) {
        if (m_pixels[i].nEstPasNoir()) {
            m_pixels[i].setCouleur(rand()%255, rand()%255, rand()%255);
            m_pixels[i].setRepresentant(&m_pixels[i]);
        }
    }
    
    // ETAPE 2 - Pour chaque pixel blanc, pour chacun de ses voisins blancs, si ils ne sont pas dans le même ensemble alors faire l'union
    for (int i = 0; i < m_pixels.size(); i++) {
        
        Pixel pix = m_pixels[i];
        if (pix.nEstPasNoir()) {
            
            // Voisin de droite
            if (pix.getColonne() < m_largeur - 1 && m_pixels[i+1].nEstPasNoir()) {
                //Maillon* m1 = findSet(&pix);
                //Maillon* m2 = findSet(&m_pixels[i+1]);
                
                Pixel* p1 = pix.getRepresentant();
                Pixel* p2 = m_pixels[i+1].getRepresentant();
                                
                if (p1 != p2) {
                    p1->unionChaines(p2);
                }
            }
            
            // Voisin du bas
            if (pix.getLigne() < m_hauteur - 1 && m_pixels[i+m_largeur].nEstPasNoir()) {
                Pixel* p1 = pix.getRepresentant();
                Pixel* p2 = m_pixels[i+m_largeur].getRepresentant();
                
                if (p1 != p2) {
                    p1->unionChaines(p2);
                }
            }
        }
    }
}









