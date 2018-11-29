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
#include "Tetromino.hpp"

#include <stdio.h>

class Board {
    
public:
    static const int kStandardHeight = 20;
    static const int kStandardWidth = 10;
    
    static Tetromino tetromino_I;
    static Tetromino tetromino_J;
    static Tetromino tetromino_L;
    
    static void InitBoard();
    static Tetromino GenerateTetromino(int x1, int y1);
    static void CheckBoardForCompletedRow();
    
    
private:
    static bool CanRemoveRow(int row);
    static void RemoveRow(int row);
    static bool IsGameOver();
};


extern bool board[Board::kStandardHeight][Board::kStandardWidth];
extern Tetromino possible_tetrominoes[];

#endif /* Board_hpp */
