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
//    void skirtSpeedChange(float & skirtMove);
//
// --------- Used for main drawings
    ofTrueTypeFont bebasSmall;
    ofTrueTypeFont bebasBig;
    ofTrueTypeFont decorative;
// travel map
    ofImage travelMap;
// first scene images;
    ofImage worldMap, pointingHand,Xmark;
    
// second scene images;
    ofImage thoughtBubble;
    
// third scene images
    ofImage soju, koreanAir, deltaAir, ramen, samsung, lg, kimchi;
    
// fourth scene images
    ofImage cursor, koreanFlag;
    
// fifth scene images
    ofImage korea1, korea2, korea3, korea4, korea5, korea6, korea7, korea8, letterExample;
    ofImage koreaImages[8] = {korea1, korea2, korea3, korea4, korea5, korea6, korea7, korea8};
    
    ofImage starbucks, microsoft, costco, spaceneedle, boeing;
    ofImage seattleImages[5] = {starbucks, microsoft, costco, spaceneedle, boeing};
// seventh scene
    
// nineth scene images
    ofImage leave1, leave2, leave3, leave4, leave5, leave6, leave7, tulip1, tulip2, tulip3, tulip4;
    ofImage tulipImages[4] = {tulip1, tulip2, tulip3, tulip4};
    ofImage leaveImages[7] = {leave1, leave2, leave3, leave4, leave5, leave6, leave7};
// tenth scene images
    ofImage snowboarding, pineTree;
    
// thirteenth scene images
    ofImage moma, metrocard, iloveny, yellowCab, liberty;
    
// fourteenth scene
    ofImage earth, airplaneLast;
    
//    ofImage newyorkImages[5] = {moma, metrocard, iloveny, yelloCab, liberty};
    
    ofSoundPlayer arirang;
    ofSoundPlayer bird;
    ofSoundPlayer twinkle;
    ofSoundPlayer yay;
    

    // gui options.
    ofxVec2Slider position;
    ofxIntSlider skirtMove;
    ofxToggle smile;
    ofxIntSlider hairResolution;
    ofxColorSlider color;
    ofxPanel gui;
    
    float width, height;
    float midX, midY;
};
