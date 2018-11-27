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
#include <map>
#include <vector>

class Tetromino {
public:
    enum State {
        WAITING,
        FALLING,
        LANDED
    };
    
    Tetromino(std::vector<ofPoint> vector_of_shape, int x_pos, int y_pos, State state) {
        shape = vector_of_shape;
        x = x_pos;
        y = y_pos;
        current_state = state;
    }
    
    static const int kTetrominoSize = 4;
    static std::vector<ofPoint> I;
    static std::vector<ofPoint> J;
    static std::vector<ofPoint> L;
    static std::vector<ofPoint> O;
    static std::vector<ofPoint> S;
    static std::vector<ofPoint> T;
    static std::vector<ofPoint> Z;
    
    void SetX(int x_pos);
    void SetY(int y_pos);
    void SetState(State state);
    
    int GetX();
    int GetY();
    State GetState();
    
    static void Draw();
    void Move(int direction);  // negative = left, positive = right
    void Rotate();
    
private:
    std::vector<ofPoint> shape;
    int x;
    int y;
    State current_state;
    double falling_speed = 0.0;
    
    static void InitShapes();
};

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
