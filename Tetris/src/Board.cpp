//
//  Board.cpp
//  Tetris
//
//  Created by Julie Dosher on 11/15/18.
//

#include "Board.hpp"

bool board[Board::kStandardHeight][Board::kStandardWidth] = {};

Tetromino Board::tetromino_I = *new Tetromino('I', shape_I, ofColor::cyan, Tetromino::State::INACTIVE);
Tetromino Board::tetromino_J = *new Tetromino('J', shape_J, ofColor::blue, Tetromino::State::INACTIVE);
Tetromino Board::tetromino_L = *new Tetromino('L', shape_L, ofColor::orange, Tetromino::State::INACTIVE);

Tetromino possible_tetrominoes[] = {Board::tetromino_I, Board::tetromino_J, Board::tetromino_L};


void Board::InitBoard() {
    for (int r = 0; r < kStandardHeight; r++) {
        for (int c = 0; c < kStandardWidth; c++) {
            board[r][c] = false;
        }
    }
}

Tetromino Board::GenerateTetromino(int x1, int y1) {
    int random_index = rand() % sizeof(possible_tetrominoes);
    
    int x = x1;
    int y = y1;
    
    Tetromino chosen_tetromino = possible_tetrominoes[random_index];
    std::cout << chosen_tetromino.letter;
    
    ofSetColor(chosen_tetromino.color);
    
    for (int r = 0; r < Tetromino::kTetrominoSize + 1; r++) {
        for (int c = 0; c < Tetromino::kTetrominoSize; c++) {
            if (chosen_tetromino.shape_and_rotations[0][r][c]) {
                ofDrawRectangle(x, y, Block::kSideLength, Block::kSideLength);
            }
            x += Block::kSideLength;
        }
        x = x1;
        y += Block::kSideLength;
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

