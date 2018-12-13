//
//  Board.cpp
//  Tetris
//
//  Created by Julie Dosher on 11/15/18.
//

#include "Board.hpp"

ofColor board[Board::kStandardHeight][Board::kStandardWidth] = {};

int Board::num_of_active_tetrominoes = 0;
int Board::num_of_waiting_tetrominoes = 0;

Tetromino Board::tetromino_I = *new Tetromino('I', shape_I, Tetromino::State::INACTIVE);
Tetromino Board::tetromino_J = *new Tetromino('J', shape_J, Tetromino::State::INACTIVE);
Tetromino Board::tetromino_L = *new Tetromino('L', shape_L, Tetromino::State::INACTIVE);
Tetromino Board::tetromino_O = *new Tetromino('O', shape_O, Tetromino::State::INACTIVE);
Tetromino Board::tetromino_S = *new Tetromino('S', shape_S, Tetromino::State::INACTIVE);
Tetromino Board::tetromino_T = *new Tetromino('T', shape_T, Tetromino::State::INACTIVE);
Tetromino Board::tetromino_Z = *new Tetromino('Z', shape_Z, Tetromino::State::INACTIVE);

Tetromino possible_tetrominoes[Tetromino::num_of_tetrominoes] = {Board::tetromino_I, Board::tetromino_J, Board::tetromino_L, Board::tetromino_O, Board::tetromino_S, Board::tetromino_T, Board::tetromino_Z};

std::vector<Tetromino> active_tetromino;
std::vector<Tetromino> waiting_tetromino;


void Board::InitBoard() {
    for (int r = 0; r < kStandardHeight; r++) {
        for (int c = 0; c < kStandardWidth; c++) {
            board[r][c] = false;
        }
    }
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
            color = ofColor::black;
            break;
    }
    return color;
}


Tetromino Board::GenerateTetromino(Tetromino::State state) {
    int random_index = rand() % Tetromino::num_of_tetrominoes;
    Tetromino chosen_tetromino = possible_tetrominoes[random_index];
    chosen_tetromino.SetState(state);
    
    if (state == Tetromino::State::FALLING) {
        active_tetromino.clear();
        active_tetromino.push_back(chosen_tetromino);
    }
    if (state == Tetromino::State::WAITING) {
        waiting_tetromino.clear();
        waiting_tetromino.push_back(chosen_tetromino);
    }
    
    return chosen_tetromino;
}


Tetromino Board::FindActiveTetromino() {
    
    return Tetromino();
}


Tetromino Board::FindWaitingTetromino() {
    
    return Tetromino();
}


void Board::PlaceTetrominoInBoard(Tetromino tetromino, int row, int column) {
    ofColor chosen_color = Board::SelectColor(tetromino);
    
    int r_b = row;
    int c_b = column;
    int block_count = 0;
    for (int r_t = 0; r_t < Tetromino::kStartingHeight; r_t++) {
        for (int c_t = 0; c_t < Tetromino::kStartingWidth; c_t++) {
            if (tetromino.shape[r_t][c_t]) {
                board[r_b][c_b] = chosen_color;
                tetromino.block_locations[block_count] = std::make_pair(r_b, c_b);
                block_count++;
            }
            c_b++;
        }
        r_b++;
        c_b = column;
    }
    
    active_tetromino.clear();
    active_tetromino.push_back(tetromino);
}


void Board::DrawBoard(int x_board_start, int y_board_start, int width, int height, int block_side_length) {
    int r = 0;
    int c = 0;
    for (int x = x_board_start; x < width + block_side_length; x += block_side_length) {
        for (int y = y_board_start; y < height; y += block_side_length) {
            ofSetColor(board[r][c]);
            ofDrawRectangle(x, y, block_side_length, block_side_length);
            r++;
        }
        r = 0;
        c++;
    }
}


void Board::DrawWaitingTetromino(int x_board_start, int y_board_start, int width, int height, int block_side_length) {
    ofColor color = Board::SelectColor(waiting_tetromino[0]);
    ofSetColor(color);
    
    int x = x_board_start + (2 * block_side_length);
    int y = y_board_start + (3 * block_side_length);
    
    for (int r_t = 0; r_t < Tetromino::kStartingHeight; r_t++) {
        for (int c_t = 0; c_t < Tetromino::kStartingWidth; c_t++) {
            if (waiting_tetromino[0].shape[r_t][c_t]) {
                ofDrawRectangle(x, y, block_side_length, block_side_length);
            }
            x += block_side_length;
        }
        y += block_side_length;
        x = x_board_start + (2 * block_side_length);
    }
}


void Board::Fall() {
    if (Board::CanFall()) {
        Tetromino falling_tetromino = active_tetromino[0];
        ofColor color = Board::SelectColor(falling_tetromino);
            
        for (int block = 0; block < Tetromino::kTetrominoSize; block++) {
            // set each block to black fill
            int r = falling_tetromino.block_locations[block].first;
            int c = falling_tetromino.block_locations[block].second;
            board[r][c] = ofColor::black;
        }
            
        for (int block = 0; block < Tetromino::kTetrominoSize; block++) {
            // move each block 1 space down by changing fill color
            int r = falling_tetromino.block_locations[block].first + 1;
            int c = falling_tetromino.block_locations[block].second;
            active_tetromino[0].block_locations[block] = std::make_pair(r, c);
            board[r][c] = color;
        }
    }
}


void Board::FastFall() {
    while (Board::CanFall()) {
        Board::Fall();
    }
}


void Board::MoveActiveTetromino(Tetromino::Direction direction) {
    if (Board::CanMove(direction)) {
        Tetromino falling_tetromino = active_tetromino[0];
      
        ofColor color = Board::SelectColor(falling_tetromino);

        for (int block = 0; block < Tetromino::kTetrominoSize; block++) {
            // set each block to black fill
            int r = falling_tetromino.block_locations[block].first;
            int c = falling_tetromino.block_locations[block].second;
            board[r][c] = ofColor::black;
        }
            
        for (int block = 0; block < Tetromino::kTetrominoSize; block++) {
            // move each block over 1 space by changing fill color
            int r = falling_tetromino.block_locations[block].first;
            int c = falling_tetromino.block_locations[block].second + direction;
            active_tetromino[0].block_locations[block] = std::make_pair(r, c);
            board[r][c] = color;
        }
    }
}


void Board::RotateActiveTetromino() {
    Tetromino falling_tetromino = active_tetromino[0];
    ofColor color = Board::SelectColor(falling_tetromino);
    
    int pivot_block_r = falling_tetromino.block_locations[1].first;
    int pivot_block_c = falling_tetromino.block_locations[1].second;
    int r_increment;
    int c_increment;
    
    for (int block = 0; block < Tetromino::kTetrominoSize; block++) {
        // set each block to black fill
        int r = falling_tetromino.block_locations[block].first;
        int c = falling_tetromino.block_locations[block].second;
        board[r][c] = ofColor::black;
    }
    
    for (int block = 0; block < Tetromino::kTetrominoSize; block++) {
        // find new block locations
        r_increment = pivot_block_c - falling_tetromino.block_locations[block].second;
        c_increment = pivot_block_r - falling_tetromino.block_locations[block].first;
        int r = pivot_block_r - r_increment;
        int c = pivot_block_c + c_increment;
        active_tetromino[0].block_locations[block] = std::make_pair(r, c);
        board[r][c] = color;
    }
    
}


int Board::GetLowestPoint(Tetromino tetromino) {
    int lowest_row = 0;
    for (int block = 0; block < Tetromino::kTetrominoSize; block++) {
        if (tetromino.block_locations[block].first > lowest_row) {
            lowest_row = tetromino.block_locations[block].first;
        }
    }
    return lowest_row;
}


bool Board::CanFall() {
    for (int block = 0; block < Tetromino::kTetrominoSize; block++) {
        if (active_tetromino[0].block_locations[block].first == Board::kStandardHeight - 1) {
            active_tetromino[0].SetState(Tetromino::State::INACTIVE);
            active_tetromino.clear();
            return false;
        }
                
        if (active_tetromino[0].block_locations[block].first == Board::GetLowestPoint(active_tetromino[0])) {
            if (board[active_tetromino[0].block_locations[block].first + 1][active_tetromino[0].block_locations[block].second] != ofColor::black) {
                active_tetromino[0].SetState(Tetromino::State::INACTIVE);
                active_tetromino.clear();
                return false;
            }
        }
    }
    
    return true;
}


bool Board::CanMove(Tetromino::Direction direction) {
    for (int block = 0; block < Tetromino::kTetrominoSize; block++) {
        int c = active_tetromino[0].block_locations[block].second;
            if (c + direction < 0 || c + direction > Board::kStandardWidth - 1) {
                return false;
            }
        }
   
    return true;
}


bool Board::CanRemoveRow(int row) {
    for (int c = 0; c < kStandardWidth; c++) {
        if (board[row][c] == ofColor::black) {
            return false;
        }
    }
    return true;
}


void Board::RemoveRow(int row) {
    // clear row
    for (int c = 0; c < kStandardWidth; c++) {
        board[row][c] = ofColor::black;
    }
    
    // collapse rows above
    for (int c = 0; c < kStandardWidth; c++) {
        for (int r = row; r > 0; r--) {
            board[r][c] = board[r - 1][c];
        }
    }
    
    Game::lines_cleared++;
    Game::score += Game::line_score;
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
        if (board[0][c] != ofColor::black && !Board::CanFall()) {
            std::cout << "DONE " << "c: " << c << ". color: " << board[0][c] << '\n' << std::endl;
            Game::current_state = Game::FINISHED;
            return true;
        }
    }
    return false;
}
