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
    std::cout << tetromino.letter << std::endl;
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

 Tetromino Board::GenerateTetromino(int x_origin, int y_origin, int block_side_length, Tetromino::State t_state) {
 
     int random_index = rand() % Tetromino::num_of_tetrominoes;
     Tetromino chosen_tetromino = possible_tetrominoes[random_index];
     ofColor chosen_color = Board::SelectColor(chosen_tetromino);
     ofSetColor(chosen_color);
     
     chosen_tetromino.SetState(t_state);
     
     int x = x_origin;
     int y = y_origin;
     int r_b = Board::board_x_entry_point;
     int c_b = 1;
     int block_count = 0;
     
     for (int r_t = 2; r_t < 4; r_t++) {
         for (int c_t = 1; c_t < 5; c_t++) {
             if (chosen_tetromino.shape_and_rotations[0][r_t][c_t]) {
                 board[r_b][c_b] = chosen_color;
                 ofDrawRectangle(x_origin + (r_b * block_side_length), y_origin + (c_b * block_side_length), block_side_length, block_side_length);
                 chosen_tetromino.block_locations[block_count] = std::make_pair(r_b, c_b);
                 block_count++;
            }
            r_b++;
            }
            r_b = Board::board_x_entry_point;
            c_b++;
    }
    all_created_tetrominoes.push_back(chosen_tetromino);
     
    return chosen_tetromino;
}
 
 void Board::Fall(int x_origin, int y_origin) {
     for (int i = 0; i < all_created_tetrominoes.size(); i++) {
         if (all_created_tetrominoes[i].GetState() == Tetromino::State::FALLING) {
             ofColor color = Board::SelectColor(all_created_tetrominoes[i]);
             
             int x;
             int original_y;
         
             for (int block = 0; block < Tetromino::kTetrominoSize; block++) {
                 // check original location/color
                 std::pair<int, int> original_block_location = all_created_tetrominoes[i].block_locations[block];
                 x = original_block_location.first;
                 original_y = original_block_location.second;
                 board[x][original_y] = ofColor::black;
                 ofSetColor(ofColor::black);
                 ofDrawRectangle(x_origin + (x * Block::kSideLength), y_origin + (original_y * Block::kSideLength), Block::kSideLength, Block::kSideLength);
                 }
             
             for (int block = 0; block < Tetromino::kTetrominoSize; block++) {
                 // move each block down 1 space by changing fill color
                 std::pair<int, int> original_block_location = all_created_tetrominoes[i].block_locations[block];
                 x = original_block_location.first;
                 original_y = original_block_location.second;
                 all_created_tetrominoes[i].block_locations[block] = std::make_pair(x, original_y + 1);
                 board[x][original_y + 1] = color;
                 ofSetColor(color);
                 ofDrawRectangle(x_origin + (x * Block::kSideLength), y_origin + ((original_y + 1) * Block::kSideLength), Block::kSideLength, Block::kSideLength);
            }
         }
     }
 }

void Board::MoveActiveTetromino(Tetromino::Direction direction, int x_origin, int y_origin) {
    for (int i = 0; i < all_created_tetrominoes.size(); i++) {
        if (all_created_tetrominoes[i].GetState() == Tetromino::State::FALLING) {
            ofColor color = Board::SelectColor(all_created_tetrominoes[i]);
            
            int original_x;
            int y;
            
            for (int block = 0; block < Tetromino::kTetrominoSize; block++) {
                // check original location/color
                std::pair<int, int> original_block_location = all_created_tetrominoes[i].block_locations[block];
                original_x = original_block_location.first;
                y = original_block_location.second;
                board[original_x][y] = ofColor::black;
                ofSetColor(ofColor::black);
                ofDrawRectangle(x_origin + (original_x * Block::kSideLength), y_origin + (y * Block::kSideLength), Block::kSideLength, Block::kSideLength);
            }
            
            for (int block = 0; block < Tetromino::kTetrominoSize; block++) {
                // move each block down 1 space by changing fill color
                std::pair<int, int> original_block_location = all_created_tetrominoes[i].block_locations[block];
                original_x = original_block_location.first;
                y = original_block_location.second;
                all_created_tetrominoes[i].block_locations[block] = std::make_pair(original_x + direction, y);
                board[original_x + direction][y] = color;
                ofSetColor(color);
                ofDrawRectangle(x_origin + ((original_x + direction) * Block::kSideLength), y_origin + ((y) * Block::kSideLength), Block::kSideLength, Block::kSideLength);
            }
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
