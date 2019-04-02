#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    std::string url = "https://api.darksky.net/forecast/b96163523d6a99fe63b7df16e90fb401/35.9078,-127.7669";
    
    // Now parse the JSON
    bool parsingSuccessful = json.open(url);
    
    if (parsingSuccessful)
    {
        ofLogNotice("ofApp::setup") << json.getRawString(true);
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    float humidity  = json["daily"]["data"][0]["humidity"].asFloat();
    
    //summary text and high temperature for tomorrow
    //current time, sunrise, sunset (for today)

    //Print time, sunriseTime, sunsetTime, temperature, and two other values of your choice.
    std::string summary  = json["daily"]["data"][1]["summary"].asString();
    std::string hTemp  = json["daily"]["data"][1]["temperatureHigh"].asString();
    int currentTime  = json["currently"]["time"].asInt();
    int sunrise  = json["daily"]["data"][0]["sunriseTime"].asInt();
    int sunset  = json["daily"]["data"][0]["sunsetTime"].asInt();
    
    ofColor black = ofColor::black;
    ofColor yellow = ofColor::yellow;
    
    ofBackground(black.lerp(yellow, humidity));
    ofSetColor(255);
    
    ofDrawBitmapString("Humidity = " + ofToString(humidity), 20, 40);
   //Write "Hello World" on the canvas.
    ofDrawBitmapString("Hello World", 20, 80);
    //Draw the summary text and high temperature for tomorrow on the canvas.
    ofDrawBitmapString("summary of the day" + ofToString(summary), 20, 120);
    //Draw the summary text and high temperature for tomorrow on the canvas.
    ofDrawBitmapString("High Temperature = " + ofToString(hTemp), 20, 160);
    
    // Use key presses 0-7 to print the above for each day in the forecast.
    
    // Draw an orange circle on the screen at y=100 r=50.  Its X should be a map() using our current time, sunrise/sunset, and the width of the canvas.
    cout << sunrise << endl;
    cout << sunset << endl;
    cout << currentTime << endl;
    cout << (currentTime / 60 / 60 / 24 / 31 ) % 12  << endl;
    
    ofDrawBitmapString("Current Time = " + ofToString(currentTime), 20, 200);
    ofDrawBitmapString("sunrise Time = " + ofToString(sunrise), 20, 220);
    ofDrawBitmapString("sunset Time = " + ofToString(sunset), 20, 240);
    ofDrawBitmapString( ofToString((currentTime/60/60/24/31) % 12) + "th month of the year", 20, 260);
    ofDrawBitmapString(ofToString(currentTime/60/60/24/365) + "years since 1970" , 20, 280);
    
    int days = (currentTime/60/60/24)%365;
    int month = (currentTime/60/60/24/31) % 12;
    ofDrawBitmapString(ofToString(days%30) + "days of the month" , 20, 300);
//    ofDrawBitmapString ( ofToString((currentTime/60/60/24) % 31) + "th days of the month", 20, 300);
    
    int sunPosition = ofMap(currentTime, sunrise, sunset, 0, ofGetWidth());
    int monthPosition = ofMap(month,0,12,0,ofGetWidth());
    ofSetColor(255);
    ofDrawCircle(sunPosition,100,50);
    ofSetColor(0);
    ofDrawBitmapString("SUN", sunPosition-25, 100);
    ofSetColor(255);
    ofDrawRectangle(0,350,monthPosition,50);
    
    // Use this with the current time, sunrise, sunset to map a value between 0 - 1.
//    float colorValue = ofMap(humidity, 0, 1, 0, );
    
    // Using this, make the background a lerp between yellow (255,255,0) and black.
 
//    float humidityValue = ofMap(humidity, 0, 1, )
    
    //

 
  
    


    
    
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
