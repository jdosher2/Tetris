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
int Game::lines_cleared = 0;
int Game::falling_speed = 1000;


void Game::UpdateLevel() {
    if (score != 0) {
        if (Game::score % 1000 == 0) {
            if (!Game::was_level_set) {
                Game::current_level++;
                Game::was_level_set = true;
            }
        } else {
            Game::was_level_set = false;
        }
    }
}
