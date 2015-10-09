//
//  Pixel.cpp
//  algoprog_tp1
//
//  Created by Nils Burlat on 08/10/2015.
//  Copyright (c) 2015 Porlat. All rights reserved.
//

#include "Pixel.h"


Pixel::Pixel() {
    
}

Pixel::Pixel(int rouge, int vert, int bleu) {
    m_rouge = rouge;
    m_vert = vert;
    m_bleu = bleu;
}

Pixel::~Pixel() {
    
}

string Pixel::getString() const {
    return to_string(m_rouge) + " " + to_string(m_vert) + " " + to_string(m_bleu);
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