//
//  maillon.cpp
//  algoprog_tp1
//
//  Created by Nils Burlat on 01/10/2015.
//  Copyright (c) 2015 Porlat. All rights reserved.
//

#include "maillon.h"

Maillon::Maillon() {
    setPixel(0,0,0);
}

Maillon::Maillon(int pixel[3]) {
    setPixel(pixel[INDICE_ROUGE], pixel[INDICE_VERT], pixel[INDICE_BLEU]);
}

Maillon::Maillon(int pixel[3], Maillon* suivant, Maillon* representant) {
    setPixel(pixel[INDICE_ROUGE], pixel[INDICE_VERT], pixel[INDICE_BLEU]);
    setSuivant(suivant);
    setRepresentant(representant);
}

void Maillon::setPixel(int rouge, int vert, int bleu) {
    m_pixel[INDICE_ROUGE] = rouge;
    m_pixel[INDICE_VERT] = vert;
    m_pixel[INDICE_BLEU] = bleu;
}

void Maillon::setSuivant(Maillon *suivant) {
    m_suivant = suivant;
}

void Maillon::setRepresentant(Maillon *representant) {
    m_representant = representant;
}

int* Maillon::getPixel() {
    return m_pixel;
}

Maillon* Maillon::getSuivant() {
    return m_suivant;
}

Maillon* Maillon::getRepresentant() {
    return m_representant;
}