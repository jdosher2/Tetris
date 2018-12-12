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
        INACTIVE = 0,
        WAITING = 2,
        FALLING = 1
    };
    
    enum Direction {
        LEFT = -1,
        RIGHT = 1
    };
    
    static const int kTetrominoSize = 4;
    static const int num_of_tetrominoes = 7;
    char letter;
    bool shape[kTetrominoSize + 1][kTetrominoSize + 1] = {};
    State current_state;
    std::pair<int, int> block_locations[kTetrominoSize] = {};
    
    Tetromino() {
        
    }
    
    Tetromino(char name, const bool shape_array[kTetrominoSize + 1][kTetrominoSize + 1], State state) {
        letter = name;
        for (int i = 0; i < kTetrominoSize + 1; i++) {
            for (int j = 0; j < kTetrominoSize + 1; j++) {
                shape[i][j] = shape_array[i][j];
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
};

extern const bool shape_I[Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1];

extern const bool shape_J[Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1];

extern const bool shape_L[Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1];

extern const bool shape_O[Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1];

extern const bool shape_S[Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1];

extern const bool shape_T[Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1];

extern const bool shape_Z[Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1];


#endif /* Tetromino_hpp */
