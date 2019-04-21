#pragma once

#include "ofMain.h"
#include "ofxJSON.h"
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
    
        // JSON
        ofxJSONElement seoulJSON;
        ofxJSONElement nycJSON;
    
        //gui options
        ofxFloatSlider seoulBackground; // background colors
        ofxFloatSlider nycBackground;
    
        ofxIntSlider seoulCloudiness; //number of clouds
        ofxIntSlider nycCloudiness;
    
        ofxFloatSlider seoulBlurriness; // opacity of clouds = humidity.
        ofxFloatSlider nycBlurriness;
    
        ofxFloatSlider seoulWindSpeed; // windspeed;
        ofxFloatSlider nycWindSpeed;
    
        // current sun position
        ofxIntSlider seoulSunPosition;
        ofxIntSlider nycSunPosition;
    
        ofxIntSlider seoulSunVisibility;
        ofxIntSlider nycSunVisibility;
    
        ofxIntSlider nextDays;
//        ofxIntSlider circleResolution;
    
    
        ofxPanel gui;
    
        // IMAGES
        ofImage cloud;
};
