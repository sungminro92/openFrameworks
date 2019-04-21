#include "ofApp.h"

float seoulHumidity;
float nycHumidity;

int seoulCurrentTime;
int seoulSunrise;
int seoulSunset;

int nycCurrentTime;
int nycSunrise;
int nycSunset;

float seoulTemperature; // direct data
float nycTemperature;

float seoulTemp; // mapped values for color change
float nycTemp;

float seoulWindS; // speed of clouds
float nycWindS;

ofVec2f cloud0, cloud1, cloud2, cloud3, cloud4, cloud5, cloud6, cloud7, cloud8, cloud9;
ofVec2f clouds[10] = {cloud0, cloud1, cloud2, cloud3, cloud4, cloud5, cloud6, cloud7, cloud8, cloud9};

ofVec2f ncloud0, ncloud1, ncloud2, ncloud3, ncloud4, ncloud5, ncloud6, ncloud7, ncloud8, ncloud9;
ofVec2f nclouds[10] = {ncloud0, ncloud1, ncloud2, ncloud3, ncloud4, ncloud5, ncloud6, ncloud7, ncloud8, ncloud9};

float seoulCloudCover;
float nycCloudCover;

float seoulCloudNum;
float nycCloudNum;

int seoulCloud;
int nycCloud;

float seoulAlpha;
float nycAlpha;

float seoulVisibility;
float nycVisibility;

float seoulNextDaysLow[7];
float seoulNextDaysHigh[7];
float seoulNewLow[7];
float seoulNewHigh[7];
float nycNextDaysLow[7];
float nycNextDaysHigh[7];
float nycNewLow[7];
float nycNewHigh[7];

//--------------------------------------------------------------
void ofApp::setup(){
    // seoul JSON
    std::string seoulURL = "https://api.darksky.net/forecast/b96163523d6a99fe63b7df16e90fb401/37.483571,127.016269";
    // nyc JSON
    std::string nycURL = "https://api.darksky.net/forecast/b96163523d6a99fe63b7df16e90fb401/40.748858,-73.990236";
    
    // Now parse the JSON
    bool seoulSuccessful = seoulJSON.open(seoulURL); // seoul
    bool nycSuccessful = nycJSON.open(nycURL); // nyc
    
    // checking successful?
    if (seoulSuccessful) {
        ofLogNotice("ofApp::setup") << seoulJSON.getRawString(true);
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }
    
    if (nycSuccessful) {
        ofLogNotice("ofApp::setup") << nycJSON.getRawString(true);
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }
    
    // SEOUL JSON----------------------------
    // humidity used for opacity of the clouds
    seoulHumidity  = seoulJSON["daily"]["data"][0]["humidity"].asFloat();
    // sunrise, sunset, currentTime used in sun placement
    seoulCurrentTime  = seoulJSON["currently"]["time"].asInt();
    seoulSunrise  = seoulJSON["daily"]["data"][0]["sunriseTime"].asInt();
    seoulSunset  = seoulJSON["daily"]["data"][0]["sunsetTime"].asInt();
    // temperature used in background color
    seoulTemperature = seoulJSON["currently"]["temperature"].asFloat();
    
    // windspeed used for particles moving speed ( 0 - 1 range )
    seoulWindS = seoulJSON["currently"]["windSpeed"].asFloat()/10;
    nycWindS = nycJSON["currently"]["windSpeed"].asFloat()/10;
    
    seoulVisibility = seoulJSON["currently"]["visibility"].asFloat();
    // next 7 days temperature
    for (int s = 0; s < 7; s ++) {
        seoulNextDaysLow[s] = seoulJSON["daily"]["data"][s]["temperatureLow"].asFloat();
        seoulNextDaysHigh[s] = seoulJSON["daily"]["data"][s]["temperatureHigh"].asFloat();
        seoulNewLow[s] = ofMap(seoulNextDaysLow[s], 30, 105, 50, (ofGetWidth()/2)-100);
        seoulNewHigh[s] = ofMap(seoulNextDaysHigh[s], 30, 105, 50,(ofGetWidth()/2)-100);
    }
    // ----------------------------
    
    // NYC JSON----------------------------
    // humidity used for opacity of the clouds
    nycHumidity  = nycJSON["daily"]["data"][0]["humidity"].asFloat();
    // sunrise, sunset, currentTime used in sun placement
    nycCurrentTime  = nycJSON["currently"]["time"].asInt();
    nycSunrise  = nycJSON["daily"]["data"][0]["sunriseTime"].asInt();
    nycSunset  = nycJSON["daily"]["data"][0]["sunsetTime"].asInt();
    // temperature used in background color
    nycTemperature = nycJSON["currently"]["temperature"].asFloat();
    nycVisibility = nycJSON["currently"]["visibility"].asFloat();
    for (int n = 0; n < 7; n ++) {
        nycNextDaysLow[n] = nycJSON["daily"]["data"][n]["temperatureLow"].asFloat();
        nycNextDaysHigh[n] = nycJSON["daily"]["data"][n]["temperatureHigh"].asFloat();
        nycNewLow[n] = ofMap(nycNextDaysLow[n], 30, 105, 50, (ofGetWidth()/2)-100);
        nycNewHigh[n] = ofMap(nycNextDaysHigh[n], 30, 105, 50,(ofGetWidth()/2)-100);
    }
    
    // ----------------------------

    // Images
    cloud.load("cloud.png");
    
    // CLOUDINESS
    // cloud cover range used to create number of clouds ( 0 - 1 range)
    seoulCloudCover = seoulJSON["currently"]["cloudCover"].asFloat();
    // cloud cover range used to create number of clouds
    nycCloudCover = nycJSON["currently"]["cloudCover"].asFloat();
    seoulCloudNum = ofMap(seoulCloudCover,0,1,1,10);
    nycCloudNum = ofMap(nycCloudCover,0,1,1,10);
    
    // CLOUD POSITIONS
    for( int i=0; i < 10; i++) {
        clouds[i].set(ofRandom(ofGetWidth()), ofRandom(100, ofGetHeight()-300));
    }
    for( int j=0; j < 10; j++) {
        nclouds[j].set(ofRandom(ofGetWidth()/2-100), ofRandom(100, ofGetHeight()-300));
    }
    
    gui.setup();

    gui.add(seoulBackground.setup("seoulBackground", ofMap(seoulTemperature, 30, 105, 0, 200), 200, 0));
    gui.add(nycBackground.setup("nycBackground", ofMap(nycTemperature, 30, 105, 0, 200), 200, 0));
    gui.add(seoulCloudiness.setup("seoulCloudiness", (int)seoulCloudNum,  0, 10)); // cloud numbers
    gui.add(nycCloudiness.setup("nycCloudiness", (int)nycCloudNum, 0, 10));
    gui.add(seoulBlurriness.setup("seoulBlurriness", ofMap(seoulHumidity, 0, 1, 0, 255), 0, 255));
    gui.add(nycBlurriness.setup("nycBlurriness", ofMap(nycHumidity, 0, 1, 0, 255), 0, 255));
    gui.add(seoulWindSpeed.setup("seoulWindSpeed", seoulWindS, 0, 1));
    gui.add(nycWindSpeed.setup("nycWindSpeed", nycWindS, 0, 1));
    
    gui.add(seoulSunPosition.setup("seoulSunPosition", ofMap(seoulCurrentTime, seoulSunrise, seoulSunset, 0, ofGetWidth()/2), 0, ofGetWidth()/2));
    gui.add(nycSunPosition.setup("nycSunPosition", ofMap(nycCurrentTime, nycSunrise, nycSunset, ofGetWidth()/2, ofGetWidth()), ofGetWidth()/2, ofGetWidth()));
    gui.add(seoulSunVisibility.setup("seoulSunVisibility", seoulVisibility, 0, 10));
    gui.add(nycSunVisibility.setup("nycSunVisibility", nycVisibility, 0, 10));
    gui.add(nextDays.setup("nextDays", 7, 1, 7));

}

// windspeed used for clouds moving speed ( 0 - 1 range )


int sDirection[] = {1,1,1,1,1,1,1,1,1,1,1};
int nDirection[] = {1,1,1,1,1,1,1,1,1,1,1};
//--------------------------------------------------------------
void ofApp::update(){

    for( int i=0; i < (int)seoulCloudNum; i++) {
        clouds[i].x += (seoulWindSpeed * sDirection[i]);
        
        if ( clouds[i].x >= ofGetWidth()/2-150) {
            sDirection[i] *= -1;
        }
        if ( clouds[i].x <= 0) {
            sDirection[i] *= -1;
        }
    }
   
    for( int j=0; j < (int)nycCloudNum; j++) {
        nclouds[j].x += (nycWindSpeed * nDirection[j]);
        
        if ( (nclouds[j].x+ ofGetWidth()/2) <= ofGetWidth()/2) {
            nDirection[j] *= -1;
        }
        if ( (nclouds[j].x+ ofGetWidth()/2) >= ofGetWidth()-50) {
            nDirection[j] *= -1;
        }
    }
}




//--------------------------------------------------------------
void ofApp::draw(){
    // SEOUL temp range = 30(0'c) - 105(40'c) vs.
    ofSetColor(255, seoulBackground, 0);
    
    //SEOUL background with temperature
    ofDrawRectangle(0,0,ofGetWidth()/2,ofGetHeight());
    
    // SEOUL mapping cloud cover
    ofEnableAlphaBlending();
    ofSetColor(255,seoulBlurriness);
    // draw clouds
    for (int j=0; j < (int)seoulCloudiness; j++ ) {
        cloud.draw(clouds[j].x, clouds[j].y);
    }
    ofDisableAlphaBlending();
    
    // SEOUL SUN POSITION
//    int seoulSunPos = ofMap(seoulCurrentTime, seoulSunrise, seoulSunset, 0, ofGetWidth()/2);
    int seoulRedVal = ofMap(seoulVisibility,0,10,150,255);
    int seoulYellowVal = ofMap(seoulSunVisibility,0,10,140,230);
    ofSetColor(seoulRedVal, seoulYellowVal, 0);
    ofDrawCircle(seoulSunPosition,100,50);
    ofSetColor(0);
    ofDrawBitmapString("SUN", seoulSunPosition, 100);
    
    for(int k=0; k<nextDays; k ++) {
        ofEnableAlphaBlending();
        ofSetColor(255,255,255,50);
        ofDrawRectangle(50, 500 + (25*k), (ofGetWidth()/2)-100, 10);
        ofDisableAlphaBlending();
        ofSetColor(255);
        ofDrawRectangle(seoulNewLow[k], 500 + (25*k), seoulNewHigh[k]-seoulNewLow[k], 10);
    }
    
    ofSetColor(255);
    ofDrawBitmapString("30", 45, 480);
    ofDrawBitmapString("105", ofGetWidth()/2-92, 480);
    
// -------------------------------------------------------------------
    // NYC temp range = 30(0'c) - 105(40'c) vs.
//    nycTemp = ofMap( nycTemperature, 30, 105, 0, 200);
    // NYC mapping cloud cover
    nycCloud = ofMap(nycCloudCover, 0, 1, 0, 10);
    
    // NyC background with temperature
    ofSetColor(255, nycBackground, 0);
    ofDrawRectangle(ofGetWidth()/2,0,ofGetWidth()/2,ofGetHeight());
    
    // NYC clouds
    ofEnableAlphaBlending();
    ofSetColor(255,nycBlurriness);
    // draw clouds
    for (int k=0; k < (int)nycCloudiness; k++ ) {
        cloud.draw(nclouds[k].x + ofGetWidth()/2, nclouds[k].y);
    }
    ofDisableAlphaBlending();
    
    // NYC SUN POSITION
    int nycRedVal = ofMap(nycVisibility,0,10,150,255);
    int nycYellowVal = ofMap(nycSunVisibility,0,10,140,230);
    ofSetColor(nycRedVal, nycYellowVal, 0);
    ofDrawCircle(nycSunPosition,100,50);
    ofSetColor(0);
    ofDrawBitmapString("SUN", nycSunPosition, 100);

    for(int l=0; l< nextDays; l ++) {
        ofEnableAlphaBlending();
        ofSetColor(255,255,255,50);
        ofDrawRectangle((ofGetWidth()/2)+50, 500 + (25*l), (ofGetWidth()/2)-100, 10);
        ofDisableAlphaBlending();
        ofSetColor(255);
        ofDrawRectangle((ofGetWidth()/2)+nycNewLow[l], 500 + (25*l), nycNewHigh[l]-nycNewLow[l], 10);
    }
    
    
    

    
    gui.draw();
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
