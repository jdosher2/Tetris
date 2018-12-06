//
//  Board.hpp
//  Tetris
//
//  Created by Julie Dosher on 11/15/18.
//

#ifndef Board_hpp
#define Board_hpp

#include "ofMain.h"
#include "Block.hpp"
#include "Game.hpp"
#include "Tetromino.hpp"

#include <stdio.h>

class Board {
    
public:
    static const int kStandardHeight = 20;
    static const int kStandardWidth = 10;
    
    static Tetromino active_tetromino;
    static Tetromino waiting_tetromino;
    static Tetromino inactive_tetromino;
    
    static Tetromino tetromino_null;
    static Tetromino tetromino_I;
    static Tetromino tetromino_J;
    static Tetromino tetromino_L;
    static Tetromino tetromino_O;
    static Tetromino tetromino_S;
    static Tetromino tetromino_T;
    static Tetromino tetromino_Z;
    
    static void InitBoard();
    static void InitColors();
    static Tetromino GenerateTetromino(int x1, int y1, int block_side_length, Tetromino::State t_state);
    static void CheckBoardForCompletedRow();
    
    
private:
    static const int board_x_entry_point = 3;
    
    static void DrawTetrominoToWindow();
    static bool CanRemoveRow(int row);
    static void RemoveRow(int row);
    static bool IsGameOver();
};


extern ofColor board[Board::kStandardHeight][Board::kStandardWidth];
extern Tetromino possible_tetrominoes[Tetromino::num_of_tetrominoes];
extern ofColor possible_colors[Tetromino::num_of_tetrominoes];

#endif /* Board_hpp */
