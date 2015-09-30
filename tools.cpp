//
//  tools.cpp
//  algoprog_tp1
//
//  Created by Pierre-Antoine Porte on 30/09/2015.
//  Copyright (c) 2015 Porlat. All rights reserved.
//

#include "tools.h"

Tools::Tools() {
}

Tools::~Tools() {
}

int Tools::read(string filepath) {
    
    std::ifstream ifs;
    // Doesn't work with relative path... Investigate later
    // This issue seems to be on Mac only.
    ifs.open (filepath, std::ifstream::in);
    
    if (ifs.is_open()) {
        std::vector<string> lines;
        
        char c = ifs.get();
        while (ifs.good()) {
            std::cout << c;
            if (c == '\n') {
                
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