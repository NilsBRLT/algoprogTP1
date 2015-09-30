//
//  main.cpp
//  algoprog_tp1
//
//  Created by Pierre-Antoine Porte on 30/09/2015.
//  Copyright (c) 2015 Porlat. All rights reserved.
//

// print the content of a text file.

#include "tools.h"

int main () {
    Tools tool = Tools();
    
    tool.read("/Users/portepa/development/algoprog_tp1/nils.pbm");
    
    return 0;
}