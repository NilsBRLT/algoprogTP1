//
//  Pixel.cpp
//  algoprog_tp1
//
//  Created by Nils Burlat on 08/10/2015.
//  Copyright (c) 2015 Porlat. All rights reserved.
//

#include "pixel.h"


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

void Pixel::setQueue(Pixel *pixel) {
    m_queue = pixel;
}

Pixel* Pixel::getQueue() {
    return m_queue;
}

/**
 * Réalise l'union de deux ensembles de pixels
 * assume : representant2 n'est pas nullptr, les deux ensembles sont distincts
 * guarantee : création d'un ensemble unique à partir des deux ensembles d'entrée
 **/
void Pixel::unionClassique(Pixel *representant2) {
    if (representant2->getSetSize() > this->getSetSize()) {
        // taille(S2) > taille(S1)
        // On change donc les représentants des pixels de S1 (le set le plus court)
        
        Pixel* parcoursS1 = this;
        do {
            parcoursS1->setRepresentant(this);
            parcoursS1 = parcoursS1->getSuivant();
        } while (parcoursS1 != nullptr);
        
        // On branche la tête de S1 à la queue de S2
        representant2->getQueue()->setSuivant(this);
        // On change la queue de S2
        representant2->setQueue(this->getQueue());
        
    } else {
        // taille(S1) > taille(S2)
        // On change donc les représentants des pixels de S2 (le set le plus court)
        
        Pixel* parcoursS2 = representant2;
        do {
            parcoursS2->setRepresentant(this);
            parcoursS2 = parcoursS2->getSuivant();
        } while (parcoursS2 != nullptr);
        
        // On branche la tête de S2 à la queue de S1
        this->getQueue()->setSuivant(representant2);
        // On change la queue de S1
        this->setQueue(representant2->getQueue());
    }
}

/**
 * Réalise l'union de deux ensembles de pixels (BONUS)
 * assume : representant2 n'est pas nullptr, les deux ensembles sont distincts
 * guarantee : création d'un ensemble unique à partir des deux ensembles d'entrée
 **/
void Pixel::unionBonus(Pixel* representant2) {
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

void Pixel::afficherEnsemble() {
    Pixel* parcours = this;
    int i = 1;
    while (parcours != nullptr) {
        cout << "Pixel " << i << " (RVB) : " << parcours->getRepresentant()->getRouge() << " " << parcours->getRepresentant()->getVert() << " " << parcours->getRepresentant()->getBleu() << endl;
        i++;
        parcours = parcours->getSuivant();
    }
}
