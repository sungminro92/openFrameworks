#pragma once

#include "ofMain.h"

class window {
    private:
        int width = 20;  // width
        int height = 157; // height
    public:
        ofColor color; // red? or blue?
        ofPoint pos; // set up position of each window? (x,y)
        bool broken; // is window broken? (advanced level)
        void setup(); // set up at each floor
        void update(); // update to be broken when it gets hit by an ax. (advanced level)
        void draw(); // draw.
        int getX(); // get position of the window
        int getY();
};

class people {
    private:
        int size = 20; // size of the people on the floor
        void distanceSensor(); // distance sensor to window.
    public:
        ofPoint pos; // people's current position
        bool alive = false;
        bool mounted = false;
        bool dropped = false;
        int saved = 670;
        void setup(int idx);
        void update();
        void draw();
        void mountedNow();
//        void savedNow();
        float getX();
        float getY();
        float getR();
};

class character {
    public:
        ofPoint pos;  // charactor position
        bool dead = false;
        void setup();
        void update();
        void draw();
        int getX();
        int getY();
    
};

class floor {
    private:
        int width = 624;
        int height = 157;
    public:
        ofPoint pos;
        void setup();
        void update();
        void draw();
    //    bool burnt
};

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
    

    ofTrueTypeFont title;
    ofTrueTypeFont subtitle;
    ofTrueTypeFont description;
    ofImage instruction1;

};

