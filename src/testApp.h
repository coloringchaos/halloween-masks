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
    
    ofImage mummy, mEyeR, mEyeL, mMouth;
    ofImage pumpkin, pEyeR, pEyeL, pMouth;
    ofImage frank, fEyeR, fEyeL, fMouth;
    ofImage ghost, gEyeR, gEyeL, gMouth;
    ofImage vamp, vEyeR, vEyeL, vMouth;
    
    ofVec2f position;
    int scale;
    ofVec3f orientation;
    ofMatrix4x4 rotationMatrix;
    ofVec2f left, right, eyeLPos, eyeRPos;

};
