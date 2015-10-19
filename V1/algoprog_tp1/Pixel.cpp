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
}

Pixel::Pixel(Pixel* pixel) {
    setCouleur(pixel->getRouge(), pixel->getVert(), pixel->getBleu());
    setColonne(pixel->getColonne());
    setLigne(pixel->getLigne());
    setSuivant(nullptr);
    m_setSize = 1;
}

Pixel::Pixel(int rouge, int vert, int bleu) {
    m_rouge = rouge;
    m_vert = vert;
    m_bleu = bleu;
    setSuivant(nullptr);
    m_setSize = 1;
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
//    if (representant2->getSetSize() > this->getSetSize()) {
//        // Le second set sera plus long à parcourir que le premier : on parcours S1
//        Pixel* parcoursS1 = this;
//        Pixel* dernierS1;
//        do {
//            dernierS1 = parcoursS1;
//            parcoursS1->setRepresentant(representant2);
//            parcoursS1->setCouleur(representant2->getRouge(), representant2->getVert(), representant2->getBleu());
//            parcoursS1 = parcoursS1->getSuivant();
//        } while(parcoursS1 != nullptr);
//        
//        // TECHNIQUE TROUVÉE AVEC ANNE, MA MUSE
//        Pixel* deuxiemeS2 = representant2->getSuivant();
//        representant2->setSuivant(this);
//        representant2->incrementSize(this->getSetSize());
//            cout << representant2->getSetSize() <<endl;
//        cout << "québlo" << endl;
//        dernierS1->setSuivant(deuxiemeS2);
//
//    } else {
        // Le premier set sera plus long à parcouri : on parcours S2
        Pixel* parcoursS2 = representant2;
        while(parcoursS2->getSuivant() != nullptr) {
            parcoursS2->setRepresentant(this);
            parcoursS2->setCouleur(this->getRouge(), this->getVert(), this->getBleu());
            parcoursS2 = parcoursS2->getSuivant();
        }
        // On prends désormais le dernier à la fin ca évite les affectations inutiles
        Pixel* dernierS2 = parcoursS2;
        parcoursS2->setRepresentant(this);
        parcoursS2->setCouleur(this->getRouge(), this->getVert(), this->getBleu());
        parcoursS2 = parcoursS2->getSuivant();
        // TECHNIQUE TROUVÉE AVEC ANNE, MA MUSE
        Pixel* deuxiemeS1 = this->getSuivant();
        this->setSuivant(representant2);
        this->incrementSize(representant2->getSetSize());
//            cout << this->getSetSize() <<endl;
//        cout << "bloqué" << endl;
//        cout << "Dernier S2 : " << dernierS2 << endl;
//        cout << "Deuxième S1 : " << deuxiemeS1 << endl;
        dernierS2->setSuivant(deuxiemeS1);
//    }
}

int Pixel::getSetSize() {
    return m_setSize;
}

void Pixel::incrementSize(int size) {
    m_setSize+= size;
}
