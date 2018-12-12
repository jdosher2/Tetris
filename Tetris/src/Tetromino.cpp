//
//  Tetromino.cpp
//  Tetris
//
//  Created by Julie Dosher on 11/15/18.
//

#include "Tetromino.hpp"


const bool shape_I[Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1] = {
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, true, true, true, true},
        {false, false, false, false, false},
        {false, false, false, false, false}
    
};

const bool shape_J[Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1] = {
    
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, true, true, true, false},
        {false, false, false, true, false},
        {false, false, false, false, false},
};

const bool shape_L[Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1] = {
    
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, true, true, true, false},
        {false, true, false, false, false},
        {false, false, false, false, false}
    
};

const bool shape_O[Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1] = {
    
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, false, true, true, false},
        {false, false, true, true, false},
        {false, false, false, false, false}
    
};

const bool shape_S[Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1] = {
    
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, false, true, true, false},
        {false, true, true, false, false},
        {false, false, false, false, false}
    
};

const bool shape_T[Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1] = {
    
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, true, true, true, false},
        {false, false, true, false, false},
        {false, false, false, false, false}
    
};

const bool shape_Z[Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1] = {
    
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, true, true, false, false},
        {false, false, true, true, false},
        {false, false, false, false, false}
    
};


Tetromino::State Tetromino::GetState() {
    return Tetromino::current_state;
}


void Tetromino::SetState(Tetromino::State state) {
    Tetromino::current_state = state;
}
