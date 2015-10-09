//
//  PixelPPM.cpp
//  algoprog_tp1
//
//  Created by Nils Burlat on 09/10/2015.
//  Copyright (c) 2015 Porlat. All rights reserved.
//

#include "PixelPPM.h"

using namespace std;

PixelPPM::PixelPPM(int rouge, int vert, int bleu) {
    m_rouge = rouge;
    m_vert = vert;
    m_bleu = bleu;
}

PixelPPM::~PixelPPM() {
    
}

string PixelPPM::getString() {
    return to_string(m_rouge) + " " + to_string(m_vert) + " " + to_string(m_bleu);
}

int PixelPPM::getRouge() {
    return m_rouge;
}

int PixelPPM::getVert() {
    return m_vert;
}

int PixelPPM::getBleu() {
    return m_bleu;
}