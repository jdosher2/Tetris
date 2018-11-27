//
//  score_tracker.hpp
//  Tetris
//
//  Created by Julie Dosher on 11/27/18.
//

#ifndef score_tracker_hpp
#define score_tracker_hpp

#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>

class ScoreTracker {
public:
    static const int kNumTopScores = 10;
    static const std::string kFileToScoreUsers;
    static const std::string kFileToStoreScores;

    static std::string DisplayTopScores();
    static std::string DisplayPlayerScore();
    static void ReadPreviousTopScores(std::string score_file);
    static void SetNewTopScores(int current_game_score);
    static void WriteTopScoresToFile(std::string score_file);


private:
    static void SortTopScores();
};

#endif /* score_tracker_hpp */
