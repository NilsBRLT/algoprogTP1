//
//  test.cpp
//  algoprog_tp1
//
//  Created by Nils Burlat on 23/10/2015.
//  Copyright (c) 2015 Porlat. All rights reserved.
//

#include "test.h"

Test::Test() {
    
}

Test::~Test() {
    
}

void Test::run() {
    cout << ">>>>>> TEST DE L'UNION CLASSIQUE <<<<<<" << endl;
    testUnionClassique();
    cout << ">>>>>> FIN DU TEST <<<<<<" << endl << endl;
    
    cout << ">>>>>> TEST DE L'UNION BONUS <<<<<<" << endl;
    testUnionBonus();
    cout << ">>>>>> FIN DU TEST <<<<<<" << endl << endl;
}

void Test::testUnionBonus() {
    // Premier ensemble
    Pixel* pix1 = new Pixel(1,1,1);
    Pixel* pix2 = new Pixel(1,1,1);
    Pixel* pix3 = new Pixel(1,1,1);
    pix1->setRepresentant(pix1);
    pix2->setRepresentant(pix1);
    pix3->setRepresentant(pix1);
    pix1->setSuivant(pix2);
    pix2->setSuivant(pix3);
    pix3->setSuivant(nullptr);
    pix1->setQueue(pix3);
    pix2->setQueue(pix3);
    pix3->setQueue(pix3);
    
    // Deuxième ensemble
    Pixel* pix4 = new Pixel(2,2,2);
    Pixel* pix5 = new Pixel(3,3,3);
    Pixel* pix6 = new Pixel(4,4,4);
    pix4->setRepresentant(pix4);
    pix5->setRepresentant(pix4);
    pix6->setRepresentant(pix4);
    pix4->setSuivant(pix5);
    pix5->setSuivant(pix6);
    pix6->setSuivant(nullptr);
    pix4->setQueue(pix6);
    pix5->setQueue(pix6);
    pix6->setQueue(pix6);
    
    // Affichage pré union
    cout << "Ensemble S1 de trois pixels : " << endl;
    pix1->afficherEnsemble();
    cout << endl << "Ensemble S2 de trois pixels : " << endl;
    pix4->afficherEnsemble();
    
    // Test de l'union
    pix1->unionBonus(pix4);
    
    // Affichage post union
    cout << endl << "Ensemble S3 (fusion de S1 et S2) : " << endl;
    pix1->afficherEnsemble();
}

void Test::testUnionClassique() {
    // Premier ensemble
    Pixel* pix1 = new Pixel(1,1,1);
    Pixel* pix2 = new Pixel(1,1,1);
    Pixel* pix3 = new Pixel(1,1,1);
    pix1->setRepresentant(pix1);
    pix2->setRepresentant(pix1);
    pix3->setRepresentant(pix1);
    pix1->setSuivant(pix2);
    pix2->setSuivant(pix3);
    pix3->setSuivant(nullptr);
    pix1->setQueue(pix3);
    pix2->setQueue(pix3);
    pix3->setQueue(pix3);
    
    // Deuxième ensemble
    Pixel* pix4 = new Pixel(2,2,2);
    Pixel* pix5 = new Pixel(3,3,3);
    Pixel* pix6 = new Pixel(4,4,4);
    pix4->setRepresentant(pix4);
    pix5->setRepresentant(pix4);
    pix6->setRepresentant(pix4);
    pix4->setSuivant(pix5);
    pix5->setSuivant(pix6);
    pix6->setSuivant(nullptr);
    pix4->setQueue(pix6);
    pix5->setQueue(pix6);
    pix6->setQueue(pix6);
    
    // Affichage pré union
    cout << "Ensemble S1 de trois pixels : " << endl;
    pix1->afficherEnsemble();
    cout << endl << "Ensemble S2 de trois pixels : " << endl;
    pix4->afficherEnsemble();
    
    // Test de l'union
    pix1->unionBonus(pix4);
    
    // Affichage post union
    cout << endl << "Ensemble S3 (fusion de S1 et S2) : " << endl;
    pix1->afficherEnsemble();
}