//
//  Block.hpp
//  Tetris
//
//  Created by Julie Dosher on 11/15/18.
//

#ifndef Block_hpp
#define Block_hpp

#include "ofMain.h"

#include <stdio.h>


class Block {
    
public:
    static const int kSideLength = 35;
    
    bool is_filled;
    ofColor fill_color;
   
    Block(bool filled, ofColor color) {
        is_filled = filled;
        fill_color = color;
    }
};



#endif /* Block_hpp */
