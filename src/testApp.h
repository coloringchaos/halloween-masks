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
    ofxFaceTrackerThreaded tracker;
    
    Mask mMask;
    
    ofImage mummy;
    ofImage pumpkin;
    ofImage frank;
    ofImage mEyeR, mEyeL, pEyeR, pEyeL, fEyeR, fEyeL;
    ofImage mMouth, pMouth, fMouth;
    
    
    ofVec2f position;
    int scale;
    ofVec3f orientation;
    ofMatrix4x4 rotationMatrix;
    ofVec2f left, right, eyeLPos, eyeRPos;

};
