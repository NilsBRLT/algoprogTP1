//
//  test.h
//  algoprog_tp1
//
//  Created by Nils Burlat on 23/10/2015.
//  Copyright (c) 2015 Porlat. All rights reserved.
//

#ifndef __algoprog_tp1__test__
#define __algoprog_tp1__test__

#include <stdio.h>
#include <iostream>
#include <string>
#include "pixel.h"
#include "image.h"

using namespace std;

class Test {
public:
    // Constructeurs et destructeur
    Test();
    ~Test();
    
    void run();
    void testGenerer();
    void testUnionClassique();
    void testUnionBonus();
    
private:

    
};

#endif /* defined(__algoprog_tp1__test__) */
