// This game is designed to depict the terrifying moment of natural disaster and to urge and bring on everyone's intuitive sense of bravery and heroism.

#include "ofApp.h"

//bool gameStarted = false;
int stage = 0;
int peopleSaved = 0;

ofColor pink(255,234,231);
ofColor skyBlue(166,206,206);
ofColor darkBlue(128,181, 175);
ofColor red(255,0, 0);
ofColor blue(0,0,255);
ofColor black(0,0,0);
ofColor white(255,255,255);

ofVec2f fire;

// level distribution
const int level1 = 5;
const int level2 = 10;
const int level3 = 15;

people myPeople[level2];

character myCharacter;

class floor myFloor[4];

window myWindows[4];
window myWindows2[4];

// x position of the door placement
int doorX[4] = {300, 700, 400, 600};
int doorY[4] = {215, 350, 485, 620}; // each door y values
int floorY[4] = {285, 420, 555, 690}; // used for door/floor placement
int buildingY[4] = {150, 307, 464, 621};



// place people at random floor
int peopleY[4] = {265, 400, 535, 670};

void floor::setup() {
//    pos = ofPoint(200, buildingY[(int)ofRandom[4]);
}

void floor::update() {
}

void floor::draw() {
    ofSetColor(skyBlue);
    ofDrawRectangle(pos, width, height);
}

//--------------------------------------------------------------
void window::setup() {

}
void window::update()  {
    
}
void window::draw() {
    ofSetColor(blue);
    ofDrawRectangle(pos, width, height);
}

int window::getX() {
    return pos.x;
}
int window:: getY() {
    return pos.y;
}
//--------------------------------------------------------------
float people::getX() {
    return pos.x;
}

float people::getY() {
    return pos.y;
}

void people::setup(int idx) {
    pos = ofPoint(ofRandom(200,824), peopleY[(int)ofRandom(0,3)]);
}
void people::update() {
    mountedNow();
//    droppedNow();
}

void people::draw() {
    if (alive == false && mounted == false) {
    ofSetColor(blue);
    ofDrawCircle(pos,size);
    } else if(alive == false && mounted == true) {
        ofSetColor(blue);
        ofDrawCircle(myCharacter.pos.x, myCharacter.pos.y-30, size);
    }
}

void people::mountedNow() {
    for(int i=0; i<level2; i++) {
        if (myPeople[i].mounted == true) {
            mounted = true;
            
        } else if(myPeople[i].mounted == false){
            mounted = false;
        }
    }
}


//void people::savedNow() {
//
//}

//--------------------------------------------------------------
void character::setup() {
    
}

void character::update() {
    if(fire.y <= myCharacter.pos.y) {
        myCharacter.dead = true;
    }
}

void character::draw() {
    if (!dead) {
        ofSetColor(red);
        ofDrawCircle(pos,20);
    } else if (dead) {
        ofSetColor(black);
        ofDrawBitmapString("YOU'RE DEAD!", ofGetWidth()/2-15, 200);
    }
}

int character::getX() {
    return pos.x;
}

int character::getY() {
    return pos.y;
}
//--------------------------------------------------------------
void ofApp::setup(){
    // building size width- 624, height -150
    ofSetBackgroundColor(pink);
    title.load("Symtext.ttf", 35);
    subtitle.load("Symtext.ttf", 20);
    description.load("Symtext.ttf", 15);
    instruction1.load("instruction1.png");
    
    // setting up postition for building floors
    for(int i = 0; i< 4; i++) {
        myFloor[i].pos = ofPoint(200, buildingY[i]);
    }
    
    //setting up window postitions
    for(int i = 0; i< 4; i++) {
        myWindows[i].pos = ofPoint(180, buildingY[i]);
        myWindows2[i].pos = ofPoint(824, buildingY[i]);
    }
    
    // position for fire
    fire.set(140, 768);
    
    // setting up postition for character
    myCharacter.pos = ofPoint(ofGetWidth()/2, 670);
    
    for(int i=0; i<level2; i++){
        myPeople[i].pos = ofPoint(ofRandom(200,824), peopleY[(int)ofRandom(3)]);
    }
}

void ofApp::update(){
    if(stage == 1) {
        fire.y -= 0.003; // increase the fire through the building
        
        // if character meets the floor = character dead.
        if ( myCharacter.pos.y >= fire.y ) {
            myCharacter.dead = true;
        }
    }
}

void ofApp::draw(){
    // 1024
    // 768
//    cout << (int)ofRandom(4) << endl;
    
    if(stage == 0) {
        ofBackground(pink);
        ofSetColor(255,0,0);
        //instruction
        title.drawString("THE FLOOR IS LAVA", ofGetWidth()/2-270, 200);
        description.drawString("GOTTA SAVE'EM ALL!", ofGetWidth()/2-270, 300);
        description.drawString("This game is designed to depict the ", ofGetWidth()/2-270, 320);
         description.drawString("terrifying moment of natural disaster", ofGetWidth()/2-270, 340);
        description.drawString("and to urge and bring on everyone's", ofGetWidth()/2-270, 360);
        description.drawString("intuitive sense of bravery and heroism.", ofGetWidth()/2-270, 380);
         description.drawString("SAVE THEM NOW!", ofGetWidth()/2-95, 630);
        
        ofSetColor(red);
        instruction1.draw(0,0);
        
        ofNoFill();
        ofSetLineWidth(3);
        ofDrawRectangle(ofGetWidth()/2-120, 600, 240, 60);
        
    } else if(stage == 1 && !myCharacter.dead) {
        // whole building
        
        ofSetColor(skyBlue);
        ofFill();
        ofSetLineWidth(1);
//        ofDrawRectangle(200, 150, 624, ofGetHeight()-150);
        
        for(int i=0; i < 4; i++) {
            myFloor[i].draw();
            myWindows[i].draw();
            myWindows2[i].draw();
        }
        
        // door/floor placement
        for(int i=0; i<4; i++) {
            ofSetColor(darkBlue);
            ofDrawRectangle(doorX[i],doorY[i],40,70);
            ofDrawRectangle(177, floorY[i],670, 10);
        };
        
        // draw people in the building
        for(int i=0; i<level2; i++){
            myPeople[i].draw();
        }
        
        // draw a character
        myCharacter.draw();
        
        // draw fire moving up
        ofSetColor(red);
        ofDrawRectangle(140, fire.y, 740, ofGetHeight() - fire.y);
        
    } else if (myCharacter.dead) {
        ofBackground(red);
//        myCharacter.draw();
        ofSetColor(white);
        subtitle.drawString("YOU SAVED: " + ofToString(peopleSaved) + "PEOPLE", ofGetWidth()/2-150, ofGetHeight()/2);
        
    }
    

}

void ofApp::keyPressed(int key){
    
    // When game is playing.
    if(stage == 0) {
        
    }else if (stage == 1) {
        if(myCharacter.pos.x <= 200 ) {
            myCharacter.pos.x = 202;
        }
        if(myCharacter.pos.x >= 824) {
            myCharacter.pos.x = 822;
        }
        
        if(key == OF_KEY_RIGHT && myCharacter.pos.x <= 824 && myCharacter.pos.x >= 200) {
            myCharacter.pos.x += 5;
        }
        
        if (key == OF_KEY_LEFT && myCharacter.pos.x >= 200 && myCharacter.pos.x <= 824) {
            myCharacter.pos.x -= 5;
        }
        
        // from 4th UP to top floor.
        if (key == OF_KEY_UP && myCharacter.pos.x >= 300 && myCharacter.pos.x <= 340 && myCharacter.pos.y > 150 && myCharacter.pos.y < 285) {
            myCharacter.pos.x = 700;
            myCharacter.pos.y = 400;
        }
        
        // from 3rd UP to 4th
        if (key == OF_KEY_UP && myCharacter.pos.x >= 700 && myCharacter.pos.x <= 740 && myCharacter.pos.y > 286 && myCharacter.pos.y < 420) {
            myCharacter.pos.x = 320;
            myCharacter.pos.y = 265;
        }
        // from 2nd UP to 3rd.
        if (key == OF_KEY_UP && myCharacter.pos.x >= 400 && myCharacter.pos.x <= 440 && myCharacter.pos.y > 421 && myCharacter.pos.y < 555) {
            myCharacter.pos.x = 720;
            myCharacter.pos.y = 400;
        }
        
        // from 1st UP to 2nd.
        if (myCharacter.pos.x >= 600 && myCharacter.pos.x <= 640 && myCharacter.pos.y > 556 && myCharacter.pos.y < 691 && key == OF_KEY_UP) {
            myCharacter.pos.x = 420;
            myCharacter.pos.y = 535;
        }
        
        // from 2nd DOWN to 1st.
        if (key == OF_KEY_DOWN && myCharacter.pos.x >= 400 && myCharacter.pos.x <= 440 && myCharacter.pos.y > 421 && myCharacter.pos.y < 555) {
            myCharacter.pos.x = 620;
            myCharacter.pos.y = 670;
        }
        
        // from 3rd DOWN to 2nd
        if (key == OF_KEY_DOWN && myCharacter.pos.x >= 700 && myCharacter.pos.x <= 740 && myCharacter.pos.y > 286 && myCharacter.pos.y < 420) {
            myCharacter.pos.x = 420;
            myCharacter.pos.y = 535;
        }

        // from 4th DOWN to 3rd.
        if (key == OF_KEY_DOWN && myCharacter.pos.x >= 300 && myCharacter.pos.x <= 340 && myCharacter.pos.y > 150 && myCharacter.pos.y < 285) {
            myCharacter.pos.x = 700;
            myCharacter.pos.y = 400;
        }
    }


}

void ofApp::keyReleased(int key){
    for(int i=0; i<level2; i++){
        if(key == OF_KEY_SPACE && myPeople[i].mounted == true) {
            std::cout << "released";
            myPeople[i].mounted = false;
//            myPeople[i].dropped = true;
        } else if (key == OF_KEY_SPACE && myCharacter.pos.x > myPeople[i].getX() - 10 &&
            myCharacter.pos.x < myPeople[i].getX() + 10 && myCharacter.pos.y == myPeople[i].getY() && myPeople[i].mounted == false) {
            std::cout << "picked up";
            myPeople[i].mounted = true;
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    if (stage == 0) {
        if(x >= ofGetWidth()/2-120 && x <= ofGetWidth()/2+120 && y >= 600 && y <= 660) {
            stage = 1;
        }
    }
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
