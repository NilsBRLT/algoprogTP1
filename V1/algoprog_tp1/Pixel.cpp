//
//  Pixel.cpp
//  algoprog_tp1
//
//  Created by Nils Burlat on 08/10/2015.
//  Copyright (c) 2015 Porlat. All rights reserved.
//

#include "Pixel.h"


Pixel::Pixel() {
    m_setSize = 0;
    m_rouge = 0;
    m_vert = 0;
    m_bleu = 0;
}

Pixel::Pixel(int rouge, int vert, int bleu) {
    m_rouge = rouge;
    m_vert = vert;
    m_bleu = bleu;
    m_setSize = 1;
}

Pixel::~Pixel() {
    
}

bool Pixel::nEstPasNoir() {
    return m_rouge != 0 || m_vert != 0 || m_bleu != 0;
}

int Pixel::getRouge() {
    return m_rouge;
}

int Pixel::getVert() {
    return m_vert;
}

int Pixel::getBleu() {
    return m_bleu;
}

void Pixel::setRepresentant(Pixel *pixel) {
    m_representant = pixel;
}

Pixel* Pixel::getRepresentant() {
    return m_representant;
}

void Pixel::setSuivant(Pixel *pixel) {
    m_suivant = pixel;
}

Pixel* Pixel::getSuivant() {
    return m_suivant;
}

void Pixel::unionChaines(Pixel* representant2) {
    // Soient this le représentant du set S1 et representant2 celui du set S2
    
    if (representant2->getSetSize() > this->getSetSize()) {
        // taille(S2) > taille(S1)
        // On change donc les représentants des pixels de S1 (le set le plus court)
        
        Pixel* parcoursS1 = this;
        while(parcoursS1->getSuivant() != nullptr) {
            parcoursS1->setRepresentant(representant2);
            parcoursS1 = parcoursS1->getSuivant();
        }
        
        // On coupe le set S2 après sa tête (son représentant) pour y insérer S1 (on raccroche donc S2 (privé de sa tête) à la fin de S1)
        Pixel* dernierS1 = parcoursS1;
        parcoursS1->setRepresentant(representant2);
        parcoursS1 = dernierS1->getSuivant();
        Pixel* deuxiemeS2 = representant2->getSuivant();
        dernierS1->setSuivant(deuxiemeS2);
        representant2->setSuivant(this);
        representant2->incrementSize(this->getSetSize());
        
    } else {
        // taille(S1) > taille(S2)
        // On change donc les représentants des pixels de S2 (le set le plus court)
        
        Pixel* parcoursS2 = representant2;
        while(parcoursS2->getSuivant() != nullptr) {
            parcoursS2->setRepresentant(this);
            parcoursS2 = parcoursS2->getSuivant();
        }

        // On coupe le set S1 après sa tête (son représentant) pour y insérer S2 (on raccroche donc S1 (privé de sa tête) à la fin de S2)
        Pixel* dernierS2 = parcoursS2;
        parcoursS2->setRepresentant(this);
        parcoursS2 = parcoursS2->getSuivant();
        Pixel* deuxiemeS1 = this->getSuivant();
        this->setSuivant(representant2);
        this->incrementSize(representant2->getSetSize());
        dernierS2->setSuivant(deuxiemeS1);
    }
}

int Pixel::getSetSize() {
    return m_setSize;
}

void Pixel::incrementSize(int size) {
    m_setSize+= size;
}
