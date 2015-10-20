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
        m_pixels.clear();
        string bufferLigne = "";
        int numeroLigne = 0;
        char c = ifs.get();
        
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
                Pixel* pix;
                if (c == '0') {
                    pix = new Pixel(rand()%NB_COULEURS, rand()%NB_COULEURS, rand()%NB_COULEURS);

                } else {
                    pix = new Pixel();
                }
                pix->setRepresentant(pix);
                m_pixels.push_back(pix);
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

void Image::generer(int largeur, int hauteur, int pourcentageNoir) {
    m_largeur = largeur;
    m_hauteur = hauteur;

    m_type = CODE_PPM;
    
    m_pixels.clear();
    
    for (int i=0; i<m_largeur*m_hauteur; i++) {
        int noir = rand() % 100;
        Pixel* pix;
        if (noir <= pourcentageNoir) {
            pix = new Pixel();
        } else {
            pix = new Pixel(rand()%NB_COULEURS, rand()%NB_COULEURS, rand()%NB_COULEURS);
        }
        
        
        pix->setRepresentant(pix);
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
            string rouge = to_string(m_pixels[i]->getRepresentant()->getRouge()) + " ";
            if ((ligneSize+rouge.size()) >= TAILLE_MAX_LIGNE) {
                ligneSize = 0;
                ofs << '\n';
            }
            ofs << rouge;
            ligneSize+= rouge.size();
            string vert = to_string(m_pixels[i]->getRepresentant()->getVert()) + " ";
            if ((ligneSize+vert.size()) >= TAILLE_MAX_LIGNE) {
                ligneSize = 0;
                ofs << '\n';
            }
            ofs << vert;
            ligneSize+= vert.size();
            string bleu = to_string(m_pixels[i]->getRepresentant()->getBleu()) + " ";
            if ((ligneSize+bleu.size()) >= TAILLE_MAX_LIGNE) {
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
//    for (int i = 0; i < m_pixels.size(); i++) {
//        if (m_pixels[i].nEstPasNoir()) {
//            m_pixels[i].setCouleur(rand()%NB_COULEURS, rand()%NB_COULEURS, rand()%NB_COULEURS);
//            m_pixels[i].setRepresentant(&m_pixels[i]);
//        }
//    }
//
    // ETAPE 2 - Pour chaque pixel blanc, pour chacun de ses voisins blancs, si ils ne sont pas dans le même ensemble alors faire l'union
    for (int i = 0; i < m_pixels.size(); i++) {
        
        Pixel* pix = m_pixels[i];
        if (pix->nEstPasNoir()) {
            
            // Voisin de droite
            if (i % m_largeur < m_largeur - 1 && m_pixels[i+1]->nEstPasNoir()) {
                //Maillon* m1 = findSet(&pix);
                //Maillon* m2 = findSet(&m_pixels[i+1]);
                
                Pixel* p1 = pix->getRepresentant();
                Pixel* p2 = m_pixels[i+1]->getRepresentant();
                                
                if (p1 != p2) {
                    p1->unionChaines(p2);
                }
            }
            
            // Voisin du bas
            if (i / m_largeur < m_hauteur - 1 && m_pixels[i+m_largeur]->nEstPasNoir()) {
                Pixel* p1 = pix->getRepresentant();
                Pixel* p2 = m_pixels[i+m_largeur]->getRepresentant();
                
                if (p1 != p2) {
                    p1->unionChaines(p2);
                }
            }
        }
    }
}









