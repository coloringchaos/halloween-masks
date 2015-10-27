#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "mask.h"
//#include "ofxFaceTracker.h"
#include "ofxFaceTrackerThreaded.h"

class testApp : public ofBaseApp {
public:
	void setup();
	void update();
    void exit();
	void draw();
	void keyPressed(int key);
	
	ofVideoGrabber cam;
//	ofxFaceTracker tracker;
    ofxFaceTrackerThreaded tracker;
//    std::vector<Mask> mMasks;
    Mask mummyMask;
    
    ofImage mummy;
    ofImage pumpkin;
    ofImage frank;
    ofImage eyeR, eyeL;
    
//    string currentMask[];
    
    ofVec2f position;
    int scale;
    ofVec3f orientation;
    ofMatrix4x4 rotationMatrix;
    ofVec2f left, right, eyeLPos, eyeRPos;

};
