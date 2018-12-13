#pragma once

#include "ofMain.h"
#include "Block.hpp"
#include "Board.hpp"
#include "Game.hpp"

class ofApp : public ofBaseApp{
    
public:
    std::string default_song;
    ofSoundPlayer game_music;
    
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
    const int board_width = Block::kSideLength * Board::kStandardWidth;
    const int board_height = Block::kSideLength * Board::kStandardHeight;
    const int x_origin = 50;
    const int y_origin = (ofGetWindowHeight() - board_height) / 2;
    
    const int preview_board_width = 210;
    const int preview_board_height = 210;
    const int preview_x_origin = (((x_origin + board_width + ofGetWindowWidth()) / 2)  - 100);
    const int preview_y_origin = y_origin + (12 * Block::kSideLength);
    
    const int label_x_start = ((x_origin + board_width + ofGetWindowWidth()) / 2)  - 100;
    const int placeholder_x_start = ((x_origin + board_width + ofGetWindowWidth()) / 2) + 10;
    const int score_text_start = ((x_origin + board_width + ofGetWindowWidth()) / 2) + 20;
    
    const int paused_x_offset = 150;
    const int paused_y_offset = 100;
    const int unpause_text_y_offset = 200;
    const int exit_text_y_offset = 300;
    
    const int game_over_x_offset = 140;
    const int game_over_y_offset = 100;
    const int score_text_y_offset = 200;
    const int reset_text_y_offset = 300;
    
    
    void DrawNormalBackground();
    void DrawPausedBackground();
    void DrawGameOverBackground();
    void DrawGridlines();
    void DrawText();
    void DrawScoreText();
};


