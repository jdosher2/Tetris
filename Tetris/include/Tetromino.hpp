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
        INACTIVE,
        WAITING,
        FALLING,
        LANDED
    };
    static const int kTetrominoSize = 4;
    static const int num_of_tetrominoes = 7;
    char letter;
    bool shape_and_rotations[kTetrominoSize][kTetrominoSize + 1][kTetrominoSize + 1] = {};
    State current_state;
    
    
    Tetromino(char name, const bool shape_array[kTetrominoSize][kTetrominoSize + 1][kTetrominoSize + 1], State state) {
        letter = name;
        for (int rot = 0; rot < kTetrominoSize; rot++) {
            for (int i = 0; i < kTetrominoSize + 1; i++) {
                for (int j = 0; j < kTetrominoSize + 1; j++) {
                    shape_and_rotations[rot][i][j] = shape_array[rot][i][j];
                }
            }
        }
        current_state = state;
    }
    
    
    void SetX(int x_pos);
    void SetY(int y_pos);
    void SetState(State state);
    
    int GetX();
    int GetY();
    State GetState();
    
    void Draw();
    void Move(int direction);  // negative = left, positive = right
    void Rotate();
    
    
private:
    int x;
    int y;
    double falling_speed = 0.5;
};

extern const bool shape_I[Tetromino::kTetrominoSize][Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1];

extern const bool shape_J[Tetromino::kTetrominoSize][Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1];

extern const bool shape_L[Tetromino::kTetrominoSize][Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1];

extern const bool shape_O[Tetromino::kTetrominoSize][Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1];

extern const bool shape_S[Tetromino::kTetrominoSize][Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1];

extern const bool shape_T[Tetromino::kTetrominoSize][Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1];

extern const bool shape_Z[Tetromino::kTetrominoSize][Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1];


#endif /* Tetromino_hpp */
