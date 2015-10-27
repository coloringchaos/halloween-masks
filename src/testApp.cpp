#include "testApp.h"

using namespace ofxCv;

void testApp::setup() {
	cam.initGrabber(1280, 720);
	tracker.setup();
    
    mummy.loadImage("mummy-head.png");
    mEyeR.loadImage("mummy-eye.png");
    mEyeL.loadImage("mummy-eye.png");
    
    pumpkin.loadImage("pumpkin-head.png");
    pEyeR.loadImage("pumpkin-eyeR.png");
    pEyeL.loadImage("pumpkin-eyeL.png");
    
    
    frank.loadImage("frank-head.png");
    fEyeR.loadImage("frank-eye.png");
    fEyeL.loadImage("frank-eye.png");
    

    mMask.setup(mummy, mEyeR, mEyeL);
    pMask.setup(pumpkin, pEyeR, pEyeL);
    fMask.setup(frank, fEyeR, fEyeL);
}

void testApp::exit() {
    tracker.waitForThread();
}

//--------------------------------------------------------------
void testApp::update() {
	cam.update();

    mMask.update();
	if(cam.isFrameNew()) {
        tracker.update(toCv(cam));

        mMask.position = tracker.getPosition();
        mMask.left =tracker.getImagePoint(0);    //left side of face
        mMask.right =tracker.getImagePoint(16);  //right side of face
        mMask.eyeLPos =tracker.getImagePoint(38);
        mMask.eyeRPos =tracker.getImagePoint(44);
        mMask.leftEyeOpenScale =tracker.getGesture(ofxFaceTracker::LEFT_EYE_OPENNESS);
        mMask.rightEyeOpenScale =tracker.getGesture(ofxFaceTracker::RIGHT_EYE_OPENNESS);
	}
    
    
    pMask.update();
    if(cam.isFrameNew()) {
        tracker.update(toCv(cam));
        
        pMask.position = tracker.getPosition();
        pMask.left =tracker.getImagePoint(0);    //left side of face
        pMask.right =tracker.getImagePoint(16);  //right side of face
        pMask.eyeLPos =tracker.getImagePoint(38);
        pMask.eyeRPos =tracker.getImagePoint(44);
        pMask.leftEyeOpenScale =tracker.getGesture(ofxFaceTracker::LEFT_EYE_OPENNESS);
        pMask.rightEyeOpenScale =tracker.getGesture(ofxFaceTracker::RIGHT_EYE_OPENNESS);
    }
    
    fMask.update();
    if(cam.isFrameNew()) {
        tracker.update(toCv(cam));
        
        fMask.position = tracker.getPosition();
        fMask.left =tracker.getImagePoint(0);    //left side of face
        fMask.right =tracker.getImagePoint(16);  //right side of face
        fMask.eyeLPos =tracker.getImagePoint(38);
        fMask.eyeRPos =tracker.getImagePoint(44);
        fMask.leftEyeOpenScale =tracker.getGesture(ofxFaceTracker::LEFT_EYE_OPENNESS);
        fMask.rightEyeOpenScale =tracker.getGesture(ofxFaceTracker::RIGHT_EYE_OPENNESS);
    }

}

//--------------------------------------------------------------
void testApp::draw() {
	cam.draw(0, 0);
    
	ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);
    
    mMask.drawMummy();
//    pMask.drawPumpkin();
//    fMask.drawFrank();

}

void testApp::keyPressed(int key) {
	if(key == 'r') {
		tracker.reset();
	}
}







