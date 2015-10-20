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