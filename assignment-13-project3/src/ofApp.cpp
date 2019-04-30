#include "ofApp.h"

ofColor pink(255,234,231);
ofColor skyBlue(166,206,206);
ofColor darkBlue(128,181, 175);
ofColor red(255,0, 0);

ofVec2f fire;


// x position of the door placement
int doorX[4] = {300, 700, 400, 600};
int doorY[4] = {215, 350, 485, 620}; // each floor
int floorY[4] = {285, 420, 555, 690};

//--------------------------------------------------------------
void ofApp::setup(){
    // building size width- 624, height -150
    ofSetBackgroundColor(pink);
    
    fire.set(140, 768);
}

//--------------------------------------------------------------
void ofApp::update(){
    fire.y -= 0.003; // increase the fire through the building
}

//--------------------------------------------------------------
void ofApp::draw(){
    // 1024
    // 768
    
    // whole building
    ofSetColor(skyBlue);
    ofDrawRectangle(200, 150, 624, ofGetHeight()-150);

    // door placement
    for(int i=0; i<4; i++) {
        ofSetColor(darkBlue);
        ofDrawRectangle(doorX[i],doorY[i],40,70);
        ofDrawRectangle(177, floorY[i],670, 10);
    }
    
    ofSetColor(red);
    ofDrawRectangle(140, fire.y, 740, ofGetHeight() - fire.y);
    
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
