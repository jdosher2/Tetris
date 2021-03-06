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
    static int num_of_active_tetrominoes;
    static int num_of_waiting_tetrominoes;
    
    static Tetromino tetromino_I;
    static Tetromino tetromino_J;
    static Tetromino tetromino_L;
    static Tetromino tetromino_O;
    static Tetromino tetromino_S;
    static Tetromino tetromino_T;
    static Tetromino tetromino_Z;
    
    static void InitBoard();
    static Tetromino GenerateTetromino(Tetromino::State state);
    static void PlaceTetrominoInBoard(Tetromino tetromino, int row, int column);
    static void DrawBoard(int x_board_start, int y_board_start, int width, int height, int block_side_length);
    static void DrawWaitingTetromino(int x_board_start, int y_board_start, int width, int height, int block_side_length);
    static void Fall();
    static void FastFall();
    static void MoveActiveTetromino(Tetromino::Direction direction);
    static void RotateActiveTetromino();
    static void CheckBoardForCompletedRow();
    static bool IsGameOver();
    
    
private:
    static ofColor SelectColor(Tetromino tetromino);
    static int GetLowestPoint(Tetromino tetromino);
    static bool CanFall();
    static bool CanMove(Tetromino::Direction direction);
    static bool CanRotate();
    static bool CanRemoveRow(int row);
    static void RemoveRow(int row);
};

extern std::vector<Tetromino> active_tetromino;
extern std::vector<Tetromino> waiting_tetromino;

extern ofColor board[Board::kStandardHeight][Board::kStandardWidth];
extern Tetromino possible_tetrominoes[Tetromino::num_of_tetrominoes];


#endif /* Board_hpp */
