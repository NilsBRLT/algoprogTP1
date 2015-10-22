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

int Image::read(string filepath) throw(ExceptionTP1) {
    // Ouverture du fichier .pbm
    std::ifstream ifs;
    ifs.open (filepath, ifstream::in);
    
    // Initialisation de l'aléatoire
    // time(NULL) renvoie le nb de secondes depuis le 1/01/1970, ce qui change à chaque run, et nous prenons ainsi un nouveau seed de random
    srand((unsigned int) time(NULL));
    
    if (ifs.is_open()) {
        
        try {
            // Initialisation des variables utiles à la lecture du fichier
            m_pixels.clear();
            string bufferLigne = "";
            int numeroLigne = 0;
            char c = ifs.get();
            
            while (ifs.good()) {
                bufferLigne += c;
                
                // Lecture du header (largeur et hauteur notamment)
                if (c == '\n') {
                    if (numeroLigne == 1) {
                        size_t pos = bufferLigne.find(" ");
                        m_largeur = stoi(bufferLigne.substr(0, pos));
                        m_hauteur = stoi(bufferLigne.substr(pos));
                    }
                    numeroLigne++;
                    bufferLigne = "";
                }
                
                // Lecture des pixels de l'image
                if ((c == '0' || c == '1' ) && numeroLigne >= 2) {
                    Pixel* pix;
                    if (c == '0') {
                        // Création d'un pointeur sur Pixel coloré aléatoirement si le pixel était blanc
                        pix = new Pixel(rand()%NB_COULEURS, rand()%NB_COULEURS, rand()%NB_COULEURS);

                    } else {
                        // Création d'un pointeur sur Pixel noir si le pixel était noir
                        pix = new Pixel();
                    }
                    
                    // Le pixel est son propre représentant au début de l'algorithme ; il est donc le seul de son ensemble
                    makeSet(pix);
                } else if (c != '0' && c != '1' && c != ' ' && c != '\n' && numeroLigne >= 2) {
                    throw ExceptionTP1(ERREUR_FORMAT);
                }
                c = ifs.get();
            }
        } catch (exception e) {
            throw ExceptionTP1(ERREUR_FORMAT);
        }
    }
    else {
        throw ExceptionTP1(ERREUR_LECTURE);
    }
    
    // Fermeture du fichier .pbm
    ifs.close();
    return 0;
}

void Image::generer(int largeur, int hauteur, int pourcentageNoir) {
    // Initialisation des attributs de this
    m_largeur = largeur;
    m_hauteur = hauteur;
    m_pixels.clear();
    
    for (int i=0; i<m_largeur*m_hauteur; i++) {
        int noir = rand() % 100;
        Pixel* pix;
        if (noir <= pourcentageNoir) {
            // Si la variable aléatoire est comprise dans le pourcentage de pixels noirs, on crée un *Pixel noir
            pix = new Pixel();
        } else {
            // Sinon, on crée un *Pixel coloré aléatoirement
            pix = new Pixel(rand()%NB_COULEURS, rand()%NB_COULEURS, rand()%NB_COULEURS);
        }
        
        // Le pixel est son propre représentant au début de l'algorithme ; on l'ajoute au tableau de *Pixels
        makeSet(pix);
        m_pixels.push_back(pix);
    }
}

void Image::write(string filepath) throw(ExceptionTP1) {
    
    // Création d'un fichier (mode out)
    ofstream ofs;
    ofs.open(filepath);
    
    if (ofs.is_open()) {
        
        // Ecriture du header
        ofs << CODE_PPM;
        ofs << '\n';
        ofs << m_largeur;
        ofs << " ";
        ofs << m_hauteur;
        ofs << '\n';
        ofs << NB_COULEURS;
        ofs << '\n';
        
        // Boucle d'écriture des pixels
        int lineSize = 0;
        for (int i = 0; i < m_pixels.size(); i++) {
            lineSize = writePixel(m_pixels[i], ofs, lineSize);
        }
    
    }
    else {
        throw ExceptionTP1(ERREUR_ECRITURE);
    }
    
    ofs.close();
}

int Image::writePixel(Pixel* pixel, ofstream& file, int lineSize) throw(ExceptionTP1) {
    try {
        // Ecriture de la composante rouge
        string rouge = to_string(pixel->getRepresentant()->getRouge()) + " ";
        if ((lineSize+rouge.size()) >= TAILLE_MAX_LIGNE) {
            lineSize = 0;
            file << '\n';
        }
        lineSize += rouge.size();
        file << rouge;
                
        // Ecriture de la composante verte
        string vert = to_string(pixel->getRepresentant()->getVert()) + " ";
        if ((lineSize+vert.size()) >= TAILLE_MAX_LIGNE) {
            lineSize = 0;
            file << '\n';
        }
        lineSize += vert.size();
        file << vert;
        
        // Ecriture de la composante bleue
        string bleu = to_string(pixel->getRepresentant()->getBleu()) + " ";
        if ((lineSize+bleu.size()) >= TAILLE_MAX_LIGNE) {
            lineSize = 0;
            file << '\n';
        }
        lineSize += bleu.size();
        file << bleu;
            
        return lineSize;
    } catch (exception e) {
        throw ExceptionTP1(ERREUR_DATA);
    }
}

void Image::colorierImage(bool unionBonus) {
    // Pour chaque pixel blanc, pour chacun de ses voisins blancs, si ils ne sont pas dans le même ensemble alors faire l'union
    // On a finalement besoin de traiter uniquement les pixels à droite et en bas du pixel courant
    
    for (int i = 0; i < m_pixels.size(); i++) {
        Pixel* pix = m_pixels[i];
        if (pix->nEstPasNoir()) {
            // On ne traite le pixel que s'il n'est pas noir
            
            // Voisin de droite
            if (i % m_largeur < m_largeur - 1 && m_pixels[i+1]->nEstPasNoir()) {
                Pixel* p1 = findSet(pix);
                Pixel* p2 = findSet(m_pixels[i+1]);
                                
                if (p1 != p2) {
                    // On fusionne les ensembles si les représentants des deux ensembles ne sont pas les mêmes
                    if (unionBonus) {
                        // Union de la question BONUS
                        p1->unionBonus(p2);
                    } else {
                        // Union avec pointeur vers queue
                        p1->unionClassique(p2);
                    }
                }
            }
            
            // Voisin du bas
            if (i / m_largeur < m_hauteur - 1 && m_pixels[i+m_largeur]->nEstPasNoir()) {
                Pixel* p1 = findSet(pix);
                Pixel* p2 = findSet(m_pixels[i+m_largeur]);
                
                if (p1 != p2) {
                    // On fusionne les ensembles si les représentants des deux ensembles ne sont pas les mêmes
                    if (unionBonus) {
                        // Union de la question BONUS
                        p1->unionBonus(p2);
                    } else {
                        // Union avec pointeur vers queue
                        p1->unionClassique(p2);
                    }
                }
            }
        }
    }
}

Pixel* Image::findSet(Pixel *pixel) {
    return pixel->getRepresentant();
}

void Image::makeSet(Pixel *pixel) {
    pixel->setRepresentant(pixel);
    pixel->setSuivant(nullptr);
    pixel->setQueue(pixel);
    m_pixels.push_back(pixel);
}





