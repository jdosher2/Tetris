//
//  Tetromino.hpp
//  Tetris
//
//  Created by Julie Dosher on 11/15/18.
//

#ifndef Tetromino_hpp
#define Tetromino_hpp

#include "ofMain.h"
#include "Block.hpp"

#include <stdio.h>
#include <array>
#include <map>
#include <vector>

class Tetromino {
public:
    enum State {
        WAITING,
        FALLING,
        LANDED
    };
    static const int kTetrominoSize = 4;
    static std::vector<ofPoint> I;
    static std::vector<ofPoint> J;
    static std::vector<ofPoint> L;
    static std::vector<ofPoint> O;
    static std::vector<ofPoint> S;
    static std::vector<ofPoint> T;
    static std::vector<ofPoint> Z;
    
    static void draw();

private:
    static void InitShapes();
};


//extern const std::map<char, std::array<int, Tetromino::kTetrominoSize>> all_shapes = {
    
    /*
     using pattern:
     0   1
     2   3
     4   5
     6   7
    {'I', {0, 2, 3, 6} },
    {'J', {3, 5, 7, 6} },
    {'L', {2, 4, 6, 7} },
    {'O', {2, 3, 4, 5} },
    {'S', {3, 5, 4, 6} },
    {'T', {3, 5, 4, 7} },
    {'Z', {2, 4, 5, 7} }
     */

// red, orange, green, blue, cyan, magenta, yellow
extern const std::map<char, ofColor> shapes_and_colors = {
    {'I', ofColor::cyan},
    {'J', ofColor::orange},
    {'L', ofColor::yellow},
    {'O', ofColor::blue},
    {'S', ofColor::green},
    {'T', ofColor::magenta},
    {'Z', ofColor::red}
};

#endif /* Tetromino_hpp */
