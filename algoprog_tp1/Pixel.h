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

// Classe abstraite Pixel

using namespace std;

class Pixel {
public:
    Pixel();
    ~Pixel();
    
    string getString() const;

private:
    
};

#endif /* defined(__algoprog_tp1__Pixel__) */
