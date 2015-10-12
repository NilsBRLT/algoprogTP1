//
//  maillon.cpp
//  algoprog_tp1
//
//  Created by Nils Burlat on 01/10/2015.
//  Copyright (c) 2015 Porlat. All rights reserved.
//

#include "maillon.h"

Maillon::Maillon() {

}

// Peut-être useless ?
Maillon::Maillon(Maillon* maillon) {
    m_pixel = maillon->getPixel();
    m_suivant = maillon->getSuivant();
    m_representant = maillon->getRepresentant();
}

Maillon::Maillon(Pixel* pixel) {
    setPixel(pixel);
    setRepresentant(this);
    pixel->setMaillon(this);
}

Maillon::Maillon(Pixel* pixel, Maillon* suivant, Maillon* representant) {
    setPixel(pixel);
    setSuivant(suivant);
    setRepresentant(representant);
}

void Maillon::setPixel(Pixel* pixel) {
    m_pixel = pixel;
}

void Maillon::setSuivant(Maillon *suivant) {
    m_suivant = suivant;
}

void Maillon::setRepresentant(Maillon *representant) {
    m_representant = representant;
}

Pixel* Maillon::getPixel() {
    return m_pixel;
}

Maillon* Maillon::getSuivant() {
    return m_suivant;
}

Maillon* Maillon::getRepresentant() {
    return m_representant;
}

bool Maillon::sameEnsemble(Maillon *maillon) {
    return (getRepresentant()->getPixel()->estEgal(maillon->getRepresentant()->getPixel()));
}

void Maillon::unionSet(Maillon* representant2) {
    
    //    if (representant1.getRepresentant()->getPixel() == reprensentant2.getRepresentant()->getPixel()) {
    //        // Ensemble non disjoint
    //        // Throw error (précond)
    //    }
    //    if (representant1.getRepresentant()->getPixel() != representant1.getPixel()
    //        || representant2.getRepresentant()->getPixel() != representant2.getPixel()) {
    //        // Reprensentants ne sont pas représentant (au moins un des deux
    //        // Throw error ou prendre son représentant ?
    //    }
    
    Maillon* elemS1 = new Maillon(this);
    Maillon* elemS2 = new Maillon(representant2);
    
    // On veut prendre le dernier de la liste pour lui ajouter les suivants
    while (elemS1->getSuivant() != nullptr) {
        elemS1 = elemS1->getSuivant();
    }
    // Arrivé ici, elemS1 est le dernier élément de S1
    
    // On "accroche" S2 à S1
    elemS1->setSuivant(elemS2);
    
    while (elemS1->getSuivant() != nullptr) {
        elemS1 = elemS1->getSuivant();
        elemS1->setRepresentant(this);
        elemS1->getPixel()->setCouleur(this->getPixel()->getRouge(), this->getPixel()->getVert(), this->getPixel()->getBleu());
    }
}