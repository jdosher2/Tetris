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
        IN_PROGRESS = 1,
        PAUSED = 2,
        FINISHED = 3
    };
    
    static GameState current_state;
    static int current_level;
    static int score;
    static int lines_cleared;
    static bool was_level_set;
    static bool was_score_increased;
    
    static int falling_speed;
    constexpr static const float starting_falling_speed = 1.0;
    constexpr static const float falling_speed_increment = 0.1; // 0.05 sec
    static const int line_score = 100;
    static const int tetromino_score = 50;
    static int num_of_tetrominoes_created;
    
    
    static void UpdateLevel();
};


#endif /* Game_hpp */
