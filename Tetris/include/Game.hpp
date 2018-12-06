//
//  Game.hpp
//  Tetris
//
//  Created by Julie Dosher on 11/15/18.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>

class Game {
    
public:
    static int current_level;
    static int score;
    static int lines_cleared;
    
    static double falling_speed;
    static constexpr double level_multiplier = 0.05;
    
};

#endif /* Game_hpp */
