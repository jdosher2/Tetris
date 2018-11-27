#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

enum GameState {
        IN_PROGRESS,
        PAUSED,
        FINISHED
};
    
public:
    std::string default_song;
    ofSoundPlayer game_music;
    
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
    
};
