// This game is designed to depict the terrifying moment of natural disaster and to urge and bring on everyone's intuitive sense of bravery and heroism.

#include "ofApp.h"

//bool gameStarted = false;
int stage = 0;
int peopleSaved = 0;
int savedY = 690;
int savedY2 = 690;

ofColor pink(255,234,231);
ofColor skyBlue(166,206,206);
ofColor darkBlue(128,181, 175);
ofColor red(255,0, 0);
ofColor blue(0,0,255);
ofColor black(0,0,0);
ofColor white(255,255,255);

ofTrueTypeFont title;
ofTrueTypeFont subtitle;
ofTrueTypeFont description;
ofImage instruction1;

ofVec2f fire;

// level distribution
const int level = 10;
people myPeople[level];

character myCharacter;

flag myFlag;

class floor myFloor[4];

window myWindows[4];
window myWindows2[4];

// x position of the door placement
int doorX[5] = {700, 300, 700, 400, 600};
int doorY[5] = {80, 215, 360, 505, 650}; // each door y values
int floorY[4] = {285, 430, 575, 720}; // used for floors
int buildingY[4] = {150, 295, 440, 585}; // used for building floors / windows placement

// place people at random floor
int peopleY[4] = {265, 400, 535, 670};

ofColor colors[2] = {red, blue};

void floor::setup() {

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
    // make the window breakable
}
void window::draw() {
    if ( color == red ) {
        ofSetColor(red);
        ofDrawRectangle(pos, width, 140);
    } else if ( color == blue) {
        ofSetColor(blue);
        ofDrawRectangle(pos, width, 140);
    }
}

int window::getX() {
    return pos.x;
}
int window:: getY() {
    return pos.y;
}
//--------------------------------------------------------------

void people::setup() {
    int flo = ofRandom(0,4);
    // set up the position for each person
    pos = ofPoint(ofRandom(220,804), floorY[(int)flo]-20);
    floor = flo;
    color = colors[(int)ofRandom(0,2)];
}

float people::getX() {
    return pos.x;
}

float people::getY() {
    return pos.y;
}

void people::update() {
    
}


void people::draw() {
    if (alive == false && color == red) {
        ofSetColor(red);
        ofDrawCircle(getX(),getY(),size);
    } else if ( alive == false && color == blue) {
        ofSetColor(blue);
        ofDrawCircle(getX(),getY(),size);
    }
}




//--------------------------------------------------------------
void character::setup() {
    pos = ofPoint(ofGetWidth()/2, floorY[3]-20);
    floor = 3;
}

void character::update() {
    if(fire.y <= myCharacter.pos.y) {
        myCharacter.dead = true;
    }
}



void character::draw() {
    if (!dead) {
        ofSetColor(black);
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
    
    // draw people
    for(int i=0; i<level; i++){
        myPeople[i].setup();
    }
    
    // setting up postition for building floors
    for(int i = 0; i< 4; i++) {
        myFloor[i].pos = ofPoint(200,buildingY[i]);
    }
    
    //setting up window postitions
    bool existRed = false;
    bool existBlue = false;
    
    // if there is ALL RED or ALL BLUE, run the setting again!
    while (!(existRed && existBlue)) {
        existRed = false;
        existBlue = false;
        for(int i = 0; i< 4; i++) {
            myWindows[i].pos = ofPoint(180, buildingY[i]);
            myWindows[i].floor = i;
            myWindows[i].color = colors[(int)ofRandom(0,2)];
            if (myWindows[i].color == red) {
                existRed = true;
            }
            myWindows2[i].pos = ofPoint(824, buildingY[i]);
            myWindows2[i].floor = i;
            myWindows2[i].color = colors[(int)ofRandom(0,2)];
            if (myWindows[i].color == blue) {
                existBlue = true;
            }
        }
    }
    
    // position for fire
    fire.set(140, 768);
    
    // setting up postition for character
    myCharacter.setup();
    
    // draw flag
    myFlag.pos = ofPoint(ofGetWidth()/2,80);
   
}

float increment = 0.003; // increment for fire and detailed particles
int sec;

void ofApp::update(){
    if(stage == 1) {
        fire.y -= increment; // increase the fire through the building
        
        // if character meets the floor = character dead.
        if ( myCharacter.pos.y >= fire.y ) {
            myCharacter.dead = true;
            stage = 2;
        }
        
        // update for mounted person
        for(int i=0; i<level; i++) {
            if (myPeople[i].mounted == true) {
                myPeople[i].pos.x = myCharacter.getX();
                myPeople[i].pos.y = myCharacter.getY()-30;
            }
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
        
        ofSetColor(red);
        
    } else if(stage == 1 && !myCharacter.dead) {
        ofResetElapsedTimeCounter(); // counting time.
        
        // whole building
        ofSetColor(skyBlue);
        ofFill();
        ofSetLineWidth(1);
        
        for(int i=0; i < 4; i++) { // drawing floors, windows, floor separations
            myFloor[i].draw();
            myWindows[i].draw();
            myWindows2[i].draw();
            ofSetColor(darkBlue);
            ofDrawRectangle(177, floorY[i] ,   670, 10);
        }
        
        // door placement
        for(int i=0; i<5; i++) {
            ofSetColor(darkBlue);
            ofDrawRectangle(doorX[i],doorY[i],40,70);
        };
        
        // draw people in the building
        for(int i=0; i<level; i++){
            myPeople[i].draw();
            if(myPeople[i].mounted == true) {
                cout << myPeople[i].pos.x << endl;
            }
        }
        
        // flag placement
        ofSetColor(black);
        ofDrawRectangle(myFlag.pos.x, myFlag.pos.y,10,70);
        ofSetColor(white);
        if (!myFlag.reached) {
            ofDrawTriangle(ofGetWidth()/2+10,120,ofGetWidth()/2+30,130,ofGetWidth()/2+10,140);
        } else if (myFlag.reached) {
            ofDrawTriangle(ofGetWidth()/2+10,80,ofGetWidth()/2+30,90,ofGetWidth()/2+10,100);
        }
        
        // draw a character
        myCharacter.draw();
        
        // draw fire moving up
        ofSetColor(red);
        ofDrawRectangle(140, fire.y, 740, ofGetHeight() - fire.y);
        subtitle.drawString("left over people: " + ofToString(level-peopleSaved), ofGetWidth()/2-170, 50);
        for(int i=0; i < 500; i++) {
            ofSetColor(255,92,0); // orange
            ofDrawRectangle(ofRandom(140,870),ofRandom(fire.y+increment,ofGetHeight()),10,10);
            ofSetColor(252,233,3); // yellow
            ofDrawRectangle(ofRandom(140,870),ofRandom(fire.y+increment+increment,ofGetHeight()),10,10);
        }
        
    } else if (stage == 2) { // when the character dies
        ofBackground(red);
        for(int i=0; i < 1000; i++) {
            float size = ofRandom(0,30);
            ofSetColor(255,92,0); // orange
            ofDrawRectangle(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),size,size);
            ofSetColor(252,233,3); // yellow
            ofDrawRectangle(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),size,size);
        }
//        myCharacter.draw();
        ofSetColor(255,255,0);
        subtitle.drawString("THE FLOOR IS LAVA!!!", ofGetWidth()/2-155, ofGetHeight()/2);
        subtitle.drawString("YOU SAVED: " + ofToString(peopleSaved) + " PEOPLE", ofGetWidth()/2-160, ofGetHeight()/2 + 50);
//        ofSetLineWidth(3);
//        ofNoFill();
//        ofDrawRectangle(ofGetWidth()/2-100, ofGetHeight()/2 + 100, 200, 50);
//        ofFill();
//        subtitle.drawString("PLAY AGAIN", ofGetWidth()/2-85, ofGetHeight()/2 + 135);
        
    } else if (stage == 3) { // when the character saves all!
        ofBackground(white);
        ofSetColor(black);
        subtitle.drawString("WOW! YOU'RE A SUPER HERO!", ofGetWidth()/2-270, ofGetHeight()/2);

    }
}

void ofApp::keyPressed(int key){
    
    // When game is playing.
    if (stage == 1) {
        if(myCharacter.pos.x <= 200 ) {
            myCharacter.pos.x = 202;
        }
        if(myCharacter.pos.x >= 824) {
            myCharacter.pos.x = 822;
        }
        
        if(key == OF_KEY_RIGHT && myCharacter.pos.x <= 824 && myCharacter.pos.x >= 200) {
            myCharacter.pos.x += 10;
        }
        
        if (key == OF_KEY_LEFT && myCharacter.pos.x >= 200 && myCharacter.pos.x <= 824) {
            myCharacter.pos.x -= 10;
        }
        
        // from 4th UP to top floor.
        if (key == OF_KEY_UP && myCharacter.pos.x >= 300 && myCharacter.pos.x <= 340 && myCharacter.pos.y > floorY[0]-135 && myCharacter.pos.y < floorY[0]) {
            myCharacter.pos.x = 720;
            myCharacter.pos.y = floorY[0]-155;
            myCharacter.floor = -1;
        }
        
        // from 3rd UP to 4th
        if (key == OF_KEY_UP && myCharacter.pos.x >= 700 && myCharacter.pos.x <= 740 && myCharacter.pos.y > floorY[0]+10 && myCharacter.pos.y < floorY[1]) {
            myCharacter.pos.x = 320;
            myCharacter.pos.y = floorY[0]-20;
            myCharacter.floor = 0;
        }
        // from 2nd UP to 3rd.
        if (key == OF_KEY_UP && myCharacter.pos.x >= 400 && myCharacter.pos.x <= 440 && myCharacter.pos.y > floorY[1]+10 && myCharacter.pos.y < floorY[2]) {
            myCharacter.pos.x = 720;
            myCharacter.pos.y = floorY[1]-20;
            myCharacter.floor = 1;
        }
        
        // from 1st UP to 2nd.
        if (myCharacter.pos.x >= 600 && myCharacter.pos.x <= 640 && myCharacter.pos.y > floorY[2]+10 && myCharacter.pos.y < floorY[3]+10 && key == OF_KEY_UP) {
            myCharacter.pos.x = 420;
            myCharacter.pos.y = floorY[2]-20;
            myCharacter.floor = 2;
        }
        
        // from 2nd DOWN to 1st.
        if (key == OF_KEY_DOWN && myCharacter.pos.x >= 400 && myCharacter.pos.x <= 440 && myCharacter.pos.y > floorY[1]+10 && myCharacter.pos.y < floorY[2]+10) {
            myCharacter.pos.x = 620;
            myCharacter.pos.y = floorY[3]-20;
            myCharacter.floor = 3;
        }
        
        // from 3rd DOWN to 2nd
        if (key == OF_KEY_DOWN && myCharacter.pos.x >= 700 && myCharacter.pos.x <= 740 && myCharacter.pos.y > 286 && myCharacter.pos.y < 420) {
            myCharacter.pos.x = 420;
            myCharacter.pos.y = floorY[2]-20;
            myCharacter.floor = 2;
        }

        // from 4th DOWN to 3rd.
        if (key == OF_KEY_DOWN && myCharacter.pos.x >= 300 && myCharacter.pos.x <= 340 && myCharacter.pos.y > 150 && myCharacter.pos.y < 285) {
            myCharacter.pos.x = 720;
            myCharacter.pos.y = floorY[1]-20;
            myCharacter.floor = 1;
        }
        // from top DOWN to 4th
        if (key == OF_KEY_DOWN && myCharacter.pos.x >= 700 && myCharacter.pos.x <= 740 && myCharacter.pos.y > floorY[0]-270 && myCharacter.pos.y < floorY[0]-135) {
            myCharacter.pos.x = 320;
            myCharacter.pos.y = floorY[0]-20;
            myCharacter.floor = 0;
        }
    }


}

void ofApp::keyReleased(int key){
    // when space is released
    if(key == OF_KEY_SPACE && stage == 1) {
        // going through all people
        for(int i=0; i<level; i++){
            // if the person is at same position and not mounted, pick up
            if(myCharacter.pos.x > myPeople[i].getX() - 10 &&
               myCharacter.pos.x < myPeople[i].getX() + 10 && myCharacter.pos.y == myPeople[i].getY() && myPeople[i].mounted == false && myCharacter.hasOne == false) {
                    myPeople[i].mounted = true;
                    myCharacter.hasOne = true;
                    std::cout << "picked up" << endl;
       
            // if the person is near the left window, the person is saved
            } else if ( myPeople[i].pos.x <= 220 && myPeople[i].mounted == true && myCharacter.hasOne == true ) {
                for(int j=0; j<4; j++) {
                    if((myWindows[j].color == myPeople[i].color && myWindows[j].floor ==
                        myCharacter.floor )) {
                        
                        std::cout << "saved on left";
                        peopleSaved += 1 ;
                        myPeople[i].alive = true;
                        myPeople[i].mounted = false;
                        myPeople[i].left = true;
                        myCharacter.hasOne = false;
                    }
                }
            // if ther person is near the right window, the person is saved on right
            } else if (myPeople[i].pos.x >= 820 && myPeople[i].mounted == true && myCharacter.hasOne == true ) {
                for(int j=0; j<4; j++) {
                    if(myWindows2[j].color == myPeople[i].color && myWindows2[j].floor ==
                       myCharacter.floor) {
                        std::cout << "saved on right";
                        peopleSaved += 1;
                        myPeople[i].alive = true;
                        myPeople[i].mounted = false;
                        myPeople[i].left = false;
                        myCharacter.hasOne = false;
                        std::cout << peopleSaved <<endl;
                    }
                }
            } else if ( myCharacter.pos.x > myPeople[i].getX() - 10 && myCharacter.pos.x < myPeople[i].getX() + 10 && myPeople[i].mounted == true &&    myCharacter.hasOne == true ) {
                 myPeople[i].mounted = false;
                    myPeople[i].pos = ofPoint(myPeople[i].getX(), myPeople[i].getY()+30);
                    myCharacter.hasOne = false;
                    std::cout << "released" << endl;
                    std::cout << myPeople[i].mounted <<endl;
            } else if ( myCharacter.pos.y < 150 && myCharacter.pos.x >= ofGetWidth()/2-20 && myCharacter.pos.x <= ofGetWidth()/2+20 && peopleSaved == level) {
                int sec =
                myFlag.reached = true;
                std::cout << "reached top" << endl;
                stage = 3;
                
            }
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
