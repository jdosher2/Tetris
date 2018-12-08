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
    enum GameState {
        IN_PROGRESS,
        PAUSED,
        FINISHED
    };
    
    static GameState current_state;
    static int current_level;
    static int score;
    static int lines_cleared;
    static bool was_level_set;
    
    static int falling_speed;
    static const int falling_speed_increment = 50; // 0.05 sec
    static const int line_score = 100;
    
    
    static void UpdateLevel();
};


#endif /* Game_hpp */
