//
//  Tetromino.cpp
//  Tetris
//
//  Created by Julie Dosher on 11/15/18.
//

#include "Tetromino.hpp"

const bool shape_I[Tetromino::kStartingHeight][Tetromino::kStartingWidth] = {
    {true, true, true, true},
    {false, false, false, false}
};

const bool shape_J[Tetromino::kStartingHeight][Tetromino::kStartingWidth] = {
    {true, true, true, false},
    {false, false, true, false}
};

const bool shape_L[Tetromino::kStartingHeight][Tetromino::kStartingWidth] = {
    {true, true, true, false},
    {true, false, false, false}
};

const bool shape_O[Tetromino::kStartingHeight][Tetromino::kStartingWidth] = {
    {true, true, false, false},
    {true, true, false, false}
};

const bool shape_S[Tetromino::kStartingHeight][Tetromino::kStartingWidth] = {
    {false, true, true, false},
    {true, true, false, false}
};

const bool shape_T[Tetromino::kStartingHeight][Tetromino::kStartingWidth] = {
    {true, true, true, false},
    {false, true, false, false}
};

const bool shape_Z[Tetromino::kStartingHeight][Tetromino::kStartingWidth] = {
    {true, true, false, false},
    {false, true, true, false}
};


Tetromino::State Tetromino::GetState() {
    return Tetromino::current_state;
}


void Tetromino::SetState(Tetromino::State state) {
    Tetromino::current_state = state;
}
