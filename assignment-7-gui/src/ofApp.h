#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
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
    
        void hairResolutionChanged(int & hairResolution);
//
//
//    void skirtSpeedChange(float & skirtMove);
//
// --------- Used for main drawings
    ofTrueTypeFont bebas;
    ofTrueTypeFont decorative;
    
    ofSoundPlayer arirang;
    ofSoundPlayer bird;
    ofSoundPlayer twinkle;
    ofSoundPlayer yay;
    
    // define width/height and halves
    float width, height;
    float midX, midY;
    
    
    
    ofxVec2Slider position;
    ofxIntSlider skirtMove;
    ofxToggle smile;
    ofxIntSlider hairResolution;
    ofxColorSlider color;
    ofxPanel gui;
    
};
