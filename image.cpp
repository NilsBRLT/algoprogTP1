//
//  tools.cpp
//  algoprog_tp1
//
//  Created by Pierre-Antoine Porte on 30/09/2015.
//  Copyright (c) 2015 Porlat. All rights reserved.
//

#include "image.h"

Image::Image() {
}

Image::~Image() {
}

int Image::read(string filepath) {
    
    std::ifstream ifs;
    // Doesn't work with relative path... Investigate later
    // This issue seems to be on Mac only.
    ifs.open (filepath, std::ifstream::in);
    
    if (ifs.is_open()) {
        string ligne = "";
        int positionFichierLigne = 0;
        
        char c = ifs.get();
        while (ifs.good()) {
            ligne += c;
            if (c == '\n') {
                analyseLigne(ligne, positionFichierLigne);
                positionFichierLigne++;
                ligne = "";
            }
            c = ifs.get();
        }
    }
    else {
        // show message:
        std::cout << "Error opening file";
    }
    
    ifs.close();
    
    return 0;
}

void Image::analyseLigne(string ligne, int position) {
    if (position == 0) {
        type = ligne;
        return;
    } else if (position == 1) {
        size_t pos = ligne.find(" ");
        largeur = stoi(ligne.substr(0, pos));
        hauteur = stoi(ligne.substr(pos));
        return;
    } else {
        for (size_t pos = 0; pos < ligne.length(); pos = ligne.find("1", pos)) {
            if (pos == string::npos) {
                pos = ligne.find("0", pos);
            }
            cout << ligne.substr(pos, pos);
            pixels.push_back((stoi(ligne.substr(pos, pos))));
        }
    }
}