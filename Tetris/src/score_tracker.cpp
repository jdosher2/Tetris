//
//  score_tracker.cpp
//  Tetris
//
//  Created by Julie Dosher on 11/27/18.
//

#include "score_tracker.hpp"

const std::string ScoreTracker::kFileToScoreUsers = "/Users/julie/Downloads/of_v0.10.1_osx_release/apps/myApps/finalproject-jdosher2/Tetris/build/saved_players.txt";
const std::string ScoreTracker::kFileToStoreScores = "/Users/julie/Downloads/of_v0.10.1_osx_release/apps/myApps/finalproject-jdosher2/Tetris/build/saved_scores.txt";

int top_scores[ScoreTracker::kNumTopScores];

void ScoreTracker::ReadPreviousTopScores(std::string score_file) {
    std::ifstream input;
    int score;
    input.open(score_file);
    
    int i = 0;
    while (input >> score && i < ScoreTracker::kNumTopScores) {
        top_scores[i] = score;
        i++;
    }
    input.close();
}

void ScoreTracker::SortTopScores() {
    std::sort(std::begin(top_scores), std::end(top_scores), std::greater<int>());
}

void ScoreTracker::SetNewTopScores(int current_game_score) {
    if (current_game_score > top_scores[ScoreTracker::kNumTopScores - 1]) {
        top_scores[ScoreTracker::kNumTopScores - 1] = current_game_score;
    }
    ScoreTracker::SortTopScores();
}

std::string ScoreTracker::DisplayTopScores() {
    // TODO
    
    return "";
}


void ScoreTracker::WriteTopScoresToFile(std::string score_file) {
    std::ofstream output(score_file);
    
    for (int i = 0; i < ScoreTracker::kNumTopScores; i++) {
        output << std::to_string(top_scores[i]) << std::endl;
    }
    output.close();
}


