//
//  tools.h
//  algoprog_tp1
//
//  Created by Pierre-Antoine Porte on 30/09/2015.
//  Copyright (c) 2015 Porlat. All rights reserved.
//

#ifndef __algoprog_tp1__tools__
#define __algoprog_tp1__tools__

#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <vector>
using namespace std;

class Tools {
public:
    Tools();
    ~Tools();
    int read(std::string filepath);
};

#include <stdio.h>

#endif /* defined(__algoprog_tp1__tools__) */
