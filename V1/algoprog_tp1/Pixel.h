//
//  Pixel.h
//  algoprog_tp1
//
//  Created by Nils Burlat on 08/10/2015.
//  Copyright (c) 2015 Porlat. All rights reserved.
//

#ifndef __algoprog_tp1__Pixel__
#define __algoprog_tp1__Pixel__

#include <stdio.h>
#include <string>

using namespace std;
class Maillon;

class Pixel {
public:
    Pixel();
    Pixel(Pixel* pixel);
    Pixel(int rouge, int vert, int bleu);
    ~Pixel();
    
    bool nEstPasNoir();
    string getString() const;
    int getRouge();
    int getVert();
    int getBleu();
    int getLigne();
    int getColonne();
    bool estEgal(Pixel* pixel);
    
    void setLigne(int ligne);
    void setCouleur(int rouge, int vert, int bleu);
    void setColonne(int colonne);
    
    // NIQUE LES MAILLONS
    
    void setRepresentant(Pixel* pixel);
    Pixel* getRepresentant();
    
    void setSuivant(Pixel* pixel);
    Pixel* getSuivant();
    
    void unionChaines(Pixel* representant2);
    int getSetSize();
    void incrementSize(int size);
    
private:
    int m_rouge;
    int m_vert;
    int m_bleu;
    int m_ligne;
    int m_colonne;
    Pixel* m_representant;
    Pixel* m_suivant;
    int m_setSize;
    
};

#endif /* defined(__algoprog_tp1__Pixel__) */
