#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    default_song = "game_music.mp3";
    
    game_music.load(default_song);
    game_music.setLoop(true);
    game_music.play();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetBackgroundColor(255, 255, 255);
    
    for (int i = 200; i < 400; i += 20) {
        // grid
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    int lower_key = tolower(key);
    
    if (lower_key == 'p' || key == OF_KEY_ESC) {
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
