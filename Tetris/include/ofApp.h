#pragma once

#include "ofMain.h"
#include "Block.hpp"
#include "Board.hpp"
#include "Game.hpp"

class ofApp : public ofBaseApp{

enum GameState {
        IN_PROGRESS,
        PAUSED,
        FINISHED
};
    
public:
    std::string default_song;
    ofSoundPlayer game_music;
    
    ofFbo buffer;
    ofTrueTypeFont game_font;
    
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
		
private:
    GameState current_state = IN_PROGRESS;
    
    bool is_tetromino_falling = false;
    
    const int board_width = Block::kSideLength * Board::kStandardWidth;
    const int board_height = Block::kSideLength * Board::kStandardHeight;
    const int x_origin = 50;
    const int y_origin = (ofGetWindowHeight() - board_height) / 2;
    
    const int preview_board_width = 210;
    const int preview_board_height = 210;
    const int preview_x_origin = (((x_origin + board_width + ofGetWindowWidth()) / 2)  - 100);
    const int preview_y_origin = y_origin + (12 * Block::kSideLength);
    
    
    void DrawNormalBackground();
    void DrawPausedBackground();
    void UpdateScoreText();
};


