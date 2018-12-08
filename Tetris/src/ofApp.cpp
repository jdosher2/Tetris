#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    default_song = "game_music.mp3";
    game_music.load(default_song);
    game_music.setLoop(true);
    game_music.play();
    
    Board::InitBoard();
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofApp::DrawNormalBackground();
    ofApp::DrawText();
    ofApp::DrawScoreText();
    
    Tetromino falling_tetromino;
    Tetromino waiting_tetromino;
    
    if (Board::num_of_active_tetrominoes == 0) {
        Board::num_of_active_tetrominoes++;
        Board::GenerateTetromino(Tetromino::State::FALLING, 1, 3);
        //waiting_tetromino = Board::GenerateTetromino(Tetromino::State::WAITING, 2, 2);
    }
    
    Board::DrawTetrominoes(x_origin, y_origin, board_width, board_height, Block::kSideLength);
    ofApp::DrawGridlines();

    if (ofGetElapsedTimeMillis() % Game::falling_speed < 20) {
        Board::Fall();
        Board::CheckBoardForCompletedRow();
        Board::DrawTetrominoes(x_origin, y_origin, board_width, board_height, Block::kSideLength);
        ofApp::DrawGridlines();
    }
}

//--------------------------------------------------------------
void ofApp::DrawNormalBackground() {
    ofSetColor(ofColor::slateGray);
    ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    ofSetColor(ofColor::black);
    ofDrawRectangle(x_origin, y_origin, board_width, board_height);
}

//--------------------------------------------------------------
void ofApp::DrawPausedBackground() {
    
}

//--------------------------------------------------------------
void ofApp::DrawGridlines() {
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
}

//--------------------------------------------------------------
void ofApp::DrawText() {
    ofSetColor(ofColor::white);
    game_font.load("zian.ttf", 40);
    game_font.drawString("tetris", ((x_origin + board_width + ofGetWindowWidth()) / 2)  - 100, y_origin + Block::kSideLength);
    
    game_font.load("zian.ttf", 20);
    game_font.drawString("level", label_x_start, y_origin + (3 * Block::kSideLength));
    game_font.drawString("score", label_x_start, y_origin + (5 * Block::kSideLength));
    game_font.drawString("lines", label_x_start, y_origin + (7 * Block::kSideLength));
    game_font.drawString("next", label_x_start, y_origin + (12 * Block::kSideLength) - 10);
}

//--------------------------------------------------------------
void ofApp::DrawScoreText() {
    Game::UpdateLevel();
    
    ofSetColor(ofColor::black);
    ofDrawRectangle(placeholder_x_start, y_origin + (3 * Block::kSideLength) + 5, 100, - Block::kSideLength * 0.9 - 5);    // level
    ofDrawRectangle(placeholder_x_start, y_origin + (5 * Block::kSideLength) + 5, 100, - Block::kSideLength * 0.9 - 5);    // score
    ofDrawRectangle(placeholder_x_start, y_origin + (7 * Block::kSideLength) + 5, 100, - Block::kSideLength * 0.9 - 5);    // lines
    ofDrawRectangle(label_x_start, y_origin + (12 * Block::kSideLength), 210, 210); // next box
    
    ofSetColor(ofColor::white);
    game_font.load("azonix.otf", 22);
    game_font.drawString(std::to_string(Game::current_level), score_text_start, y_origin + (3 * Block::kSideLength));
    game_font.drawString(std::to_string(Game::score), score_text_start, y_origin + (5 * Block::kSideLength));
    game_font.drawString(std::to_string(Game::lines_cleared), score_text_start, y_origin + (7 * Block::kSideLength));
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
        Board::MoveActiveTetromino(Tetromino::Direction::LEFT);
        
    } else if (lower_key == 'd' || key == OF_KEY_RIGHT) {
        Board::MoveActiveTetromino(Tetromino::Direction::RIGHT);
        
    } else if (lower_key == 's' || key == OF_KEY_DOWN) {
        // fall faster
        
    } else if (key == ' ') {
        Board::FastFall();
        
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
