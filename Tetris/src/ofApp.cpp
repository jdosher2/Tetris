#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    default_song = "game_music.mp3";
    
    game_music.load(default_song);
    game_music.setLoop(true);
    game_music.play();
    
    
    buffer.allocate(ofGetWindowWidth(), ofGetWindowHeight());
    buffer.begin();
    
    
    // background
    ofSetColor(ofColor::slateGray);
    ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    
    // placeholders
    ofSetColor(ofColor::black);
    ofDrawRectangle(((x_origin + board_width + ofGetWindowWidth()) / 2) + 10, y_origin + (3 * Block::kSideLength), 100, - Block::kSideLength * 0.9);
    ofDrawRectangle(((x_origin + board_width + ofGetWindowWidth()) / 2) + 10, y_origin + (5 * Block::kSideLength), 100, - Block::kSideLength * 0.9);
    ofDrawRectangle(((x_origin + board_width + ofGetWindowWidth()) / 2) + 10, y_origin + (7 * Block::kSideLength), 100, - Block::kSideLength * 0.9);
    ofDrawRectangle(((x_origin + board_width + ofGetWindowWidth()) / 2)  - 100, y_origin + (12 * Block::kSideLength), 210, 210);
    
    
    // text
    ofSetColor(ofColor::white);
    game_font.load("zian.ttf", 40);
    game_font.drawString("tetris", ((x_origin + board_width + ofGetWindowWidth()) / 2)  - 100, y_origin + Block::kSideLength);
    
    game_font.load("zian.ttf", 20);
    game_font.drawString("level", ((x_origin + board_width + ofGetWindowWidth()) / 2)  - 100, y_origin + (3 * Block::kSideLength));
    game_font.drawString("score", ((x_origin + board_width + ofGetWindowWidth()) / 2)  - 100, y_origin + (5 * Block::kSideLength));
    game_font.drawString("lines", ((x_origin + board_width + ofGetWindowWidth()) / 2)  - 100, y_origin + (7 * Block::kSideLength));
    game_font.drawString("next", ((x_origin + board_width + ofGetWindowWidth()) / 2)  - 100, y_origin + (12 * Block::kSideLength) - 10);
    
    
    // playing board
    ofSetColor(ofColor::black);
    ofDrawRectangle(x_origin, y_origin, board_width, board_height);
    
    
    // pieces
    Board::GenerateTetromino(x_origin + (2 * Block::kSideLength), y_origin - Block::kSideLength, Block::kSideLength);
    Board::GenerateTetromino(((x_origin + board_width + ofGetWindowWidth()) / 2)  - 100 + Block::kPreviewSideLength, y_origin + (12 * Block::kSideLength) + Block::kPreviewSideLength, Block::kPreviewSideLength);
    
    
    // gridlines
    ofSetColor(30, 30, 30);
    for (int x = x_origin; x < x_origin + board_width; x += Block::kSideLength) {
        ofDrawLine(x, y_origin, x, y_origin + board_height);
    }
    for (int y = y_origin; y < y_origin + board_height; y += Block::kSideLength) {
        ofDrawLine(x_origin, y, x_origin + board_width, y);
    }
    
    for (int x = preview_x_origin; x < preview_x_origin + preview_board_width; x += Block::kPreviewSideLength) {
        ofDrawLine(x, preview_y_origin, x, preview_y_origin + preview_board_height);
    }
    for (int y = preview_y_origin; y < preview_y_origin + preview_board_height; y += Block::kPreviewSideLength) {
        ofDrawLine(preview_x_origin, y, preview_x_origin + preview_board_width, y);
    }
    
    
    
    buffer.end();
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    buffer.draw(0, 0);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    int lower_key = tolower(key);
    
    if (lower_key == 'p') {
        if (current_state == IN_PROGRESS) {
            // pause
            current_state = PAUSED;
            game_music.setPaused(true);
            
        } else if (current_state == PAUSED){
            // unpause
            current_state = IN_PROGRESS;
            game_music.setPaused(false);
        }
        
    } else if (lower_key == 'w' || key == OF_KEY_UP) {
        // rotate
        
    } else if (lower_key == 'a' || key == OF_KEY_LEFT) {
        // move left
        
    } else if (lower_key == 'd' || key == OF_KEY_RIGHT) {
        // move right
        
    } else if (lower_key == 's' || key == OF_KEY_DOWN) {
        // fall faster
        
    } else if (key == ' ') {
        // fall immediately
        
    }
}


void ofApp::DrawNormalBackground() {
    
}


//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
