#include "ofApp.h"

int sec;

ofSoundPlayer arirang;
ofSoundPlayer bird;
ofSoundPlayer twinkle;
ofSoundPlayer yay;

float width, height;
float midX, midY;

ofVec2f figure1; ofVec2f figure2; ofVec2f figure3; ofVec2f figure4;

float skirtX1, skirtX2;
float f1x, f1y, f2x, f2y, f3x, f3y, f4x, f4y;
float shadowX1, shadowX2, shadowX3, shadowX4; //X value of moving point
float shadowMove;// mapped movement amount in certain seconds to shadows

float f3ColorMove;
float f3Color;
float f3Color2;
//int ofTrueTypeFontSettings::fontSize;

ofVec2f f4One, f4Two, f4Three, f4Four, f4Five, f4Six, f4Seven;
ofVec2f f4Move1, f4Move2;

bool start;
bool drawFirst = true;
bool drawSecond = false;
bool drawThird = true;
bool drawForth = true;

//--------------------------------------------------------------
void ofApp::setup(){
    arirang.load("arirang-sound-effect.mp3");
    bird.load("bird-sound-effect.mp3");
    twinkle.load("twinkle-sound-effect.mp3");
    yay.load("yay-sound-effect.mp3");
    
    width = ofGetWidth(); //1024
    height = ofGetHeight(); //768
    midX = width/2; //512
    midY = height/2; // 384

    ofSetFrameRate(60);
    ofBackground(255);

    figure1.set(500,600); // midpoint of Figure1
    figure2.set(512,600); // midpoint of Figure2
    figure3.set(505,650); // midpoint of Figure3
    figure4.set(500,600); // midpoint of Figure3
    f1x = figure1.x; f1y = figure1.y;
    f2x = figure2.x; f2y = figure2.y;
    f3x = figure3.x; f3y = figure3.y;
    f4x = figure4.x; f4y = figure4.y;
    
    skirtX1 = f1x-100; // X value that will move of the skirt
    skirtX2 = f1x+150;
    
    shadowX1 = f2x-212; // X values of moving point of shadows
    shadowX2 = f2x-12;
    shadowX3 = f2x+138;
    shadowX4 = f2x+318;

// color change
    f3Color = 0;
    f3Color2 = 255;
    
// vertex for movement
    f4One.set(f4x-110, f4y-260);
    f4Two.set(f4x-10, f4y-360);
    f4Three.set(f4x+90, f4y-260);
    f4Four.set(f4x+40, f4y-260);
    f4Five.set(f4x+40, f4y-160);
    f4Six.set(f4x-60, f4y-160);
    f4Seven.set(f4x-60, f4y-260);
    
    if(sec >= 0 && sec <2){
        arirang.play();
    }

}


float skirtD1 = 1; // decreasing X value; increasing X value;
float skirtD2 = 1; // increasing X value;

float f3D = 1;

//--------------------------------------------------------------
void ofApp::update() {
    
    sec = (ofGetFrameNum() / 60) % 60; // time update
    
    drawFirst = sec < 2;
    drawSecond = sec < 4;
    drawThird = sec < 6;
    drawForth = sec < 8;
    
    if(drawFirst) {
        bird.play();
    } else if (drawSecond) {
        twinkle.play();
    } else if (drawThird) {
        yay.play();
    }
    
    skirtX1 -= 2 * skirtD2;
    skirtX2 -= 2 * skirtD2;
    
    if( skirtX1 <= f1x-150 || skirtX2 > f1x-100 ) {
        skirtD1 *= -1; }
    if (skirtX2 >= f1x+150 || skirtX2 <= f1x+100) {
        skirtD2 *= -1; }
    
//--------- SHADOW MOVEMENT
    
    shadowMove = 1;//mapping movement
    if(sec >= 2) {
        if(shadowX1 > f2x-312) {
            shadowX1 = shadowX1 - ofMap(shadowMove, 0, 59, 0, 50);}
        if(shadowX2 > f2x-212 ) {
            shadowX2 = shadowX2 - ofMap(shadowMove, 0, 59, 0, 100);}
        if(shadowX3 > f2x-12) {
            shadowX3 = shadowX3 - ofMap(shadowMove, 0, 59, 0, 75);}
        if(shadowX4 > f2x+70) {
            shadowX4 = shadowX4 - ofMap(shadowMove, 0, 59, 0, 130);}
    }
//--------- FIGURE 3 movement
//
//    if(sec >= 5) {
//        f3Color2 += ofMap(f3Color1, 0, 59, 0, 255);
//        f3Color3 += ofMap(f3Color1, 0, 59, 0, 255);
//    }
    f3ColorMove = 1;
    if (sec >= 4) {
        f3Color += ofMap(f3ColorMove, 0, 30, 0, 255) * f3D;
        if (f3Color >= 255) {
            f3D *= -1;
        } else if (f3Color <= 0) {
            f3D *= -1;
        }
        
        f3Color2 -= ofMap(f3ColorMove, 0, 30, 0, 255) * f3D;
        if (f3Color2 <= 0) {
            f3D *= -1;
        } else if (f3Color2 >= 255) {
            f3D *= -1;
        }
    }
    
//--------- FIGURE 3 movement
    f4Move1.set(0.5,0.5);
    f4Move2.set(-0.7,-0.7);
    if(sec>= 6 && sec < 7) {
        f4One += f4Move1;
        f4Two += f4Move1;
        f4Three += f4Move1;
        f4Four += f4Move1;
        f4Five += f4Move1;
        f4Six += f4Move1;
        f4Seven += f4Move1;
    } else if (sec>= 7 && sec <8) {
        f4One += f4Move2;
        f4Two += f4Move2;
        f4Three += f4Move2;
        f4Four += f4Move2;
        f4Five += f4Move2;
        f4Six += f4Move2;
        f4Seven += f4Move2;
    }
    
}

ofColor skin(251, 206, 181);
ofColor red(255,0,0);
ofColor yellow(255, 204, 0);
ofColor blue(6, 6, 255);
ofColor black(0);
ofColor white(255);
ofColor blueBlack(18, 41, 57);
ofColor skyBlue(113, 175, 186);
ofColor green(0, 255, 0);

//--------------------------------------------------------------
void ofApp::draw(){
    ofPolyline line;
    // one big grid is = 40;
    // facial radius = 40; circle begins in the middle
    

    if ( drawFirst ) {
    
    //--------- figure 1
    ofSetColor(skin);
    ofDrawCircle(f1x, f1y-300, 50); // face

    ofSetColor(red);
    ofDrawRectRounded(f1x-40, f1y-365, 0, 80, 10, 10, 10, 10, 10); // accessory
    ofSetColor(black);
    ofDrawCircle(f1x, f1y-365, 20); // hair
    ofSetColor(black);
    ofDrawRectRounded(f1x-50, f1y-350, 0, 100, 50, 200, 200, 0, 0); // head

    ofSetColor(red);
    ofDrawRectRounded(f1x-80, f1y-250, 0, 160, 30, 30, 30, 0, 0); // shoulder
    ofSetColor(yellow);
    ofDrawRectangle(f1x-80, f1y-220, 160, 30); // middle arm
    ofSetColor(blue);
    ofDrawRectRounded(f1x-80, f1y-190, 0, 160, 30, 0, 0, 30, 30); // arm bottom

    ofSetColor(red);
    ofDrawTriangle( skirtX1, f1y, f1x-50, f1y-160, f1x-50, f1y); // skirt1
    ofDrawTriangle( f1x+50, f1y, f1x+50, f1y-160, skirtX2, f1y); // skirt2

    ofSetColor(white);
    ofDrawRectangle(f1x-50, f1y-220, 100, 220); // white middle dress
    ofSetColor(red);
    ofDrawRectangle(f1x-50, f1y-100, 100, 20);
    ofSetColor(yellow);
    ofDrawRectangle(f1x-50, f1y-60, 100, 20);
    ofSetColor(blue);
    ofDrawRectangle(f1x-50, f1y-20, 100, 20);  // details
        
    } else if( drawSecond ) {
    
    ofSetColor(blueBlack); // color
    ofBeginShape(); // mountain shape
    ofVertex(figure2-ofVec2f(362,150));
    ofVertex(figure2-ofVec2f(262,250));
    ofVertex(figure2-ofVec2f(212,200));
    ofVertex(figure2-ofVec2f(112,350));
    ofVertex(figure2-ofVec2f(12,200));
    ofVertex(figure2-ofVec2f(-63,300));
    ofVertex(figure2-ofVec2f(-138,200));
    ofVertex(figure2-ofVec2f(-188,250));
    ofVertex(figure2-ofVec2f(-338,120));
    ofVertex(figure2-ofVec2f(-338,0));
    ofVertex(figure2-ofVec2f(362,0));
    ofEndShape();

    ofSetColor(skyBlue);
    ofDrawTriangle(f2x-262, f2y-230, shadowX1, f2y-180, f2x-262, f2y-140); //shadow1 300-250=50
    ofDrawTriangle(f2x-112, f2y-330, shadowX2, f2y-180, f2x-112, f2y-120); //shadow2 500-400=100
    ofDrawTriangle(f2x+63, f2y-280, shadowX3, f2y-180, f2x+63, f2y-200); //shadow3 650-575=75
    ofDrawTriangle(f2x+188, f2y-230, shadowX4, f2y-120, f2x+188, f2y-150); //shadow 4  830-700=130

    }
        else if ( drawThird ) {
//--------- figure 3
    
    ofSetColor(f3Color2);
    ofDrawRectangle(f3x-105, f3y-50, 210, 50);
    ofDrawRectangle(f3x-85, f3y-150, 170, 100);
    ofDrawRectangle(f3x-65, f3y-370, 130, 220);
    ofDrawRectangle(f3x-45, f3y-420, 90, 50);
    ofDrawRectangle(f3x-35, f3y-450, 70, 30);
    ofDrawRectangle(f3x-25, f3y-470, 50, 20);
        ofBeginShape();
        ofVertex(f3x-5,f3y-470);//500 130
        ofVertex(f3x-5,f3y-530);//500 70
        ofVertex(f3x,f3y-540);//505 60
        ofVertex(f3x+5,f3y-530);//510 70
        ofVertex(f3x+5,f3y-470);//510 130
        ofEndShape();
        
    for(int i=0; i < 8; i++ ) {
        ofSetColor(f3Color);
        ofDrawRectangle(f3x-75 + (20*i), f3y-130, 10, 80);}
    for(int i=0; i < 2; i++ ) {
        ofSetColor(f3Color);
        ofDrawRectangle(f3x-35 + (50*i), f3y-360, 10, 220);}
    for(int i=0; i < 3; i++ ) {
        ofSetColor(f3Color);
        ofDrawRectangle(f3x-25 + (20*i), f3y-420, 10, 50);}
    for(int i=0; i < 2; i++ ) {
        ofSetColor(f3Color);
        ofDrawRectangle(f3x-15 + (20*i), f3y-450, 10, 30);}

    ofDrawRectangle(f3x-5, f3y-470, 10, 20);

    ofSetColor(black);
    ofSetLineWidth(5);
    line.begin();
    line.addVertex(f3x-105,f3y);
    line.addVertex(f3x-105,f3y-50);
    line.addVertex(f3x-85,f3y-50);
    line.addVertex(f3x-85,f3y-150);
    line.addVertex(f3x-65,f3y-150);
    line.addVertex(f3x-65,f3y-370);
    line.addVertex(f3x-45,f3y-370);
    line.addVertex(f3x-45,f3y-420);
    line.addVertex(f3x-35,f3y-420);
    line.addVertex(f3x-35,f3y-450);//470 150
    line.addVertex(f3x-25,f3y-450);//480 150
    line.addVertex(f3x-25,f3y-470);//480 130
    line.addVertex(f3x-5,f3y-470);//500 130
    line.addVertex(f3x-5,f3y-530);//500 70
    line.addVertex(f3x,f3y-540);//505 60
    line.addVertex(f3x+5,f3y-530);//510 70
//        line.addVertex(f3x+5,f3y-530);//510 70
    line.addVertex(f3x+5,f3y-470);//510 130
    line.addVertex(f3x+25,f3y-470);//530 130
    line.addVertex(f3x+25,f3y-450);//530 150
    line.addVertex(f3x+35,f3y-450);//540 150
    line.addVertex(f3x+35,f3y-420);//540 180
    line.addVertex(f3x+45,f3y-420);//550 180
    line.addVertex(f3x+45,f3y-370);//550 230
    line.addVertex(f3x+65,f3y-370);//570 230
    line.addVertex(f3x+65,f3y-150);//570 450
    line.addVertex(f3x+85,f3y-150);//590 450
    line.addVertex(f3x+85,f3y-50);//590 550
    line.addVertex(f3x+105,f3y-50);//610 550
    line.addVertex(f3x+105,f3y);//610 600
    line.addVertex(f3x-105,f3y);
    line.close();
    line.draw();
    
    ofBeginShape();
    ofVertex(f3x-15, f3y-565); // 490 35
    ofVertex(f3x-5, f3y-570); // 500 30
    ofVertex(f3x, f3y-580); //505 20
    ofVertex(f3x+5, f3y-570); // 510 30
    ofVertex(f3x+15, f3y-565); // 520 35
    ofVertex(f3x+5, f3y-560); // 510 40
    ofVertex(f3x, f3y-550); // 505 50
    ofVertex(f3x-5, f3y-560); // 500 40
    ofEndShape();

    } else if ( drawForth) {
        
        ofSetColor(skyBlue);
        ofDrawCircle(f4x,f4y-250, 250);
        
        ofSetColor(yellow);
        ofBeginShape();
        ofVertex(f4One);
        ofVertex(f4Two);
        ofVertex(f4Three);
        ofVertex(f4Four);
        ofVertex(f4Five);
        ofVertex(f4Six);
        ofVertex(f4Seven);
        ofEndShape();
        
        ofSetColor(black);
        ofSetLineWidth(5);
        line.addVertex(f4x-100, f4y-250);
        line.addVertex(f4x, f4y-350);
        line.addVertex(f4x+100, f4y-250);
        line.addVertex(f4x+50, f4y-250);
        line.addVertex(f4x+50, f4y-150);
        line.addVertex(f4x-50, f4y-150);
        line.addVertex(f4x-50, f4y-250);
        line.close();
        line.draw();
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
