//
//  Tetromino.hpp
//  Tetris
//
//  Created by Julie Dosher on 11/15/18.
//

#ifndef Tetromino_hpp
#define Tetromino_hpp

#include "ofMain.h"

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
    static const int kTetrominoSize = 4;
    char letter;
    bool shape_and_rotations[kTetrominoSize][kTetrominoSize + 1][kTetrominoSize + 1] = {};
    ofColor color;
    
    
    Tetromino(char l, bool s[kTetrominoSize][kTetrominoSize + 1][kTetrominoSize + 1], ofColor c) {
        letter = l;
        for (int rot = 0; rot < kTetrominoSize; rot++) {
            for (int i = 0; i < kTetrominoSize + 1; i++) {
                for (int j = 0; j < kTetrominoSize + 1; j++) {
                    shape_and_rotations[rot][i][j] = s[rot][i][j];
                }
            }
        }
        color = color;
    }
    
    
    
    
    
    
    
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
    //std::vector<ofPoint> shape;
    int x;
    int y;
    State current_state;
    double falling_speed = 0.5;
    
    static void InitShapes();
};

extern const bool shape_I[Tetromino::kTetrominoSize][Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1];
extern const bool shape_J[Tetromino::kTetrominoSize][Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1];
extern const bool shape_L[Tetromino::kTetrominoSize][Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1];
extern const bool shape_O[Tetromino::kTetrominoSize][Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1];
extern const bool shape_S[Tetromino::kTetrominoSize][Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1];
extern const bool shape_T[Tetromino::kTetrominoSize][Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1];
extern const bool shape_Z[Tetromino::kTetrominoSize][Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1];

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
