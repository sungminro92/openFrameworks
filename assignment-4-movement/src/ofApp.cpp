#include "ofApp.h"

//ofVec2f move1; // move to right
float skirtX1 = 40; // X value that will move of the skirt
float skirtX2 = 280;
float skirtD1 = -1; // decreasing X value; increasing X value;
float skirtD2 = 1; // increasing X value;

//float shadowX1, shadowX2, shadowX3, shadowX4;
float shadowX1 = 55; // X values of moving point of shadows
float shadowX2 = 125;
float shadowX3 = 160;
float shadowX4 = 230;

//float shadowBase1, shadowBase2, shadowBase3, shadowBase4; // baseline distance of triangle shadows
float shadowBase1 = 14; //total movement: 55 - 28;
float shadowBase2 = 30; //total movement: 125 - 60;
float shadowBase3 = 20; //total movement: 160 - 40;
float shadowBase4 = 50; //total movement: 230 - 100;
//specifying the baseline distance of the shadows

float shadowMove1, shadowMove2, shadowMove3, shadowMove4; // mapped movement amount in certain seconds to shadows
//float shadow1, shadow2, shadow3, shadow4; // measurement of movement to shadow.
float newShadowMove1, newShadowMove2, newShadowMove3, newShadowMove4;
ofVec2f one, two, three, four, five, six, seven, eight, nine, ten, eleven; // mountai

//int ofTrueTypeFontSettings::fontSize;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(255);

    one.set(0,200);
    two.set(40,160);
    three.set(60,170);
    four.set(95,120);
    five.set(120,160);
    six.set(140,120);
    seven.set(160,160);
    eight.set(180,140);
    nine.set(240,200);
    ten.set(240,240);
    eleven.set(0,240);

}

bool drawFirst = true;
bool drawSecond = false;
bool drawThird = true;
bool drawForth = true;

//--------------------------------------------------------------
void ofApp::update(){
    int sec = (ofGetFrameNum() / 60) % 60; // time update
//---------
    drawFirst = sec < 2;
    drawSecond = sec < 4;
    drawThird = sec < 6;
    drawForth = sec < 8;

    skirtX1 += 1 * skirtD1;
    skirtX2 += 1 * skirtD2;
    
    cout << skirtX2 << endl;
    
    if( skirtX1 <= 0 || skirtX1 >= 40 ) {
        skirtD1 *= -1; }
    if (skirtX2 >= 320 || skirtX2 <= 280) {
        skirtD2 *= -1; }
//---------
    shadowMove1 = 1;
    newShadowMove1 = ofMap(shadowMove1, 0, 60, 0, shadowBase1); // total movement divided by 60.
    shadowMove2 = 1;
    newShadowMove2 = ofMap(shadowMove2, 0, 60, 0, shadowBase2);
    shadowMove3 = 1;
    newShadowMove3 = ofMap(shadowMove3, 0, 60, 0, shadowBase3);
    shadowMove4 = 1;
    newShadowMove4 = ofMap(shadowMove4, 0, 60, 0, shadowBase4);
    
    if(sec >= 2) {
        if(shadowX1 > 27) {
            shadowX1 = shadowX1 - newShadowMove1;}
        if(shadowX2 > 65 ) {
            shadowX2 = shadowX2 - newShadowMove2;}
        if(shadowX3 > 120) {
            shadowX3 = shadowX3 - newShadowMove3;}
        if(shadowX4 > 130) {
            shadowX4 = shadowX4 - newShadowMove4;}
    }

    
//    one = one + move1;
//    two = two + move1;
    
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
    //--------- figure 1
    ofSetColor(skin);
    ofDrawCircle(160, 80, 40); // face
    
    ofSetColor(red);
    ofDrawRectRounded(120, 30, 0, 80, 10, 20, 20, 20, 20); // accessory
    
    ofSetColor(black);
    ofDrawCircle(160, 30, 20); // hair

    ofSetColor(black);
//    ofRectangle myRect;
//    myRect.x = 40;
//    myRect.y = 40;
//    myRect.width = 80;
//    myRect.height = 40;
////    ofDrawRectRounded( 40, 40,  40, 40, 0, 0 ); // hair
    ofDrawRectRounded(120, 40, 0, 80, 40, 40, 40, 0, 0);
    
    ofSetColor(red);
    ofDrawRectRounded(80, 120, 0, 160, 80, 40, 40, 0, 0); // shoulder
    
    ofSetColor(blue);
    ofDrawRectRounded(80, 160, 0, 160, 80, 0, 0, 40, 40); // arm bottom
    
    ofSetColor(yellow);
    ofDrawRectangle(80, 160, 160, 40); // middle arm
    
    ofSetColor(white);
    ofDrawRectangle(120, 160, 80, 200); // white middle dress

    ofSetColor(red);                    // details
    ofDrawRectangle(120, 260, 80, 20);
    ofSetColor(yellow);
    ofDrawRectangle(120, 300, 80, 20);
    ofSetColor(blue);
    ofDrawRectangle(120, 340, 80, 20);
    
    ofSetColor(red);
    ofDrawTriangle( skirtX1, 360, 120, 240, 120, 360); // skirt1
    ofDrawTriangle( 200, 360, 200, 240, skirtX2, 360); // skirt2
        
    } else if( drawSecond ) {
//---------- figure 2
//    cout << newShadowMove1 << endl;
//    cout << newShadowMove2 << endl;
//    cout << newShadowMove3 << endl;
//    cout << newShadowMove4 << endl;
        
    ofSetColor(blueBlack);

    ofBeginShape(); // mountain shape
    ofVertex(one);
    ofVertex(two);
    ofVertex(three);
    ofVertex(four);
    ofVertex(five);
    ofVertex(six);
    ofVertex(seven);
    ofVertex(eight);
    ofVertex(nine);
    ofVertex(ten);
    ofVertex(eleven);
    ofEndShape();
    
    ofSetColor(skyBlue);
    ofDrawTriangle(40, 165, shadowX1, 180, 40, 200); //shadow 1 55 - 40 = 15
    ofDrawTriangle(95, 130, shadowX2, 180, 95, 205); //shadow 2 125 - 95 = 30
    ofDrawTriangle(140, 130, shadowX3, 170, 140, 160); //shadow 3  160 - 140 = 20
    ofDrawTriangle(180, 150, shadowX4, 200, 180, 180); //shadow 4  230 - 180 = 50

    }
        else if ( drawThird ) {
//--------- figure 3

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
