//
//  Tetromino.cpp
//  Tetris
//
//  Created by Julie Dosher on 11/15/18.
//

#include "Tetromino.hpp"

const bool shape_I[Tetromino::kTetrominoSize][Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1] = {
    {
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, true, true, true, true},
        {false, false, false, false, false},
        {false, false, false, false, false}
    },
    {
        {false, false, false, false, false},
        {false, false, true, false, false},
        {false, false, true, false, false},
        {false, false, true, false, false},
        {false, false, true, false, false},
    },
    {
        {false, false, false, false, false},
        {false, false, false, false, false},
        {true, true, true, true, false},
        {false, false, false, false, false},
        {false, false, false, false, false}
    },
    {
        {false, false, true, false, false},
        {false, false, true, false, false},
        {false, false, true, false, false},
        {false, false, true, false, false},
        {false, false, false, false, false}
    }
};

const bool shape_J[Tetromino::kTetrominoSize][Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1] = {
    {
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, true, true, true, false},
        {false, false, false, true, false},
        {false, false, false, false, false},
    },
    {
        {false, false, false, false, false},
        {false, false, true, false, false},
        {false, false, true, false, false},
        {false, true, true, false, false},
        {false, false, false, false, false},
    },
    {
        {false, false, false, false, false},
        {false, true, false, false, false},
        {false, true, true, true, false},
        {false, false, false, false, false},
        {false, false, false, false, false},
    },
    {
        {false, false, false, false, false},
        {false, false, true, true, false},
        {false, false, true, false, false},
        {false, false, true, false, false},
        {false, false, false, false, false},
    }
};

const bool shape_L[Tetromino::kTetrominoSize][Tetromino::kTetrominoSize + 1][Tetromino::kTetrominoSize + 1] = {
    {
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, true, true, true, false},
        {false, true, false, false, false},
        {false, false, false, false, false}
    },
    {
        {false, false, false, false, false},
        {false, true, true, false, false},
        {false, false, true, false, false},
        {false, false, true, false, false},
        {false, false, false, false, false}
    },
    {
        {false, false, false, false, false},
        {false, false, false, true, false},
        {false, true, true, true, false},
        {false, false, false, false, false},
        {false, false, false, false, false}
    },
    {
        {false, false, false, false, false},
        {false, false, true, false, false},
        {false, false, true, false, false},
        {false, false, true, true, false},
        {false, false, false, false, false}
    }
};

void Tetromino::Draw() {
    
}

void Tetromino::Move(int direction) {
    Tetromino::SetX(Tetromino::GetX() + direction);
}

int Tetromino::GetX() {
    return Tetromino::x;
}

int Tetromino::GetY() {
    return Tetromino::y;
}

ofColor Tetromino::GetColor() {
    return Tetromino::color;
}

Tetromino::State Tetromino::GetState() {
    return Tetromino::current_state;
}

void Tetromino::SetX(int x_pos) {
    Tetromino::x = x_pos;
}

void Tetromino::SetY(int y_pos) {
    Tetromino::y = y_pos;
}

void Tetromino::SetState(Tetromino::State state) {
    Tetromino::current_state = state;
}
