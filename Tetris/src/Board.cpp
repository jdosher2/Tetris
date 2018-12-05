//
//  Board.cpp
//  Tetris
//
//  Created by Julie Dosher on 11/15/18.
//

#include "Board.hpp"

bool board[Board::kStandardHeight][Board::kStandardWidth] = {};

Tetromino Board::tetromino_I = *new Tetromino('I', shape_I, Tetromino::State::INACTIVE);
Tetromino Board::tetromino_J = *new Tetromino('J', shape_J, Tetromino::State::INACTIVE);
Tetromino Board::tetromino_L = *new Tetromino('L', shape_L, Tetromino::State::INACTIVE);
Tetromino Board::tetromino_O = *new Tetromino('O', shape_O, Tetromino::State::INACTIVE);
Tetromino Board::tetromino_S = *new Tetromino('S', shape_S, Tetromino::State::INACTIVE);
Tetromino Board::tetromino_T = *new Tetromino('T', shape_T, Tetromino::State::INACTIVE);
Tetromino Board::tetromino_Z = *new Tetromino('Z', shape_Z, Tetromino::State::INACTIVE);

Tetromino possible_tetrominoes[Tetromino::num_of_tetrominoes] = {Board::tetromino_I, Board::tetromino_J, Board::tetromino_L, Board::tetromino_O, Board::tetromino_S, Board::tetromino_T, Board::tetromino_Z};

ofColor possible_colors[Tetromino::num_of_tetrominoes];


void Board::InitColors() {
    possible_colors[0] = ofColor::cyan;
    possible_colors[1] = ofColor::blue;
    possible_colors[2] = ofColor::orange;
    possible_colors[3] = ofColor::yellow;
    possible_colors[4] = ofColor::green;
    possible_colors[5] = ofColor::purple;
    possible_colors[6] = ofColor::red;
}

void Board::InitBoard() {
    for (int r = 0; r < kStandardHeight; r++) {
        for (int c = 0; c < kStandardWidth; c++) {
            board[r][c] = false;
        }
    }
}

Tetromino Board::GenerateTetromino(int x1, int y1, int block_side_length) {
    InitColors();
    
    int random_index = rand() % Tetromino::num_of_tetrominoes;
    Tetromino chosen_tetromino = possible_tetrominoes[random_index];
    ofColor chosen_color = possible_colors[random_index];
    ofSetColor(chosen_color);
    // TODO: fix color bug
    
    int x = x1;
    int y = y1;
    
    for (int r = 0; r < Tetromino::kTetrominoSize + 1; r++) {
        for (int c = 0; c < Tetromino::kTetrominoSize + 1; c++) {
            if (chosen_tetromino.shape_and_rotations[0][r][c]) {
                ofDrawRectangle(x, y, block_side_length, block_side_length);
            }
            x += block_side_length;
        }
        x = x1;
        y += block_side_length;
    }
    
    return chosen_tetromino;
}

bool Board::CanRemoveRow(int row) {
    for (int c = 0; c < kStandardWidth; c++) {
        if (board[row][c] == false) {
            return false;
        }
    }
    return true;
}

void Board::RemoveRow(int row) {
    // clear row
    for (int c = 0; c < kStandardWidth; c++) {
        board[row][c] = false;
    }
    
    // collapse rows above
    for (int c = 0; c < kStandardWidth; c++) {
        for (int r = row; r > 0; r--) {
            board[r][c] = board[r - 1][c];
        }
    }
    
    Game::lines_cleared++;
    Board::CheckBoardForCompletedRow();
}

void Board::CheckBoardForCompletedRow() {
    for (int r = 0; r < kStandardHeight; r++) {
        if (Board::CanRemoveRow(r)) {
            Board::RemoveRow(r);
            return;
        }
    }
}

bool Board::IsGameOver() {
    for (int c = 0; c < kStandardWidth; c++) {
        if (board[0][c] == true) {
            return true;
        }
    }
    return false;
}
