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
    
    static Tetromino tetromino_I;
    static Tetromino tetromino_J;
    static Tetromino tetromino_L;
    static Tetromino tetromino_O;
    static Tetromino tetromino_S;
    static Tetromino tetromino_T;
    static Tetromino tetromino_Z;
    
    static void InitBoard();
    
    
    static Tetromino GenerateTetromino(int x_origin, int y_origin, int block_side_length, Tetromino::State t_state);
    //static Tetromino GenerateTetromino(Tetromino::State t_state);
    //static void DrawToBoard(Tetromino tetromino_to_draw, int x_origin, int y_origin, int block_side_length);
    static void Fall(int x_origin, int y_origin);
    static void MoveActiveTetromino(Tetromino::Direction direction, int x_origin, int y_origin); 
    static void CheckBoardForCompletedRow();
    
    
private:
    static const int board_x_entry_point = 3;
    
    static ofColor SelectColor(Tetromino tetromino);
    static bool CanFall();
    static bool CanRemoveRow(int row);
    static void RemoveRow(int row);
    static bool IsGameOver();
};

extern std::vector<Tetromino> all_created_tetrominoes;
extern ofColor board[Board::kStandardHeight][Board::kStandardWidth];
extern Tetromino possible_tetrominoes[Tetromino::num_of_tetrominoes];
extern ofColor possible_colors[Tetromino::num_of_tetrominoes];

#endif /* Board_hpp */
