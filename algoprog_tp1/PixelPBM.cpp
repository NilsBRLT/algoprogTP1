//
//  PixelPBM.cpp
//  algoprog_tp1
//
//  Created by Nils Burlat on 08/10/2015.
//  Copyright (c) 2015 Porlat. All rights reserved.
//

#include "PixelPBM.h"

using namespace std;

PixelPBM::PixelPBM(int valeur) {
    m_valeur = valeur;
}

PixelPBM::~PixelPBM() {
    
}

string PixelPBM::getValeur() {
    return to_string(m_valeur);
}