#include "ofApp.h"

float seoulWindSpeed;
float nycWindSpeed;

ofVec2f cloud0, cloud1, cloud2, cloud3, cloud4, cloud5, cloud6, cloud7, cloud8, cloud9;
ofVec2f clouds[10] = {cloud0, cloud1, cloud2, cloud3, cloud4, cloud5, cloud6, cloud7, cloud8, cloud9};

ofVec2f ncloud0, ncloud1, ncloud2, ncloud3, ncloud4, ncloud5, ncloud6, ncloud7, ncloud8, ncloud9;
ofVec2f nclouds[10] = {ncloud0, ncloud1, ncloud2, ncloud3, ncloud4, ncloud5, ncloud6, ncloud7, ncloud8, ncloud9};

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
    
    // windspeed used for particles moving speed ( 0 - 1 range )
    seoulWindSpeed = seoulJSON["currently"]["windSpeed"].asFloat()/10;
    nycWindSpeed = nycJSON["currently"]["windSpeed"].asFloat()/10;
    
    // Images
    cloud.load("cloud.png");
    
    // Cloud position
    for( int i=0; i < 9; i++) {
        clouds[i].set(ofRandom(ofGetWidth()/2-100), ofRandom(150, ofGetHeight()-150));
        nclouds[i].set(ofRandom(ofGetWidth()/2-100), ofRandom(150, ofGetHeight()-150));
    }
}

// windspeed used for clouds moving speed ( 0 - 1 range )


int direction = 1;
//--------------------------------------------------------------
void ofApp::update(){

    for (int i= 0; i < 9; i ++) {
        clouds[i].x += seoulWindSpeed;
        nclouds[i].x += nycWindSpeed * direction;
    }
    
    if ( nclouds[0].x >= ofGetWidth()) {
        direction *= -1;
    }
    if ( nclouds[0].x <= ofGetWidth()) {
        direction *= -1;
    }

    
}

float seoulTemp;
float nycTemp;

int seoulCloud;
int nycCloud;

float seoulAlpha;
float nycAlpha;


//--------------------------------------------------------------
void ofApp::draw(){

// SEOUL JSON
    // humidity used for opacity of the clouds
    float seoulHumidity  = seoulJSON["daily"]["data"][0]["humidity"].asFloat();
    // sunrise, sunset, currentTime used in sun placement
    int seoulCurrentTime  = seoulJSON["currently"]["time"].asInt();
    int seoulSunrise  = seoulJSON["daily"]["data"][0]["sunriseTime"].asInt();
    int seoulSunset  = seoulJSON["daily"]["data"][0]["sunsetTime"].asInt();
    // temperature used in background color
    float seoulTemperature = seoulJSON["currently"]["temperature"].asFloat();
    // cloud cover range used to create number of clouds ( 0 - 1 range)
    float seoulCloudCover = seoulJSON["currently"]["cloudCover"].asFloat();
    float seoulVisibility = seoulJSON["currently"]["visibility"].asFloat();
    
    // NYC JSON
    // humidity used for opacity of the clouds
    float nycHumidity  = nycJSON["daily"]["data"][0]["humidity"].asFloat();
    // sunrise, sunset, currentTime used in sun placement
    int nycCurrentTime  = nycJSON["currently"]["time"].asInt();
    int nycSunrise  = nycJSON["daily"]["data"][0]["sunriseTime"].asInt();
    int nycSunset  = nycJSON["daily"]["data"][0]["sunsetTime"].asInt();
    // temperature used in background color
    float nycTemperature = nycJSON["currently"]["temperature"].asFloat();
    
    // cloud cover range used to create number of clouds
    float nycCloudCover = nycJSON["currently"]["cloudCover"].asFloat();
    float nycVisibility = nycJSON["currently"]["visibility"].asFloat();
    
//    cout << seoulHumidity << endl;
//    cout << seoulCurrentTime << endl;
//    cout << seoulSunrise << endl;
//    cout << seoulSunset << endl;
//    cout << ofGetWidth() << endl;
//    cout << ofGetHeight() << endl;
//    cout << seoulHumidity << endl;
//    cout << nycHumidity << endl;
//    cout << seoulTemperature << endl;
//    cout << nycTemperature << endl;
//    cout << seoulWindSpeed << endl;
    cout << nycVisibility << endl;
    
    // two scenes on one page
    // SEOUL temp range = 30(0'c) - 105(40'c) vs.
    seoulTemp = ofMap(seoulTemperature, 30, 105, 0, 200);
    ofSetColor(255, seoulTemp, 0);
    
    //SEOUL background with temperature
    ofDrawRectangle(0,0,ofGetWidth()/2,ofGetHeight());
    
    // SEOUL mapping cloud covver
    ofEnableAlphaBlending();
    seoulAlpha = ofMap(seoulHumidity, 0, 1, 0, 255); //
    ofSetColor(255,255,255,seoulAlpha);
    seoulCloud = ofMap(seoulCloudCover, 0, 1, 0, 10);
    for (int j=0; j < seoulCloud; j++ ) {
        cloud.draw(clouds[j].x, clouds[j].y);
    }
    ofDisableAlphaBlending();
    
    // SEOUL SUN POSITION
    int seoulSunPos = ofMap(seoulCurrentTime, seoulSunrise, seoulSunset, 0, ofGetWidth()/2);
    ofSetColor(255, 255, 0);
    ofDrawCircle(seoulSunPos,100,50);
//    ofSetColor(0);
//    ofDrawBitmapString("SUN", seoulSunPos, 100);

    
// -------------------------------------------------------------------
    // NYC temp range = 30(0'c) - 105(40'c) vs.
    nycTemp = ofMap( nycTemperature, 30, 105, 0, 200);
    // NYC mapping cloud cover
    nycCloud = ofMap(nycCloudCover, 0, 1, 0, 10);
    
    // NyC background with temperature
    ofSetColor(255, nycTemp, 0);
    ofDrawRectangle(ofGetWidth()/2,0,ofGetWidth()/2,ofGetHeight());
    
    // NYC clouds
    ofEnableAlphaBlending();
    nycAlpha = ofMap(nycHumidity, 0, 1, 0, 255);
    ofSetColor(255,nycAlpha);
    nycCloud = ofMap(nycCloudCover, 0, 1, 0, 10);
    for (int k=0; k < nycCloud; k++ ) {
        cloud.draw(nclouds[k].x + ofGetWidth()/2, nclouds[k].y);
    }
    ofDisableAlphaBlending();
    
    // NYC SUN POSITION

    int nycRedVal = ofMap(nycVisibility,0,10,150,255);
    int nycYellowVal = ofMap(nycVisibility,0,10,140,230);
    int nycSunPos = ofMap(seoulCurrentTime, nycSunrise, nycSunset, ofGetWidth()/2, ofGetWidth());
    ofSetColor(nycRedVal, nycYellowVal, 0);
    ofDrawCircle(nycSunPos,100,50);
//    ofSetColor(0);
//    ofDrawBitmapString("SUN", nycSunPos, 100);
    
    // background color correspond to the temperature
    
    // circle placement correspond to the current time
    
    // number of clouds correspond to clouds
    
    // opacitiy of clouds correspond to humidity
    
    // random drawings of black particles correspond to the ozone level
    
    // user interaction through
    
    
    
    
//
//    std::string summary  = json["daily"]["data"][1]["summary"].asString();
//    std::string hTemp  = json["daily"]["data"][1]["temperatureHigh"].asString();
//
//    ofColor black = ofColor::black;
//    ofColor yellow = ofColor::yellow;
    
//    ofBackground(black.lerp(yellow, humidity));
//    ofSetColor(255);
//
//    ofDrawBitmapString("Humidity = " + ofToString(humidity), 20, 40);
//    //Write "Hello World" on the canvas.
//    ofDrawBitmapString("Hello World", 20, 80);
//    //Draw the summary text and high temperature for tomorrow on the canvas.
//    ofDrawBitmapString("summary of the day" + ofToString(summary), 20, 120);
//    //Draw the summary text and high temperature for tomorrow on the canvas.
//    ofDrawBitmapString("High Temperature = " + ofToString(hTemp), 20, 160);
//
//    // Use key presses 0-7 to print the above for each day in the forecast.
//
//    // Draw an orange circle on the screen at y=100 r=50.  Its X should be a map() using our current time, sunrise/sunset, and the width of the canvas.
//    cout << sunrise << endl;
//    cout << sunset << endl;
//    cout << currentTime << endl;
//    cout << (currentTime / 60 / 60 / 24 / 31 ) % 12  << endl;
//

//    ofDrawBitmapString(ofToString(currentTime/60/60/24/365) + "years since 1970" , 20, 280);
//
//    int days = (currentTime/60/60/24)%365;
//    int month = (currentTime/60/60/24/31) % 12;
//    ofDrawBitmapString(ofToString(days%30) + "days of the month" , 20, 300);
//    //    ofDrawBitmapString ( ofToString((currentTime/60/60/24) % 31) + "th days of the month", 20, 300);

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
