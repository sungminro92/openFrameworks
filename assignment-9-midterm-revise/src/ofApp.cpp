#include "ofApp.h"

// figure midpoints
ofVec2f figure1; // korean girl
ofVec2f figure2;
ofVec2f figure3;
ofVec2f figure4;

// Figure1 moving skirt point values
int skirtX1, skirtX2;

// X value of moving shadows point
float shadowX1,shadowX2,shadowX3,shadowX4;
// COLORS DEFINED
float shadowColor; // shadow color code

// figure 3 color 0 - 255
float f3ColorMove;
float f3BuildingColor; // figure 3 building color (white - black)
float f3WindowColor; // figure 3 window color (white - black)

// figure4 shape && moves
ofVec2f f4One, f4Two, f4Three, f4Four, f4Five, f4Six, f4Seven;
ofVec2f f4Move1, f4Move2;

// scenes division
bool first = false; // world map - where have i lived
bool second = false; // reminiscing scene
bool third = false; // 10 sec korean representations
bool fourth = false; // 10 sec korean flag information
bool fifth = false; // 15 sec koreana letter game
bool sixth = false; // 5 sec plane from korea to seattle
bool seventh = false; // 10 sec things about seattle
bool eighth = false; // 10 sec mountain rainier represent
bool nineth = false; // 10 sec tulip festival impression
bool tenth = false; // 10 sec snowboarding
bool eleventh = false; // 5 sec plane from seattle to new york
bool twelvth = false; // 10 sec empire state building
bool thirteenth = false; //

// first scene
ofVec2f pointingHandPos;
// used in korean character scene.
bool up = true;

// second scene

// fifth scene images array
int quizKey = 0;
bool errorMessage = false;
bool correctMessage = false;

// sixth scene
float kAirPosX = 0;
float deltaAirPos =0;

// nineth scene
ofVec2f start1, start2, start3, start4;

// tenth scene
ofVec2f snowboardingPos;

// twelvth scene - used in new york empire state building scene
bool clicked = true;

// images position - for moving
ofVec2f sojuPos;
ofVec2f ramenPos;
ofVec2f samsungPos;
ofVec2f lgPos;
ofVec2f kimchiPos;

//float imageXPosArry[5] = { sojuPos, ramenPos, samsungPos, lgPos, kimchiPos}

ofColor skin(251, 206, 181);
ofColor red(255,0,0);
ofColor yellow(255, 204, 0);
ofColor blue(6, 6, 255);
ofColor black(0);
ofColor white(255);
ofColor blueBlack(18, 41, 57);
ofColor skyBlue(113, 175, 186);
ofColor green(0, 255, 0);
ofColor orange(251, 176, 59);
ofColor pink(255, 123, 172);
ofColor hotPink(237,30,121);
ofColor purple(102, 45, 145);
ofColor background;
ofColor colorBank[10] = {red,yellow,blue,skyBlue,green,orange,pink,purple,skin,hotPink};


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
    bebasSmall.load("bebas.ttf", 24);
    bebasBig.load("bebas.ttf", 40);
    decorative.load("KGDefyingGravity.ttf", 50);

//    shadowX1 = figure2.x-212; // X values of moving shadow
//    shadowX2 = figure2.x-12;
//    shadowX3 = figure2.x+138;
//    shadowX4 = figure2.x+318; no need anymore
    
// figure midpoints
    figure1.set(500,600);
    figure2.set(512,600);
    figure3.set(505,650);
    figure4.set(505,650);
// first scene - world map
pointingHandPos.set(0, 320);
    Xmark.load("x.png");
    worldMap.load("world-map.png");
    travelMap.load("travel-map.png");
pointingHand.load("pointing-hand.png");
// second scene - reminiscing
thoughtBubble.load("thoughtBubble.png");


// third scene -korean related images load
    soju.load("soju.png");
    koreanAir.load("koreanAir.png");
    deltaAir.load("deltaAir.png");
    ramen.load("ramen.png");
    samsung.load("samsung.png");
    lg.load("lg.png");
    kimchi.load("kimchi.png");
    
// third scene images positions
    sojuPos.set(1, -55);
    ramenPos.set(1, 120);
    samsungPos.set(1, 300);
    lgPos.set(1, 400);
    kimchiPos.set(1, 550);
    
// fourth scene images
    cursor.load("cursor-icon.png");
    koreanFlag.load("korean-flag.png");
    

    
// fifth scene - puzzles
    for (int i = 0; i < 8; i ++) {
        koreaImages[i].load("korean-letter-0" + ofToString(i+1) + ".jpg");
    }
    letterExample.load("letter-example.jpg");
    
    // Figure1 moving skirt point values
//    skirtX1 =  figure1.x -150;
//    skirtX2 =  figure1.x +150;
    
// eighth scene
    // X value of moving shadows point
    shadowX1 = figure2.x-212;
    shadowX2 = figure2.x-12;
    shadowX3 = figure2.x+138;
    shadowX4 = figure2.x+318;
    
// nineth scene - tulip festival
    start1.set(200, ofGetHeight()); // flower stem starting point
    start2.set(400, ofGetHeight());
    start3.set(600, ofGetHeight());
    start4.set(800, ofGetHeight());
    for (int j=1; j<5; j++ ) {
        tulipImages[j-1].load("tulip" + ofToString(j) + ".png");
    }
    for (int l=0; l<7; l++) {
        leaveImages[l].load("leave" + ofToString(l) + ".png");
            }
// tenth scene - snowboarding
    snowboarding.load("snowboarding.png");
    pineTree.load("pineTree.png");
    snowboardingPos.set(0,0);
    // width =1024 / height = 768
    width = ofGetWidth();
    height = ofGetHeight();
    midX = width/2;
    midY = height/2;
}

float figure1D = 1;
float skirtD1 = 1; // figure1 decreasing X value;
float skirtD2 = 1; // figure1 increasing X value;
float f3D = 1; // figure 3 moving direction

int sec;
 // shadowColor
float moveForMountain; // mouse move measurement for mountain movement + background color
// first scene - world map
int handMove = 0;
int firstTimer;

// second scene - reminiscing
float circleSize1 = 0; // increment to size of thought bubble
float circleSize2 = 0;
float circleSize3 = 0;
float thtBubble1 = 1024;
float thtBubble2 = 768;
float thtBubbleX = 0;
float thtBubbleY = 0;
float alpha = 255;


// third scene - images direction
int imageDirection1 = 1;
int imageDirection2 = 1;
int imageDirection3 = 1;
int imageDirection4 = 1;
int imageDirection5 = 1;
int thirdTimer;

// fourth scene
int flagStatus = 0;
float increasingCircle = 0;
int fourthTimer;

// fifth scene - korean puzzle
int fifthTimer;

// sixth scene
int hour1;

// eighth scene - mountain rainier
float rain;
float rainLength;
float transparency;
int eighthTimer;

// nineth scene - tulip festival
float increment1 = 0;
int ninethTimer;

// eleventh scene
int eleventhTimer;
int hour2;


// twelveth scene - empire state building
int twelveth;

// ninth scene - tulip festival
int ninthTimer;

// in all scenes
float gradation = 1;

//--------------------------------------------------------------
void ofApp::update() {
    // time update
    sec = (ofGetFrameNum() / 60) % 110;

    // scene times
// ******* FIXED THE TIMES ********
    if(sec < 10) {
        first = true;
    }else if ( sec >= 10 && sec < 20) {
        second = true;
        first = false;
    } else if ( sec >= 20 && sec < 30) {
        third = true;
        second = false;
    } else if (sec >= 30 && sec < 40) {
        third = false;
        fourth = true;
    } else if (sec >= 40 && sec < 55) {
        fourth = false;
        fifth = true;
    } else if (sec >= 55 && sec <60) {
        fifth = false;
        sixth = true;
    } else if ( sec >= 60 && sec < 70) {
        eighth = true;
        sixth = false;
    } else if ( sec>= 70 && sec < 80) {
//        seventh = true;
        eighth = false;
        nineth = true;
    } else if (sec >= 80 && sec < 90) {
//        seventh = false;
//        eighth = true;
        nineth = false;
        tenth = true;
    } else if (sec >= 90 && sec < 95) {
        tenth = false;
        eleventh = true;
//        twelvth = true;
//        tenth = false;
    } else if (sec >= 95 && sec < 105) {
        eleventh = false;
        twelvth = true;
    }
    

// first scene - world map
    if(handMove == 0) {
        if(pointingHandPos.x <= 56) {
            pointingHandPos.x += 1;
        }
        if(pointingHandPos.x >= 56){
            handMove = 1;
        }
    } else if (handMove == 1) {
        if(pointingHandPos.x >= -600) {
            pointingHandPos.x -= 3;
        }
        if (pointingHandPos.x <= -600) {
            handMove = 2;
        }
    } else if (handMove == 2) {
        if(pointingHandPos.x <= -450) {
            pointingHandPos.x += 2;
        }
        if(pointingHandPos.x >= -450) {
            handMove = 3;
        }
    } else if (handMove ==3) {
        
    }
    
    //first scene timer
    firstTimer = ofMap(sec,0, 10, 10, 0);

// second scene
    if(sec>= 10 && sec < 20) {
        if(circleSize1 <= 20) {
            circleSize1 += 0.5;
        } else if (circleSize2 <= 40) {
            circleSize2 += 0.7;
        } else if (circleSize3 <= 60) {
            circleSize3 += 0.9;
        } else if (thtBubble1 <= thtBubble1*3) {
            thtBubble1 += 20;
            thtBubble2 += 20;
            thtBubbleX -= 11;
            thtBubbleY -= 9;
            alpha -= 3;
        }
    }
    
//--------- third scene
    if(sec>= 20 && sec < 30) {
        ofSetColor(255, 255, 255, 255);
        sojuPos.x += ofRandom(2,10) * imageDirection1;
        ramenPos.x += ofRandom(2,10) * imageDirection2;
        samsungPos.x += ofRandom(2,10) * imageDirection3;
        lgPos.x += ofRandom(2,10)  * imageDirection4;
        kimchiPos.x += ofRandom(2,10) * imageDirection5;
        
        if(sojuPos.x >= width-100 || sojuPos.x <= 0 ) {
            imageDirection1 *= -1;
        }
        if(ramenPos.x >= width-100 || ramenPos.x <= 0 ) {
            imageDirection2 *= -1;
        }
        if(samsungPos.x >= width-100 || samsungPos.x <= 0 ) {
            imageDirection3 *= -1;
        }
        if(lgPos.x >= width-100 || lgPos.x <= 0 ) {
            imageDirection4 *= -1;
        }
        if(kimchiPos.x >= width-100 || kimchiPos.x <= 0 ) {
            imageDirection5 *= -1;
        }
    }


//    if(sec < 5) {               // skirt movement
//        skirtX1 -= skirtMove * skirtD1;
//        skirtX2 += skirtMove * skirtD2;
//
//        if( skirtX1 <= figure1.x-160 || skirtX1 >= figure1.x-100 ) {
//            skirtD1 *= -1;
//            skirtD2 *= -1;
//        }
    
// fourth scene - flag (코멘트 인 하기)
    increasingCircle += 0.5;
    if ( increasingCircle >= 20) {
        increasingCircle = 0;
    }
    fourthTimer = ofMap(sec, 30, 40, 10, 0);
    
// fifth scene - puzzle scene
    fifthTimer = ofMap(sec, 40, 55, 15, 0);

// sixth scene - korea to seattle
    if (sec >= 55 && sec < 60) {
        kAirPosX += 1.7;
    }
    hour1 = ofMap(sec, 55, 60, 1, 11);

// eighth scene - mountainRainier
    moveForMountain = ofGetMouseX();
    shadowColor = ofMap(moveForMountain, 0, width, 0, 255);
    
    if (moveForMountain < 0) {
        moveForMountain = 0;
    } else if (moveForMountain > width) {
        moveForMountain = width;
    }

    if(sec > 65 && sec < 75) {
            shadowX1 = ofMap(moveForMountain, 0, width, figure2.x-212, figure2.x -212 -50 -50);
            shadowX2 = ofMap(moveForMountain, 0, width, figure2.x-12, figure2.x -12 -100 -100);
            shadowX3 = ofMap(moveForMountain, 0, width, figure2.x+138, figure2.x+138-75-75);
            shadowX4 = ofMap(moveForMountain, 0, width, figure2.x+318, figure2.x+318-130-130);
    }
    
    rain = ofMap(mouseY, 0, height, 0, 500);
    rainLength = ofMap (mouseY, 0, height, 0, 50);
    transparency = ofMap (mouseY, 0, height, 0, 255);
    
// nineth scene - tulip festival
    if(sec >= 70 && sec < 80) {
        if ( start1.y >= 400 ) {
            start1.y -= 2;
        }
        if (start2.y >= 300) {
            start2.y -= 4;
        }
        if (start3.y >= 350) {
            start3.y -= 3;
        }
        if (start4.y >= 450) {
            start4.y -= 2;
        }
    }

// tenth scene - snowboarding
    if( sec >= 80 && sec < 90) {
    snowboardingPos += ofVec2f(ofRandom(2,3),ofRandom(1.5,2.5));
    }
    
    if(snowboardingPos.y >= ofGetHeight()) {
        snowboardingPos.x = 0;
        snowboardingPos.y = 0;
    }
    
// eleventh scene - plane scene
    if (sec >= 90 && sec < 95) {
        deltaAirPos += 2.4;
    }
    hour2 = ofMap(sec, 90, 94, 1, 7);
    
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
//    f4Move1.set(0.5,0.5);
//    f4Move2.set(-0.7,-0.7);
//    if(sec>= 6 && sec < 7) {
//        f4One += f4Move1;
//        f4Two += f4Move1;
//        f4Three += f4Move1;
//        f4Four += f4Move1;
//        f4Five += f4Move1;
//        f4Six += f4Move1;
//        f4Seven += f4Move1;
//    } else if (sec>= 7 && sec <8) {
//        f4One += f4Move2;
//        f4Two += f4Move2;
//        f4Three += f4Move2;
//        f4Four += f4Move2;
//        f4Five += f4Move2;
//        f4Six += f4Move2;
//        f4Seven += f4Move2;
//    }
}


//-------------------------------------------------------------- DRAW

void ofApp::draw(){
//    cout << figure1.x << endl;
    ofPolyline curvedSegmentPolyline;
    ofPolyline line;
    ofSetCircleResolution(100);
    ofSetCurveResolution(100);

// ------ events
    if ( first ) {
        ofBackground(255);
        ofSetColor(255);
        worldMap.draw(0,0);
        ofSetColor(black);
        bebasBig.drawString("Where   Have   I   lived   so   far?", 200, 100);
        ofSetColor(red);
        if(handMove == 1) {
            Xmark.draw(780,330);
        } else if (handMove == 2) {
            Xmark.draw(780,330);
            Xmark.draw(140,300);
        } else if (handMove == 3) {
            Xmark.draw(780,330);
            Xmark.draw(140,300);
            Xmark.draw(265,305);
        }
        
        ofSetColor(255);
        pointingHand.draw(pointingHandPos.x, pointingHandPos.y);
        
        ofSetColor(0);
        bebasBig.drawString(ofToString(firstTimer),width-100,100);
    
        
    } else if (second) {
        ofEnableAlphaBlending();
        ofSetColor(black,alpha);
        ofSetLineWidth(3);
        ofNoFill();
        ofDrawCircle(80, 700, circleSize1);
        ofDrawCircle(200,650, circleSize2);
        ofDrawCircle(340,560, circleSize3);
        ofFill();
        ofSetColor(255);
        ofSetLineWidth(1);
        if(circleSize3 >= 60) {
            thoughtBubble.draw(thtBubbleX,thtBubbleY, thtBubble1, thtBubble2);
        }
//        ofDisableAlphaBlending();
        
    } else if ( third ) {
        // korean representation scene
        //background
        ofBackground(255);
        ofSetColor(255);
        soju.draw(sojuPos);
        ramen.draw(ramenPos);
        samsung.draw(samsungPos);
        lg.draw(lgPos);
        kimchi.draw(kimchiPos);
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
        // back to 100
        ofSetCircleResolution(100);
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
        //first scene timer
        
        // gui appear
        gui.draw();
    } else if( fourth ) {  // flag Study
        
        ofSetColor(255);
        //timer
        koreanFlag.draw(0,0);
        ofSetColor(black);
    bebasBig.drawString(ofToString(fourthTimer),width-100,100);
        // cursor for click icon
        ofNoFill();
        ofSetColor(black);
        ofDrawCircle(midX+25, 600, increasingCircle);
        ofSetColor(white);
        cursor.draw(midX, 600);
        ofSetColor(black);
        bebasSmall.drawString("Find out their meanings!", midX-130, 680);
        // korean flag elements drawing
        ofFill();
        ofSetColor(black);
        if(flagStatus == 1) {
            ofNoFill();
            ofSetColor(red);
            ofSetLineWidth(3);
            ofDrawCircle(430, 80, 30);
            ofFill();
            ofSetColor(red);
        } else {
            ofSetColor(black);
        }
        ofDrawRectangle(140, 300, 150, 40);
        ofDrawRectangle(140, 350, 150, 40);
        ofDrawRectangle(140, 400, 150, 40);
        
        if(flagStatus == 2) {
            ofNoFill();
            ofSetColor(red);
            ofSetLineWidth(3);
            ofDrawCircle(590, 80, 30);
            ofFill();
            ofSetColor(red);
        } else {
            ofSetColor(black);
        }
        ofDrawRectangle(340, 300, 150, 40);
        ofDrawRectangle(340, 350, 70, 40);
        ofDrawRectangle(420, 350, 70, 40);
        ofDrawRectangle(340, 400, 150, 40);
        
        if(flagStatus == 3) {
            ofNoFill();
            ofSetColor(red);
            ofSetLineWidth(3);
            ofDrawCircle(430, 175, 30);
            ofFill();
            ofSetColor(red);
        } else {
            ofSetColor(black);
        }
        ofDrawRectangle(540, 300, 70, 40);
        ofDrawRectangle(620, 300, 70, 40);
        ofDrawRectangle(540, 350, 150, 40);
        ofDrawRectangle(540, 400, 70, 40);
        ofDrawRectangle(620, 400, 70, 40);
        if(flagStatus == 4) {
            ofNoFill();
            ofSetColor(red);
            ofSetLineWidth(3);
            ofDrawCircle(590, 175, 30);
            ofFill();
            ofSetColor(red);
        } else {
            ofSetColor(black);
        }
        ofDrawRectangle(740, 300, 70, 40);
        ofDrawRectangle(820, 300, 70, 40);
        ofDrawRectangle(740, 350, 70, 40);
        ofDrawRectangle(820, 350, 70, 40);
        ofDrawRectangle(740, 400, 70, 40);
        ofDrawRectangle(820, 400, 70, 40);
        // flag details
        if(flagStatus == 1 ){
            ofSetColor(black);
            bebasBig.drawString("HEAVEN", 140, 550);
        } else if (flagStatus ==2 ){
            ofSetColor(black);
            bebasBig.drawString("FIRE", 340, 550);
        } else if (flagStatus == 3) {
            ofSetColor(black);
            bebasBig.drawString("WATER", 540, 550);
        } else if (flagStatus == 4) {
            ofSetColor(black);
            bebasBig.drawString("EARTH", 740, 550);
        }
        
    } else if ( fifth ) { // puzzles
    
        ofBackground(255);
        ofSetColor(white);
        string alphabets[8] = {"A", "B", "C", "D", "E", "F", "G", "H"};
        letterExample.draw(100,200);
        // images setting
        for (int i = 0; i < 8; i ++) {
            koreaImages[i].draw((i+1)*100-5, 500);
        } // letters setting
        for (int j = 0; j < 8; j ++) {
            ofSetColor(black);
            bebasBig.drawString(alphabets[j],((j+1)*100)+30, 700);
        }
        // blank rectangles
        int Xplacement = 500;
        int Yplacement = 200;
        for (int l = 0; l < 2; l ++) {
            for (int k = 1; k < 5; k ++) {
                ofNoFill();
                ofDrawRectangle(Xplacement, Yplacement, 100, 100);
                Xplacement += 100;
            }
            Yplacement += 100;
            Xplacement = 500;
        }
        // answers
        ofSetColor(white);
        ofFill();
        if (quizKey == 0) {
      
        } else if (quizKey == 1) {
            koreaImages[3].draw(500, 200);
            ofSetColor(white);
            ofDrawRectangle(400,500,100,200);
        } else if (quizKey == 2) {
            ofSetColor(white);
            ofDrawRectangle(400,500,100,200);
            ofDrawRectangle(600,500,100,200);
            koreaImages[3].draw(500,200);
            koreaImages[5].draw(600,200);
        } else if (quizKey == 3) {
            ofSetColor(white);
            ofDrawRectangle(400,500,100,200);
            ofDrawRectangle(600,500,100,200);
            ofDrawRectangle(100,500,100,200);
            koreaImages[3].draw(500,200);
            koreaImages[5].draw(600,200);
            koreaImages[0].draw(700,200);
        } else if (quizKey == 4) {
            koreaImages[3].draw(500,200);
            koreaImages[5].draw(600,200);
            koreaImages[0].draw(700,200);
            koreaImages[7].draw(800,200);
            ofSetColor(white);
            ofDrawRectangle(400,500,100,200);
            ofDrawRectangle(600,500,100,200);
            ofDrawRectangle(100,500,100,200);
            ofDrawRectangle(800,500,100,200);
        } else if (quizKey == 5) {
            ofSetColor(white);
            ofDrawRectangle(400,500,100,200);
            ofDrawRectangle(600,500,100,200);
            ofDrawRectangle(100,500,100,200);
            ofDrawRectangle(800,500,100,200);
            ofDrawRectangle(300,500,100,200);
            koreaImages[3].draw(500,200);
            koreaImages[5].draw(600,200);
            koreaImages[0].draw(700,200);
            koreaImages[7].draw(800,200);
            koreaImages[2].draw(300,300);
 
        } else if (quizKey == 6) {
            koreaImages[3].draw(500,200);
            koreaImages[5].draw(600,200);
            koreaImages[0].draw(700,200);
            koreaImages[7].draw(800,200);
            koreaImages[2].draw(500,300);
            koreaImages[6].draw(600,300);
            ofSetColor(white);
            ofDrawRectangle(400,500,100,200);
            ofDrawRectangle(600,500,100,200);
            ofDrawRectangle(100,500,100,200);
            ofDrawRectangle(800,500,100,200);
            ofDrawRectangle(300,500,100,200);
            ofDrawRectangle(700,500,100,200);
        } else if (quizKey == 7) {
            koreaImages[3].draw(500,200);
            koreaImages[5].draw(600,200);
            koreaImages[0].draw(700,200);
            koreaImages[7].draw(800,200);
            koreaImages[2].draw(500,300);
            koreaImages[6].draw(600,300);
            koreaImages[4].draw(700,300);
            ofSetColor(white);
            ofDrawRectangle(400,500,100,200);
            ofDrawRectangle(600,500,100,200);
            ofDrawRectangle(100,500,100,200);
            ofDrawRectangle(800,500,100,200);
            ofDrawRectangle(300,500,100,200);
            ofDrawRectangle(700,500,100,200);
            ofDrawRectangle(500,500,100,200);
        } else if (quizKey == 8) {
            koreaImages[3].draw(500,200);
            koreaImages[5].draw(600,200);
            koreaImages[0].draw(700,200);
            koreaImages[7].draw(800,200);
            koreaImages[2].draw(500,300);
            koreaImages[6].draw(600,300);
            koreaImages[4].draw(700,300);
            koreaImages[1].draw(800,300);
            ofSetColor(white);
            ofDrawRectangle(400,500,100,200);
            ofDrawRectangle(600,500,100,200);
            ofDrawRectangle(100,500,100,200);
            ofDrawRectangle(800,500,100,200);
            ofDrawRectangle(300,500,100,200);
            ofDrawRectangle(700,500,100,200);
            ofDrawRectangle(500,500,100,200);
            ofDrawRectangle(200,500,100,200);
            ofSetColor(black);
            bebasBig.drawString("=   SOUTH   KOREA", midX-200,600);
        }
        // messages
        if (errorMessage) {
            ofSetColor(red);
            bebasSmall.drawString("TRY AGAIN!", midX, 450);
        } else if (correctMessage) {
            ofSetColor(green);
            bebasSmall.drawString("NICE!", midX, 450);
        }
        //fifth scene timer
        ofSetColor(0);
        bebasBig.drawString(ofToString(fifthTimer),width-100,100);
        
    } else if (sixth) {
    
        ofBackground(255);
        ofSetColor(white);
        // airplane
        koreanAir.draw(kAirPosX, sin(kAirPosX*0.1)*10);
        ofSetColor(black);
        // sixth scene timer
        bebasBig.drawString(ofToString(hour1) + "hour" , midX-50, 500);
        bebasBig.drawString("Korea" , 100, 300);
        bebasBig.drawString("Seattle" , ofGetWidth()-300, 300);

    } else if ( eighth ) {
//        cout << "mouse position: " << moveForMountain << endl;
//        cout << "color code: " << shadowColor << endl;
        //mountain
        ofBackground(0,shadowColor,253);
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
        //shadows
        ofSetColor(skyBlue);
        ofDrawTriangle(figure2.x-262, figure2.y-230, shadowX1, figure2.y-180, figure2.x-262, figure2.y-140); //shadow1 300-250=50
        ofDrawTriangle(figure2.x-112, figure2.y-330, shadowX2, figure2.y-180, figure2.x-112, figure2.y-120); //shadow2 500-400=100
        ofDrawTriangle(figure2.x+63, figure2.y-280, shadowX3, figure2.y-180, figure2.x+63, figure2.y-200); //shadow3 650-575=75
        ofDrawTriangle(figure2.x+188, figure2.y-230, shadowX4, figure2.y-120, figure2.x+188, figure2.y-150); //shadow 4  830-700=130
        // sky Color
        if(ofGetMouseX() > midX) {
            ofSetColor(yellow);
        } else if (ofGetMouseX() < midY) {
            ofSetColor(red);
        }
        ofDrawCircle(ofGetMouseX(), ofGetMouseY(), 50); // sun
        ofSetColor(black);
        bebasSmall.drawString("SUN", ofGetMouseX()-20, ofGetMouseY());
        // raining effect
        float xPos = ofRandom(width);
        float yPos = ofRandom(height);
        for ( int i = 0; i < rain; i ++) {
            line.begin();
            ofSetLineWidth(3);
            line.addVertex(xPos, yPos);
            line.addVertex(xPos, yPos+rainLength);
            line.close();
            line.draw();
        }
        // eighth scene text
        ofSetColor(0,255-shadowColor,253, transparency);
        bebasBig.drawString("MOUNTAIN  RAINIER", midX-200, 700);

    } else if (nineth) {
      
        // sixth scene title
        ofBackground(255);
        ofSetColor(colorBank[rand() % 9]);
        bebasBig.drawString("TULIP   FESTIVAL", 350,100);
        // plants stems
        ofSetColor(0, 255, 0);
        ofDrawRectangle(200, start1.y, 35, height-start1.y);
        ofDrawRectangle(400, start2.y, 35, height-start2.y);
        ofDrawRectangle(600, start3.y, 35, height-start3.y);
        ofDrawRectangle(800, start4.y, 35, height-start4.y);
        // flower images
        ofSetColor(255);
        if (start1.y <= 400) {
            tulipImages[0].draw(110,250);
            leaveImages[0].draw(50,580);
            leaveImages[1].draw(235,540);
        }
        if (start2.y <= 300) {
            tulipImages[1].draw(320,130);
            leaveImages[2].draw(435,400);
        }
        if (start3.y <= 350) {
            tulipImages[2].draw(510,200);
            leaveImages[3].draw(520,620);
            leaveImages[4].draw(635,520);
        }
        if (start4.y <= 450) {
            tulipImages[3].draw(700,300);
            leaveImages[5].draw(700,640);
            leaveImages[6].draw(835,500);
        }

    } else if (tenth) {
       
        ofSetColor(255);
        pineTree.draw(0,0);
        ofSetColor(skyBlue);
        ofDrawTriangle(0, 0, width, height, 0, height);
        snowboarding.draw(snowboardingPos);
    
    } else if (eleventh) { // airplane from westcoast to eastcost
        ofBackground(255);
        // airplane
        ofSetColor(255);
        deltaAir.draw(deltaAirPos, sin(deltaAirPos*0.1)*10);
        ofSetColor(black);
        // sixth scene timer
        bebasBig.drawString(ofToString(hour2) + "hour" , midX-50, 500);
        
    }else if ( twelvth ) { //--------- twelvth scene - empire state building
    
        // background color day / night
        if(clicked == true) {
            ofBackground(yellow);
        } else if(clicked == false){
            ofBackground(blueBlack);
        }
        //building shape inside building stroke
        ofSetColor(f3BuildingColor);
    ofDrawRectangle(figure3.x-105,figure3.y-50,210,50);ofDrawRectangle(figure3.x-85,figure3.y-150,170,100);ofDrawRectangle(figure3.x-65,figure3.y-370,130,220);ofDrawRectangle(figure3.x-45,figure3.y-420,90,50);ofDrawRectangle(figure3.x-35,figure3.y-450,70,30);ofDrawRectangle(figure3.x-25,figure3.y-470,50,20);
        // top of the building - star
        ofBeginShape();
        ofVertex(figure3.x-5,figure3.y-470);ofVertex(figure3.x-5,figure3.y-530);ofVertex(figure3.x,figure3.y-540);ofVertex(figure3.x+5,figure3.y-530);ofVertex(figure3.x+5,figure3.y-470);
        ofEndShape();
        // Windows drawing
        for(int i=0; i < 8; i++ ) {
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
        // black stroke empire state building
        ofSetColor(black);
        ofSetLineWidth(5);
        line.begin(); line.addVertex(figure3.x-105,figure3.y); line.addVertex(figure3.x-105,figure3.y-50); line.addVertex(figure3.x-85,figure3.y-50); line.addVertex(figure3.x-85,figure3.y-150); line.addVertex(figure3.x-65,figure3.y-150); line.addVertex(figure3.x-65,figure3.y-370);line.addVertex(figure3.x-45,figure3.y-370);line.addVertex(figure3.x-45,figure3.y-420);line.addVertex(figure3.x-35,figure3.y-420);line.addVertex(figure3.x-35,figure3.y-450);line.addVertex(figure3.x-25,figure3.y-450);line.addVertex(figure3.x-25,figure3.y-470);line.addVertex(figure3.x-5,figure3.y-470);line.addVertex(figure3.x-5,figure3.y-530);line.addVertex(figure3.x,figure3.y-540);line.addVertex(figure3.x+5,figure3.y-530);line.addVertex(figure3.x+5,figure3.y-470);line.addVertex(figure3.x+25,figure3.y-470);line.addVertex(figure3.x+25,figure3.y-450);line.addVertex(figure3.x+35,figure3.y-450);line.addVertex(figure3.x+35,figure3.y-420);line.addVertex(figure3.x+45,figure3.y-420);line.addVertex(figure3.x+45,figure3.y-370);line.addVertex(figure3.x+65,figure3.y-370);line.addVertex(figure3.x+65,figure3.y-150);line.addVertex(figure3.x+85,figure3.y-150);line.addVertex(figure3.x+85,figure3.y-50);line.addVertex(figure3.x+105,figure3.y-50);line.addVertex(figure3.x+105,figure3.y);line.addVertex(figure3.x-105,figure3.y);line.close();
        line.draw();
        // star color decision day / nite
        if(clicked) {
            ofSetColor(black);
        } else if (!clicked) {
            ofSetColor(white);
        }
        ofBeginShape(); // star on top of the building
        ofVertex(figure3.x-15,figure3.y-565);ofVertex(figure3.x-5,figure3.y-570);ofVertex(figure3.x, figure3.y-580);ofVertex(figure3.x+5,figure3.y-570);ofVertex(figure3.x+15, figure3.y-565);ofVertex(figure3.x+5,figure3.y-560);ofVertex(figure3.x,figure3.y-550);ofVertex(figure3.x-5, figure3.y-560);
        ofEndShape();
        // light switch
        ofSetColor(black);
        ofDrawRectRounded(ofGetMouseX(), ofGetMouseY(),  0, 90, 120, 10);
        ofSetColor(white);
        ofDrawRectangle(ofGetMouseX()+10, ofGetMouseY()+10, 70, 100);
        // if day time, turn to night time
        if(clicked == true) {
            ofSetColor(black);
            ofDrawRectangle(ofGetMouseX()+15, ofGetMouseY()+15, 60, 45);
            ofSetColor(white);
            bebasSmall.drawString("DAY", ofGetMouseX()+20, ofGetMouseY()+50);
            if (f3WindowColor >= 0){
                // window color turns black
                f3WindowColor -= 2;
            }
            // buildilng color turns black;
            f3BuildingColor = 255;
            ofSetColor(black);
            bebasSmall.drawString("Switch", ofGetMouseX(), ofGetMouseY());
        } else if (clicked == false) {
            //if night time, turn to day time
            ofSetColor(black);
            ofDrawRectangle(ofGetMouseX()+15, ofGetMouseY()+60, 60, 45);
            ofSetColor(white);
            bebasSmall.drawString("NITE", ofGetMouseX()+19, ofGetMouseY()+97);
            if (f3WindowColor <= 255){
                // window color turns black
                f3WindowColor += 2;
            }
            // building color turns white
            f3BuildingColor = 0;
            ofSetColor(white);
            bebasSmall.drawString("Switch", ofGetMouseX(), ofGetMouseY());
        }

    } else if (thirteenth) {
       
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
    
    // Korean Flag figure
//    ofSetColor(black);
//    ofDrawRectangle(mouseX, mouseY, 102, 72);
//    ofSetColor(white);
//    ofDrawRectangle(mouseX+1, mouseY+1, 100, 70);
//    ofSetColor(red);
//    ofDrawRectRounded(mouseX+33, mouseY+20,0,30,15,60,60,0,0);
//    ofSetColor(blue);
//    ofDrawRectRounded(mouseX+33, mouseY+30,0,30,15,0,0,60,60);
//    ofSetColor(red);
//    ofDrawEllipse(mouseX+40.5, mouseY+30, 15,12);
//    ofSetColor(blue);
//    ofDrawEllipse(mouseX+55, mouseY+32, 15,12);
    
}

void ofApp::keyPressed(int key){
   
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
// fifth scene key events - puzzle scene
    if(sec > 40 && sec < 55){
        if(quizKey == 0) {
            cout << "d key pressed" << endl;
            if(key == 'd') {
                quizKey = 1;
                errorMessage = false;
                correctMessage = true;
            } else {
                errorMessage = true;
            }
        } else if (quizKey == 1) {
            cout << "f key pressed" << endl;
            if(key == 'f') {
                quizKey = 2;
                errorMessage = false;
                correctMessage = true;
            } else {
                errorMessage = true;
            }
        } else if (quizKey == 2) {
            cout << "a key pressed" << endl;
            if(key == 'a') {
                quizKey = 3;
                errorMessage = false;
                correctMessage = true;
            } else {
                errorMessage = true;
            }
        } else if (quizKey == 3) {
            cout << "h key pressed" << endl;
            if(key == 'h') {
                quizKey = 4;
                errorMessage = false;
                correctMessage = true;
            } else {
                errorMessage = true;
            }
        } else if (quizKey == 4) {
            cout << "c key pressed" << endl;
            if(key == 'c') {
                quizKey = 5;
                errorMessage = false;
                correctMessage = true;
            } else {
                errorMessage = true;
            }
        } else if (quizKey == 5) {
            cout << "g key pressed" << endl;
            if(key == 'g') {
                quizKey = 6;
                errorMessage = false;
                correctMessage = true;
            } else {
                errorMessage = true;
            }
        } else if (quizKey == 6) {
            cout << "e key pressed" << endl;
            if(key == 'e') {
                quizKey = 7;
                errorMessage = false;
                correctMessage = true;
            } else {
                errorMessage = true;
            }
        } else if (quizKey == 7) {
            cout << "b key pressed" << endl;
            if(key == 'b' ) {
                quizKey = 8;
                errorMessage = false;
                correctMessage = true;
            } else {
                errorMessage = true;
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
//    if(sec<10) {skirtX1 -= 1 * skirtD1;
//        skirtX2 += 1 * skirtD2;
//
//        if( skirtX1 <= figure1.x-160 || skirtX1 >= figure1.x-100 ) {
//            skirtD1 *= -1;
//            skirtD2 *= -1;
//        }
//    }
}

//--------------------------------------------------------------



void ofApp::mousePressed(int x, int y, int button){

// fourth scene - korean flag info
    if(sec >= 30 && sec < 40 ){
        cout << mouseX << "," << mouseY << endl;
        if(mouseX > 140 && mouseX < 290 && mouseY > 300 && mouseY < 440) {
            cout << "cliked heaven" << endl;
            flagStatus = 1;
        } else if( mouseX>340 && mouseX<490 && mouseY>300 && mouseY<440){
            cout << "cliked Fire" << endl;
            flagStatus = 2;
        } else if ( mouseX>540 && mouseX<690 && mouseY>300 && mouseY<440 ) {
            cout << "clicked water" << endl;
            flagStatus = 3;
        } else if ( mouseX >740 && mouseX <890 && mouseY>300 && mouseY<440) {
            cout << "clicked earth" << endl;
            flagStatus = 4;
        } else {
            flagStatus = 0;
        }
    }
    
    
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
    
    // twelvth scene -- switch being clicked.
    if(sec > 95 && sec < 105) {
        if(clicked == true) {
            cout << "Day Time" << endl;
            clicked = false;
        } else if (clicked == false) {
            cout << "Night Time" <<endl;
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

