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

Maillon::Maillon(Pixel pixel) {
    setPixel(pixel);
}

Maillon::Maillon(Pixel pixel, Maillon* suivant, Maillon* representant) {
    setPixel(pixel);
    setSuivant(suivant);
    setRepresentant(representant);
}

void Maillon::setPixel(Pixel pixel) {
    m_pixel = pixel;
}

void Maillon::setSuivant(Maillon *suivant) {
    m_suivant = suivant;
}

void Maillon::setRepresentant(Maillon *representant) {
    m_representant = representant;
}

Pixel Maillon::getPixel() {
    return m_pixel;
}

Maillon* Maillon::getSuivant() {
    return m_suivant;
}

Maillon* Maillon::getRepresentant() {
    return m_representant;
}