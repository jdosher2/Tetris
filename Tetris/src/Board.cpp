//
//  Board.cpp
//  Tetris
//
//  Created by Julie Dosher on 11/15/18.
//

#include "Board.hpp"

ofColor board[Board::kStandardHeight][Board::kStandardWidth] = {};

Tetromino Board::tetromino_I = *new Tetromino('I', shape_I, Tetromino::State::INACTIVE);
Tetromino Board::tetromino_J = *new Tetromino('J', shape_J, Tetromino::State::INACTIVE);
Tetromino Board::tetromino_L = *new Tetromino('L', shape_L, Tetromino::State::INACTIVE);
Tetromino Board::tetromino_O = *new Tetromino('O', shape_O, Tetromino::State::INACTIVE);
Tetromino Board::tetromino_S = *new Tetromino('S', shape_S, Tetromino::State::INACTIVE);
Tetromino Board::tetromino_T = *new Tetromino('T', shape_T, Tetromino::State::INACTIVE);
Tetromino Board::tetromino_Z = *new Tetromino('Z', shape_Z, Tetromino::State::INACTIVE);

Tetromino possible_tetrominoes[Tetromino::num_of_tetrominoes] = {Board::tetromino_I, Board::tetromino_J, Board::tetromino_L, Board::tetromino_O, Board::tetromino_S, Board::tetromino_T, Board::tetromino_Z};

std::vector<Tetromino> all_created_tetrominoes;


void Board::InitBoard() {
    for (int r = 0; r < kStandardHeight; r++) {
        for (int c = 0; c < kStandardWidth; c++) {
            board[r][c] = false;
        }
    }
    all_created_tetrominoes;
}

ofColor Board::SelectColor(Tetromino tetromino) {
    ofColor color;
    switch (tetromino.letter) {
        case 'I':
            color = ofColor::cyan;
            break;
        case 'J':
            color = ofColor::blue;
            break;
        case 'L':
            color = ofColor::orange;
            break;
        case 'O':
            color = ofColor::yellow;
            break;
        case 'S':
            color = ofColor::green;
            break;
        case 'T':
            color = ofColor::purple;
            break;
        case 'Z':
            color = ofColor::red;
            break;
        default:
            color = ofColor::white;
            break;
    }
    return color;
}


Tetromino Board::GenerateTetromino(Tetromino::State state, int row, int column) {
    int random_index = rand() % Tetromino::num_of_tetrominoes;
    Tetromino chosen_tetromino = possible_tetrominoes[random_index];
    ofColor chosen_color = Board::SelectColor(chosen_tetromino);
    chosen_tetromino.SetState(state);
    
    int r_b = row;
    int c_b = column;
    int block_count = 0;
    for (int r_t = 2; r_t < Tetromino::kTetrominoSize; r_t++) {
        for (int c_t = 1; c_t < Tetromino::kTetrominoSize + 1; c_t++) {
            if (chosen_tetromino.shape_and_rotations[0][r_t][c_t]) {
                board[r_b][c_b] = chosen_color;
                chosen_tetromino.block_locations[block_count] = std::make_pair(r_b, c_b);
                block_count++;
            }
            c_b++;
        }
        r_b++;
        c_b = column;
    }
    
    all_created_tetrominoes.push_back(chosen_tetromino);
    return chosen_tetromino;
}

/*
 playing board:
 x1 = x_origin + 3 * block_side_length
 y1 = y_origin + block_side_length
 r = 1 = y
 c = 3 = x
 
 preview board:
 x1 = prev_x_origin + 2 * block_side_length
 y1 = prev_y_origin + 2 * block_side_length
 r = 2 = y
 c = 2 = x
 */

void Board::DrawTetrominoes(int x_board_start, int y_board_start, int width, int height, int block_side_length) {
    int r = 0;
    int c = 0;
    for (int x = x_board_start; x < width; x += block_side_length) {
        for (int y = y_board_start; y < height; y += block_side_length) {
            ofSetColor(board[r][c]);
            ofDrawRectangle(x, y, block_side_length, block_side_length);
            r++;
        }
        r = 0;
        c++;
    }
}

void Board::Fall() {
    Tetromino falling_tetromino;
    for (int i = 0; i < all_created_tetrominoes.size(); i++) {
        if (all_created_tetrominoes[i].GetState() == Tetromino::State::FALLING) {
            falling_tetromino = all_created_tetrominoes[i];
        }
    
    ofColor color = Board::SelectColor(falling_tetromino);
    
    for (int block = 0; block < Tetromino::kTetrominoSize; block++) {
        int r = falling_tetromino.block_locations[block].first;
        int c = falling_tetromino.block_locations[block].second;
        board[r][c] = ofColor::black;
    }
    
    for (int block = 0; block < Tetromino::kTetrominoSize; block++) {
        int r = falling_tetromino.block_locations[block].first + 1;
        int c = falling_tetromino.block_locations[block].second;
        all_created_tetrominoes[i].block_locations[block] = std::make_pair(r, c);
        board[r][c] = color;
    }
}
}

void Board::MoveActiveTetromino(Tetromino::Direction direction) {
    Tetromino active_tetromino;
    for (int i = 0; i < all_created_tetrominoes.size(); i++) {
        if (all_created_tetrominoes[i].GetState() == Tetromino::State::FALLING) {
            active_tetromino = all_created_tetrominoes[i];
        }
    
        ofColor color = Board::SelectColor(active_tetromino);

        for (int block = 0; block < Tetromino::kTetrominoSize; block++) {
            // check original location/color
            int r = active_tetromino.block_locations[block].first;
            int c = active_tetromino.block_locations[block].second;
            board[r][c] = ofColor::black;
        }
        
        for (int block = 0; block < Tetromino::kTetrominoSize; block++) {
            // move each block down 1 space by changing fill color
            int r = active_tetromino.block_locations[block].first;
            int c = active_tetromino.block_locations[block].second + direction;
            all_created_tetrominoes[i].block_locations[block] = std::make_pair(r, c);
            board[r][c] = color;
        }
    }
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
