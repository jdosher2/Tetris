//
//  Board.hpp
//  Tetris
//
//  Created by Julie Dosher on 11/15/18.
//

#ifndef Board_hpp
#define Board_hpp

#include "ofMain.h"

#include <stdio.h>

class Board {
    
public:
    static void InitBoard();
    static void CheckBoardForCompletedRow();
    
    
private:
    static bool CanRemoveRow(int row);
    static void RemoveRow(int row);
};

static const int kStandardHeight = 20;
static const int kStandardWidth = 10;

extern bool board[kStandardHeight][kStandardWidth];

#endif /* Board_hpp */
