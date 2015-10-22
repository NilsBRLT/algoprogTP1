//
//  ExceptionTP1.h
//  algoprog_tp1
//
//  Created by Nils Burlat on 20/10/2015.
//  Copyright (c) 2015 Porlat. All rights reserved.
//

#ifndef algoprog_tp1_ExceptionTP1_h
#define algoprog_tp1_ExceptionTP1_h

#include <iostream>
#include <exception>
#include <string>

#define ERREUR_ECRITURE "impossible de créer le fichier de sortie."
#define ERREUR_LECTURE "impossible de lire le fichier d'entrée (fichier inconnu ou accès refusé)"
#define ERREUR_FORMAT "le format attendu dans le fichier .pbm n'est pas correct"
#define ERREUR_DATA "la structure de données fournie ne permet pas la génération d'une image conforme"

using namespace std;

class ExceptionTP1 : public exception {
public:
    ExceptionTP1(string const& error="") throw() : m_error(error) {}
    
    virtual const char* what() const throw()
    {
        return m_error.c_str();
    }
    
    virtual ~ExceptionTP1() throw() {}
    
private:
    string m_error;
};

#endif