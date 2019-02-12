#include "ofApp.h"


//int ofTrueTypeFontSettings::fontSize;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(255);
    
}

bool drawFirst = true;
bool drawSecond = true;
bool drawThird = true;
bool drawForth = true;

//--------------------------------------------------------------
void ofApp::update(){
     int sec = (ofGetFrameNum() / 60) % 60;

    drawFirst = sec < 2;
    drawSecond = sec < 4;
    drawThird = sec < 6;
    drawForth = sec < 8;
}

//--------------------------------------------------------------
void ofApp::draw(){
    // one big grid is = 40;
    // facial radius = 40; circle begins in the middle
    
    ofColor skin(251, 206, 181);
    ofColor red(255,0,0);
    ofColor yellow(255, 204, 0);
    ofColor blue(6, 6, 255);
    ofColor black(0);
    ofColor white(255);
    ofColor blueBlack(18, 41, 57);
    ofColor skyBlue(113, 175, 186);
    ofColor green(0, 255, 0);
    
    if ( drawFirst ) {
    //-------------------------------------------------------------- figure 1
    ofSetColor(skin);
    ofDrawCircle(120, 80, 40); // face
    
    ofSetColor(red);
    ofDrawRectRounded(80, 30, 0, 80, 10, 20, 20, 20, 20); // accessory
    
    ofSetColor(black);
    ofDrawCircle(120, 30, 20); // hair

    ofSetColor(black);
//    ofRectangle myRect;
//    myRect.x = 40;
//    myRect.y = 40;
//    myRect.width = 80;
//    myRect.height = 40;
////    ofDrawRectRounded( 40, 40,  40, 40, 0, 0 ); // hair
    ofDrawRectRounded(80, 40, 0, 80, 40, 40, 40, 0, 0);
    
    ofSetColor(red);
    ofDrawRectRounded(40, 120, 0, 160, 80, 40, 40, 0, 0); // shoulder
    
    ofSetColor(blue);
    ofDrawRectRounded(40, 160, 0, 160, 80, 0, 0, 40, 40); // arm bottom
    
    ofSetColor(yellow);
    ofDrawRectangle(40, 160, 160, 40); // middle arm
    
    ofSetColor(white);
    ofDrawRectangle(80, 160, 80, 200); // white middle dress

    ofSetColor(red);                    // details
    ofDrawRectangle(80, 260, 80, 20);
    ofSetColor(yellow);
    ofDrawRectangle(80, 300, 80, 20);
    ofSetColor(blue);
    ofDrawRectangle(80, 340, 80, 20);
    
    ofSetColor(red);
    ofDrawTriangle( 0, 360, 80, 240, 80, 360);
    ofDrawTriangle( 160, 360, 160, 240, 240, 360);
        
    } else if( drawSecond ) {
//-------------------------------------------------------------- figure 2
    ofSetColor(blueBlack);
    ofBeginShape();
    ofVertex(0,200);
    ofVertex(40,160);
    ofVertex(60,165);
    ofVertex(80,120);
    ofVertex(120,160);
    ofVertex(140,120);
    ofVertex(160,160);
    ofVertex(180,140);
    ofVertex(240,200);
    ofVertex(240,240);
    ofVertex(0,240);
    ofEndShape();
    
    ofSetColor(skyBlue);
    ofDrawTriangle(40, 165, 60, 180, 40, 200);
    
    ofBeginShape();
    ofVertex(80,125);
    ofVertex(120,165);
    ofVertex(110,180);
    ofVertex(100,180);
    ofEndShape();
    
    ofDrawTriangle(140, 125, 160, 165, 140, 160);
    
    ofBeginShape();
    ofVertex(180,145);
    ofVertex(235,200);
    ofVertex(200,190);
    ofVertex(180,160);
    ofEndShape();
    } else if ( drawThird ) {
//-------------------------------------------------------------- figure 3
    
    ofSetColor(red);
    ofDrawLine(80, 25, 80, 60);
    ofDrawLine(40, 30, 50, 60);
    ofDrawLine(120, 30, 100, 60);
    ofDrawCircle(80, 120, 40);
    
    ofSetColor(green);
    ofBeginShape();
//    ofDrawCurve(0, 200, 40, 190, 40, 190, 80, 200);
//    ofDrawCurve(80, 200, 120, 210, 120, 210, 160, 200);
//    ofDrawCurve(160, 200, 200, 190, 200, 190, 240, 200);
        ofCurveVertex(0, 200);
        ofCurveVertex(40, 190);
        ofCurveVertex(80, 200);
        ofCurveVertex(120, 210);
        ofCurveVertex(160, 200);
        ofCurveVertex(200, 190);
        ofCurveVertex(240, 200);
    ofVertex(240,240);
    ofVertex(0, 240);
    ofEndShape();
    } else if ( drawForth) {
        ofSetColor(yellow);
        ofDrawRectRounded(20, 120, 180, 120, 5);
        ofSetColor(white);
        ofDrawTriangle(180, 120, 200, 120, 200, 135);
        ofSetColor(black);
        ofDrawRectangle(20, 200, 180, 30);
        ofSetColor(red);
        ofDrawCircle(50, 145, 25);
        
        ofSetColor(blue);
//        ofRotateDeg(30);
        ofDrawBitmapString("MetroCard", 40, 190);
        
    }
}

void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
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
