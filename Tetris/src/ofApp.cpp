#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    default_song = "game_music.mp3";
    
    game_music.load(default_song);
    game_music.setLoop(true);
    game_music.play();
    
    
    buffer.allocate(ofGetWindowWidth(), ofGetWindowHeight());
    buffer.begin();
    ofSetBackgroundColor(240, 255, 255);
    
    ofSetColor(0, 0, 0);
    int board_width = Block::kSideLength * Board::kStandardWidth;
    int board_height = Block::kSideLength * Board::kStandardHeight;
    int x_origin = 50;
    int y_origin = (ofGetWindowHeight() - board_height) / 2;
    ofDrawRectangle(x_origin, y_origin, board_width, board_height);
    
    ofSetColor(30, 30, 30);
    for (int x = x_origin; x < x_origin + board_width; x += Block::kSideLength) {
        ofDrawLine(x, y_origin, x, y_origin + board_height);
    }
    for (int y = y_origin; y < y_origin + board_height; y += Block::kSideLength) {
        ofDrawLine(x_origin, y, x_origin + board_width, y);
    }
    
    Board::GenerateTetromino(x_origin, y_origin);
    
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
