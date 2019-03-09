#include "ofApp.h"

// figure midpoints
ofVec2f figure1;
ofVec2f figure2;
ofVec2f figure3;
ofVec2f figure4;

// Figure1 moving skirt point values
int skirtX1, skirtX2;

// X value of moving shadows point
float shadowX1,shadowX2,shadowX3,shadowX4;
// COLORS DEFINED
float f2Color; // shadow color code

// figure 3 color 0 - 255
float f3ColorMove;
float f3BuildingColor; // figure 3 building color (white - black)
float f3WindowColor; // figure 3 window color (white - black)

// figure4 shape && moves
ofVec2f f4One, f4Two, f4Three, f4Four, f4Five, f4Six, f4Seven;
ofVec2f f4Move1, f4Move2;

// four scenes defined
bool drawFirst = true;
bool drawSecond = false;
bool drawThird = true;
bool drawForth = true;

// used in korean character scene.
bool up = true;
// used in new york empire state building scene
bool clicked = true;

//--------------------------------------------------------------
void ofApp::setup(){
    


    //gui setup for figure1
    gui.setup();
gui.add(position.setup("position",ofVec2f(ofGetWidth()*.5, 600), ofVec2f(0,0), ofVec2f(ofGetWidth(), ofGetHeight())));
    gui.add(skirtMove.setup("Dance", 1, 0, 20));
    gui.add(smile.setup("smile?", false));
    gui.add(color.setup("Dress Color", ofColor(255,0,0), ofColor(0,0), ofColor(255,255)));
    gui.add(hairResolution.setup("hair shape", 5,3,90));
    
    
    
    // frame rate
    ofSetFrameRate(60);
    // background color
    ofBackground(255);
    //musics
    arirang.load("arirang-sound-effect.mp3");
    bird.load("bird-sound-effect.mp3");
    twinkle.load("twinkle-sound-effect.mp3");
    yay.load("yay-sound-effect.mp3");
    // fonts
    bebas.load("bebas.ttf", 24);
    decorative.load("KGDefyingGravity.ttf", 50);
    // width =1024 / height = 768
    width = ofGetWidth();
    height = ofGetHeight();
    midX = width/2;
    midY = height/2;

//    shadowX1 = figure2.x-212; // X values of moving shadow
//    shadowX2 = figure2.x-12;
//    shadowX3 = figure2.x+138;
//    shadowX4 = figure2.x+318; no need anymore
    
    // figure midpoints
    figure1.set(500,600);
    figure2.set(512,600);
    figure3.set(505,650);
    figure4.set(505,650);
    
    // Figure1 moving skirt point values
    skirtX1 =  figure1.x -150;
    skirtX2 =  figure1.x +150;
    
    // X value of moving shadows point
    shadowX1 = figure2.x-212;
    shadowX2 = figure2.x-12;
    shadowX3 = figure2.x+138;
    shadowX4 = figure2.x+318;


    f3BuildingColor = 0; // black
    f3WindowColor = 255; // white

//    arirang.play(); // initial music play
}

float figure1D = 1;
float skirtD1 = 1; // figure1 decreasing X value;
float skirtD2 = 1; // figure1 increasing X value;
float f3D = 1; // figure 3 moving direction

int sec;
 // shadowColor
float moveForMountain; // mouse move measurement for mountain movement + background color


//--------------------------------------------------------------
void ofApp::update() {
    // time update
    sec = (ofGetFrameNum() / 60) % 60;

    drawFirst = true;
//    drawSecond = sec < 10;
//    drawThird = sec < 15;
//    drawForth = sec < 20;
//
//    if(drawFirst) { // playing music each scene
//        bird.play();
//    } else if (drawSecond) {
//        twinkle.play();
//    } else if (drawThird) {
    //        yay.play();
    //    }
    //
//--------- Figure1 MOVEMENT
//    if(sec < 5) {               // skirt movement
//        skirtX1 -= skirtMove * skirtD1;
//        skirtX2 += skirtMove * skirtD2;
//
//        if( skirtX1 <= figure1.x-160 || skirtX1 >= figure1.x-100 ) {
//            skirtD1 *= -1;
//            skirtD2 *= -1;
//        }
//--------- Figure2 MOVEMENT
    
//    if(sec >= 10) {
        moveForMountain = ofGetMouseX();
        f2Color = ofMap(moveForMountain, 0, width, 0, 255);
    
    if (moveForMountain < 0) {
        moveForMountain = 0;
    } else if (moveForMountain > width) {
        moveForMountain = width;
    }

    if(sec > 5 && sec < 10) {
            shadowX1 = ofMap(moveForMountain, 0, width, figure2.x-212, figure2.x -212 -50 -50);
            shadowX2 = ofMap(moveForMountain, 0, width, figure2.x-12, figure2.x -12 -100 -100);
            shadowX3 = ofMap(moveForMountain, 0, width, figure2.x+138, figure2.x+138-75-75);
            shadowX4 = ofMap(moveForMountain, 0, width, figure2.x+318, figure2.x+318-130-130);
    }
//--------- Figure3 MOVEMENT
//    f3ColorMove = 1;
//
//    if (sec >= 1) {
//        f3Color += ofMap(f3ColorMove, 0, 30, 0, 255) * f3D;
//        if (f3Color >= 255) {
//            f3D *= -1;}
//        else if (f3Color <= 0) {
//            f3D *= -1;}
//
//        f3Color2 -= ofMap(f3ColorMove, 0, 30, 0, 255) * f3D;
//        if (f3Color2 <= 0) {
//            f3D *= -1;}
//        else if (f3Color2 >= 255) {
//            f3D *= -1;}
//    }
    
//--------- Figure4 Movement
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
ofColor background;
//--------------------------------------------------------------


void ofApp::draw(){
//    cout << figure1.x << endl;
    
    ofPolyline curvedSegmentPolyline;
    ofPolyline line;
    ofSetCircleResolution(100);
    ofSetCurveResolution(100);

//--------- figure 1
    if ( drawFirst ) {
    // gui positioning figure1
    figure1.set((ofVec2f)position); // midpoint
    skirtX1 = figure1.x-150-skirtMove;
        skirtX2 = figure1.x+150+skirtMove;
    
    // face
    ofSetColor(skin);
    ofDrawCircle(figure1.x, figure1.y-300, 50);
    // eyes
    ofSetColor(black);
    ofDrawCircle(figure1.x-20,figure1.y-290,5);
    ofDrawCircle(figure1.x+20,figure1.y-290,5);
    // lips
        ofSetColor(red);
        ofFill();
        if(smile) {
        ofDrawTriangle(figure1.x-25,figure1.y-280,figure1.x+25,figure1.y-280,figure1.x,figure1.y-250);
        } else {
//        ofFill();
        curvedSegmentPolyline.curveTo(figure1.x-20, figure1.y-270);
        curvedSegmentPolyline.curveTo(figure1.x-20, figure1.y-270);
        curvedSegmentPolyline.curveTo(figure1.x-10, figure1.y-275);
        curvedSegmentPolyline.curveTo(figure1.x, figure1.y-270);
        curvedSegmentPolyline.curveTo(figure1.x+10, figure1.y-275);
        curvedSegmentPolyline.curveTo(figure1.x+20, figure1.y-270);
        curvedSegmentPolyline.curveTo(figure1.x, figure1.y-260);
        curvedSegmentPolyline.curveTo(figure1.x-20, figure1.y-270);
        curvedSegmentPolyline.curveTo(figure1.x-20, figure1.y-270);
        curvedSegmentPolyline.draw();
    }
    // accessory
    ofSetColor(color);
    ofDrawRectRounded(figure1.x-40, figure1.y-365, 0, 80, 10, 10, 10, 10, 10);
    // hair
    ofSetColor(black);
        ofSetCircleResolution(hairResolution);
    ofDrawCircle(figure1.x, figure1.y-365, 20);
    // head
    ofSetCircleResolution(100);
    ofSetColor(black);
    ofDrawRectRounded(figure1.x-50, figure1.y-350, 0, 100, 50, 200, 200, 0, 0);
    
    ofSetCircleResolution(100); // back to 100
    ofSetColor(skin);
    ofDrawTriangle(figure1.x-50, figure1.y-300, figure1.x, figure1.y-320, figure1.x+50, figure1.y-300);
    // shoulder
    ofSetColor(color);
    ofDrawRectRounded(figure1.x-80, figure1.y-250, 0, 160, 30, 30, 30, 0, 0);
    // middle arm
    ofSetColor(yellow);
    ofDrawRectangle(figure1.x-80, figure1.y-220, 160, 30);
    // arm bottom
    ofSetColor(blue);
    ofDrawRectRounded(figure1.x-80, figure1.y-190, 0, 160, 30, 0, 0, 30, 30);

    // skirt1
    ofSetColor(color);
    ofDrawTriangle( skirtX1, figure1.y, figure1.x-50, figure1.y-160, figure1.x-50, figure1.y);
    // skirt2
    ofDrawTriangle( figure1.x+50, figure1.y, figure1.x+50, figure1.y-160, skirtX2, figure1.y);
    // white middle dress
    ofSetColor(white);
    ofDrawRectangle(figure1.x-50, figure1.y-220, 100, 220);
    // details
    ofSetColor(red);
    ofDrawRectangle(figure1.x-50, figure1.y-100, 100, 20);
    ofSetColor(yellow);
    ofDrawRectangle(figure1.x-50, figure1.y-60, 100, 20);
    ofSetColor(blue);
    ofDrawRectangle(figure1.x-50, figure1.y-20, 100, 20);

    // ofSetLineWidth(5);
    // Korean Flag figure
    ofSetColor(black);
    ofDrawRectangle(mouseX, mouseY, 102, 72);
    ofSetColor(white);
    ofDrawRectangle(mouseX+1, mouseY+1, 100, 70);
    ofSetColor(red);
    ofDrawRectRounded(mouseX+33, mouseY+20,0,30,15,60,60,0,0);
    ofSetColor(blue);
    ofDrawRectRounded(mouseX+33, mouseY+30,0,30,15,0,0,60,60);
    ofSetColor(red);
    ofDrawEllipse(mouseX+40.5, mouseY+30, 15,12);
    ofSetColor(blue);
    ofDrawEllipse(mouseX+55, mouseY+32, 15,12);
    
    // gui appear
    gui.draw();
    } else if( drawSecond ) {
//        cout << "mouse position: " << moveForMountain << endl;
//        cout << "color code: " << f2Color << endl;
        
    ofBackground(0,f2Color,253);
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
    ofDrawTriangle(figure2.x-262, figure2.y-230, shadowX1, figure2.y-180, figure2.x-262, figure2.y-140); //shadow1 300-250=50
    ofDrawTriangle(figure2.x-112, figure2.y-330, shadowX2, figure2.y-180, figure2.x-112, figure2.y-120); //shadow2 500-400=100
    ofDrawTriangle(figure2.x+63, figure2.y-280, shadowX3, figure2.y-180, figure2.x+63, figure2.y-200); //shadow3 650-575=75
    ofDrawTriangle(figure2.x+188, figure2.y-230, shadowX4, figure2.y-120, figure2.x+188, figure2.y-150); //shadow 4  830-700=130
        
        if(ofGetMouseX() > midX) {
            ofSetColor(yellow);
        } else if (ofGetMouseX() < midY) {
            ofSetColor(red);
        }
        ofDrawCircle(ofGetMouseX(), ofGetMouseY(), 50); // sun
        ofSetColor(black);
        bebas.drawString("SUN", ofGetMouseX()-20, ofGetMouseY());
    }
        else if ( drawThird ) { //--------- figure 3
            
    if(clicked == true) {  // setting background depending on day and night
        ofBackground(yellow);
    } else if(clicked == false){
        ofBackground(blueBlack);
    }

    ofSetColor(f3BuildingColor); // building shape inside building stroke
 ofDrawRectangle(figure3.x-105,figure3.y-50,210,50);ofDrawRectangle(figure3.x-85,figure3.y-150,170,100);ofDrawRectangle(figure3.x-65,figure3.y-370,130,220);ofDrawRectangle(figure3.x-45,figure3.y-420,90,50);ofDrawRectangle(figure3.x-35,figure3.y-450,70,30);ofDrawRectangle(figure3.x-25,figure3.y-470,50,20);
        
    ofBeginShape(); // top of the building
 ofVertex(figure3.x-5,figure3.y-470);ofVertex(figure3.x-5,figure3.y-530);ofVertex(figure3.x,figure3.y-540);ofVertex(figure3.x+5,figure3.y-530);ofVertex(figure3.x+5,figure3.y-470);
    ofEndShape();
        
    for(int i=0; i < 8; i++ ) { // Windows drawing
        ofSetColor(f3WindowColor);
        ofDrawRectangle(figure3.x-75 + (20*i), figure3.y-130, 10, 80);}
    for(int i=0; i < 2; i++ ) {
        ofSetColor(f3WindowColor);
        ofDrawRectangle(figure3.x-35 + (50*i), figure3.y-360, 10, 220);}
    for(int i=0; i < 3; i++ ) {
        ofSetColor(f3WindowColor);
        ofDrawRectangle(figure3.x-25 + (20*i), figure3.y-420, 10, 50);}
    for(int i=0; i < 2; i++ ) {
        ofSetColor(f3WindowColor);
        ofDrawRectangle(figure3.x-15 + (20*i), figure3.y-450, 10, 30);}

    ofDrawRectangle(figure3.x-5, figure3.y-470, 10, 20);

    ofSetColor(black); // black stroke empire state building
    ofSetLineWidth(5);
    line.begin(); line.addVertex(figure3.x-105,figure3.y); line.addVertex(figure3.x-105,figure3.y-50); line.addVertex(figure3.x-85,figure3.y-50); line.addVertex(figure3.x-85,figure3.y-150); line.addVertex(figure3.x-65,figure3.y-150); line.addVertex(figure3.x-65,figure3.y-370);line.addVertex(figure3.x-45,figure3.y-370);line.addVertex(figure3.x-45,figure3.y-420);line.addVertex(figure3.x-35,figure3.y-420);line.addVertex(figure3.x-35,figure3.y-450);line.addVertex(figure3.x-25,figure3.y-450);line.addVertex(figure3.x-25,figure3.y-470);line.addVertex(figure3.x-5,figure3.y-470);line.addVertex(figure3.x-5,figure3.y-530);line.addVertex(figure3.x,figure3.y-540);line.addVertex(figure3.x+5,figure3.y-530);line.addVertex(figure3.x+5,figure3.y-470);line.addVertex(figure3.x+25,figure3.y-470);line.addVertex(figure3.x+25,figure3.y-450);line.addVertex(figure3.x+35,figure3.y-450);line.addVertex(figure3.x+35,figure3.y-420);line.addVertex(figure3.x+45,figure3.y-420);line.addVertex(figure3.x+45,figure3.y-370);line.addVertex(figure3.x+65,figure3.y-370);line.addVertex(figure3.x+65,figure3.y-150);line.addVertex(figure3.x+85,figure3.y-150);line.addVertex(figure3.x+85,figure3.y-50);line.addVertex(figure3.x+105,figure3.y-50);line.addVertex(figure3.x+105,figure3.y);line.addVertex(figure3.x-105,figure3.y);line.close();
    line.draw();
    
    if(clicked) { // star color decision day / nite
        ofSetColor(black);
    } else if (!clicked) {
        ofSetColor(white);
    }
    ofBeginShape(); // star on top of the building
    ofVertex(figure3.x-15,figure3.y-565);ofVertex(figure3.x-5,figure3.y-570);ofVertex(figure3.x, figure3.y-580);ofVertex(figure3.x+5,figure3.y-570);ofVertex(figure3.x+15, figure3.y-565);ofVertex(figure3.x+5,figure3.y-560);ofVertex(figure3.x,figure3.y-550);ofVertex(figure3.x-5, figure3.y-560);
    ofEndShape();
        
    ofSetColor(black); // light switch
    ofDrawRectRounded(ofGetMouseX(), ofGetMouseY(),  0, 90, 120, 10);
    ofSetColor(white);
    ofDrawRectangle(ofGetMouseX()+10, ofGetMouseY()+10, 70, 100);
    if(clicked == true) {  // if day time, turn to night time
        ofSetColor(black);
        ofDrawRectangle(ofGetMouseX()+15, ofGetMouseY()+15, 60, 45);
        ofSetColor(white);
        
        bebas.drawString("DAY", ofGetMouseX()+20, ofGetMouseY()+50);
        if (f3WindowColor >= 0){
            f3WindowColor -= 2; // window color turns black
        }
        f3BuildingColor = 255; // buildilng color turns black;
        ofSetColor(black);
        bebas.drawString("Switch", ofGetMouseX(), ofGetMouseY());
    } else if (clicked == false) { //if night time, turn to day time
        ofSetColor(black);
        ofDrawRectangle(ofGetMouseX()+15, ofGetMouseY()+60, 60, 45);
        ofSetColor(white);
        bebas.drawString("NITE", ofGetMouseX()+19, ofGetMouseY()+97);
        if (f3WindowColor <= 255){
            f3WindowColor += 2; // window color turns black
        }
        f3BuildingColor = 0; // building color turns white
        ofSetColor(white);
        bebas.drawString("Switch", ofGetMouseX(), ofGetMouseY());
    }
       

       
    } else if ( drawForth) {
        ofBackground(blueBlack);
        ofSetColor(skyBlue);
        ofDrawCircle(figure4.x,figure4.y-250, 250);
        
        ofSetColor(yellow); // vertex of moving house
        ofBeginShape();
        ofVertex(figure4.x-110, figure4.y-260);
        ofVertex(figure4.x-10, figure4.y-360);
        ofVertex(figure4.x+90, figure4.y-260);
        ofVertex(figure4.x+40, figure4.y-260);
        ofVertex(figure4.x+40, figure4.y-160);
        ofVertex(figure4.x-60, figure4.y-160);
        ofVertex(figure4.x-60, figure4.y-260);
        ofEndShape();
        
        ofSetColor(black);
        ofSetLineWidth(5);
        line.addVertex(figure4.x-100, figure4.y-250);
        line.addVertex(figure4.x, figure4.y-350);
        line.addVertex(figure4.x+100, figure4.y-250);
        line.addVertex(figure4.x+50, figure4.y-250);
        line.addVertex(figure4.x+50, figure4.y-150);
        line.addVertex(figure4.x-50, figure4.y-150);
        line.addVertex(figure4.x-50, figure4.y-250);
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
    if(sec<10) {skirtX1 -= 1 * skirtD1;
        skirtX2 += 1 * skirtD2;
        
        if( skirtX1 <= figure1.x-160 || skirtX1 >= figure1.x-100 ) {
            skirtD1 *= -1;
            skirtD2 *= -1;
        }
    }
}

//--------------------------------------------------------------



void ofApp::mousePressed(int x, int y, int button){
//    ofVec2f figure1Up(1*d, -1);
//    ofVec2f figure1Down(1*d, 1);
    
   
//        if(up == true){
//            cout << "clicked" << endl;
//            ofSetColor(red);
//            bebas.drawString("clicked!", ofGetMouseX(), ofGetMouseY());
//            cout << "move up" << endl;
//            figure1.x += 10 * d;
//            figure1.y -= 10;
//            up = false;
//        } else if ( up == false) {
//            cout << "clicked" << endl;
//            ofSetColor(red);
//            bebas.drawString("clicked!", ofGetMouseX(), ofGetMouseY());
//            cout << "move down" << endl;
//            figure1.x += 10 * d;
//            figure1.y += 10;
//            up = true;
//        }
    
    // when mouse is clicked on the switch.
    if(sec > 10 && sec < 15) {
        if(clicked == true) {
            cout << "Clicked + false" << endl;
            clicked = false;
        } else if (clicked == false) {
            cout << "Clicked + true" <<endl;
            clicked = true;
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

