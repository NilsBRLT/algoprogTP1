//
//  maillon.cpp
//  algoprog_tp1
//
//  Created by Nils Burlat on 01/10/2015.
//  Copyright (c) 2015 Porlat. All rights reserved.
//

#include "maillon.h"

using namespace std;

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
    setSuivant(nullptr); // C'EST CETTE PUTAIN DE LIGNE QUI NIQUAIT LE BUSINESS
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
    Maillon* parcoursS2 = representant2;
    
    do {
        parcoursS2->setRepresentant(this);
        parcoursS2->getPixel()->setCouleur(this->getPixel()->getRouge(), this->getPixel()->getVert(), this->getPixel()->getBleu());
        parcoursS2 = parcoursS2->getSuivant();
    } while(parcoursS2 != nullptr);
    
    Maillon* parcoursS1 = this;
    while (parcoursS1->getSuivant() != nullptr) {
        parcoursS1 = parcoursS1->getSuivant();
    }
    parcoursS1->setSuivant(representant2);
}

void Maillon::afficher() {
    cout << "affichage" << endl;
    Maillon* boucleur = new Maillon(this);
    while (boucleur != nullptr) {
        cout << boucleur->getPixel()->getString() << endl;
        boucleur = boucleur->getSuivant();
    }
}












