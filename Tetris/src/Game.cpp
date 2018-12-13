//
//  Game.cpp
//  Tetris
//
//  Created by Julie Dosher on 11/15/18.
//

#include "Game.hpp"

Game::GameState Game::current_state = Game::IN_PROGRESS;

int Game::current_level = 1;
int Game::score = 0;
bool Game::was_level_set = false;
bool Game::was_score_increased = false;

int Game::lines_cleared = 0;
int Game::falling_speed = 1;
int Game::num_of_tetrominoes_created = 0;


void Game::UpdateLevel() {
    if (score != 0) {
        if (Game::score % 400 == 0) {
            if (!Game::was_level_set) {
                Game::current_level++;
                Game::was_level_set = true;
            }
        } else {
            Game::was_level_set = false;
        }
    }
    
    if (num_of_tetrominoes_created != 0) {
        if (num_of_tetrominoes_created % 5 == 0) {
            if (!Game::was_score_increased) {
                Game::score += Game::tetromino_score;
                Game::was_score_increased = true;
            }
        } else {
            Game::was_score_increased = false;
        }
    }
}
