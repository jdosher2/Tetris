#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    default_song = "game_music.mp3";
    game_music.load(default_song);
    game_music.setLoop(true);
    game_music.play();
    
    Board::InitBoard();
    
    ofSetFrameRate(2);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofApp::DrawNormalBackground();
    ofApp::DrawText();
    ofApp::DrawScoreText();
    
    if (active_tetromino.size() == 0) {
        if (waiting_tetromino.size() < 1) {
            active_tetromino.push_back(Board::GenerateTetromino(Tetromino::State::FALLING));
            waiting_tetromino.push_back(Board::GenerateTetromino(Tetromino::State::WAITING));
                
        } else {
            active_tetromino.clear();
            active_tetromino.push_back(waiting_tetromino[0]);
            waiting_tetromino.clear();
            waiting_tetromino.push_back(Board::GenerateTetromino(Tetromino::State::WAITING));
        }
            
        Board::PlaceTetrominoInBoard(active_tetromino[0], 0, 3);
    }
    
    
    if (Game::current_state == Game::GameState::IN_PROGRESS) {
        Board::IsGameOver();
        Board::Fall();
        Board::DrawWaitingTetromino(preview_x_origin, preview_y_origin, preview_board_width, preview_board_height, Block::kPreviewSideLength);
        
    }
    
    Board::DrawBoard(x_origin, y_origin, board_width, board_height, Block::kSideLength);
    ofApp::DrawGridlines();
    
    if (Game::current_state == Game::GameState::PAUSED) {
        ofApp::DrawPausedBackground();
    }
    
    if (Game::current_state == Game::GameState::FINISHED) {
        ofApp::DrawGameOverBackground();
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
void ofApp::DrawGameOverBackground() {
    ofSetColor(ofColor::black);
    ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
    
    ofSetColor(ofColor::white);
    game_font.load("azonix.otf", 40);
    game_font.drawString("game over", game_over_x_offset, game_over_y_offset);
    game_font.load("azonix.otf", 22);
    game_font.drawString("your score: " + std::to_string(Game::score), game_over_x_offset, score_text_y_offset);
    game_font.drawString("press 'r' to play again", game_over_x_offset, reset_text_y_offset);
}


//--------------------------------------------------------------
void ofApp::DrawPausedBackground() {
    ofSetColor(ofColor::black);
    ofDrawRectangle(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
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
        if (Game::current_state == Game::IN_PROGRESS) {
            // pause
            Game::current_state = Game::PAUSED;
            game_music.setPaused(true);
            
        } else if (Game::current_state == Game::PAUSED){
            // unpause
            Game::current_state = Game::IN_PROGRESS;
            game_music.setPaused(false);
        }
    }
    
    if (Game::current_state == Game::GameState::IN_PROGRESS) {
         if (lower_key == 'w' || key == OF_KEY_UP) {
             Board::RotateActiveTetromino();
            
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
    
    if (Game::current_state == Game::GameState::FINISHED) {
        if (lower_key == 'r') {
            Board::InitBoard();
        }
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
