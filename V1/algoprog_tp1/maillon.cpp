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
    if (this->getPixel()->getLigne() == 2 && this->getPixel()->getColonne() == 2) {
        ;
    }
    if (this->getRepresentant() == representant2->getRepresentant()) {
        cout << "not normal" << endl;
    }
    
    Maillon* parcours = this;
    Maillon* representant = this;
    
    // On veut prendre le dernier de la liste pour lui ajouter les suivants
    while (parcours->getSuivant() != nullptr) {
        cout << "next of" << " (" << parcours->getPixel()->getLigne() << "," << parcours->getPixel()->getColonne() << ")" << " is " << " (" << parcours->getSuivant()->getPixel()->getLigne() << "," << parcours->getSuivant()->getPixel()->getColonne() << ")" << endl;
        parcours = parcours->getSuivant();
        if (parcours == representant2) {
            cout << "NOT FUCKING NORMAL" << endl;
            
        }
    }
    // Arrivé ici, elemS1 est le dernier élément de S1
    
    // On "accroche" S2 à S1
    parcours->setSuivant(representant2);
    
    // On passe sur le premier de l'ancienne deuxième liste
    parcours = parcours->getSuivant();
    cout << parcours->getPixel()->getLigne() << "," << parcours->getPixel()->getColonne() << " ==" << representant2->getPixel()->getLigne() << "," << representant2->getPixel()->getColonne() << endl;
    cout << parcours->getSuivant() << endl;
    vector<Maillon*> maillons;
    do {
        cout << "new representant for : " << parcours->getPixel()->getLigne() << "," << parcours->getPixel()->getColonne() << " (" << representant->getPixel()->getLigne() << "," << representant->getPixel()->getColonne() << ")" << endl;
        parcours->setRepresentant(representant);
        parcours->getPixel()->setCouleur(representant->getPixel()->getRouge(), representant->getPixel()->getVert(), representant->getPixel()->getBleu());
        maillons.push_back(parcours);
        for (int i = 0; i < maillons.size(); i++) {
            if (maillons[i] == parcours) {
                parcours->setSuivant(nullptr);
            }
        }
        parcours = parcours->getSuivant();
    } while(parcours != nullptr);
    representant2->setSuivant(nullptr);
}

void Maillon::afficher() {
    cout << "affichage" << endl;
    Maillon* boucleur = new Maillon(this);
    while (boucleur != nullptr) {
        cout << boucleur->getPixel()->getString() << endl;
        boucleur = boucleur->getSuivant();
    }
}












