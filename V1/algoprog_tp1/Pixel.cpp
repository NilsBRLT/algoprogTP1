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

bool Pixel::nEstPasNoir() {
    return m_rouge != 0 || m_vert != 0 || m_bleu != 0;
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

int Pixel::getLigne() {
    return m_ligne;
}

int Pixel::getColonne() {
    return m_colonne;
}

void Pixel::setLigne(int ligne) {
    m_ligne = ligne;
}

void Pixel::setColonne(int colonne) {
    m_colonne = colonne;
}

void Pixel::setCouleur(int rouge, int vert, int bleu) {
    m_rouge = rouge;
    m_vert = vert;
    m_bleu = bleu;
}

bool Pixel::estEgal(Pixel *pixel) {
    return m_rouge == pixel->getRouge() && m_vert == pixel->getVert() && m_bleu == pixel->getBleu();
}