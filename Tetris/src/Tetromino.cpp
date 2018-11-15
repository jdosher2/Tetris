//
//  Tetromino.cpp
//  Tetris
//
//  Created by Julie Dosher on 11/15/18.
//

#include "Tetromino.hpp"


void Tetromino::InitShapes() {
    Tetromino::I.push_back(ofPoint(0, 0));
    Tetromino::I.push_back(ofPoint(0, 1));
    Tetromino::I.push_back(ofPoint(0, 2));
    Tetromino::I.push_back(ofPoint(0, 3));
    
    Tetromino::J.push_back(ofPoint(0, 0));
    Tetromino::J.push_back(ofPoint(1, 0));
    Tetromino::J.push_back(ofPoint(1, 1));
    Tetromino::J.push_back(ofPoint(1, 2));
    
    Tetromino::L.push_back(ofPoint(0, 0));
    Tetromino::L.push_back(ofPoint(1, 0));
    Tetromino::L.push_back(ofPoint(0, 1));
    Tetromino::L.push_back(ofPoint(0, 2));
    
    Tetromino::O.push_back(ofPoint(0, 0));
    Tetromino::O.push_back(ofPoint(1, 0));
    Tetromino::O.push_back(ofPoint(0, 1));
    Tetromino::O.push_back(ofPoint(1, 1));
    
    Tetromino::S.push_back(ofPoint(0, 0));
    Tetromino::S.push_back(ofPoint(1, 0));
    Tetromino::S.push_back(ofPoint(1, 1));
    Tetromino::S.push_back(ofPoint(2, 1));
    
    Tetromino::T.push_back(ofPoint(0, 0));
    Tetromino::T.push_back(ofPoint(0, 1));
    Tetromino::T.push_back(ofPoint(1, 1));
    Tetromino::T.push_back(ofPoint(0, 2));
    
    Tetromino::Z.push_back(ofPoint(0, 0));
    Tetromino::Z.push_back(ofPoint(0, 1));
    Tetromino::Z.push_back(ofPoint(1, 1));
    Tetromino::Z.push_back(ofPoint(1, 2));
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
