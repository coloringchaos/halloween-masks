#include "testApp.h"

using namespace ofxCv;

void testApp::setup() {
	cam.initGrabber(1280, 720);
	tracker.setup();
    
    mummy.loadImage("mummy-head.png");
    mEyeR.loadImage("mummy-eye.png");
    mEyeL.loadImage("mummy-eye.png");
    mMouth.loadImage("mummy-mouth.png");
    
    pumpkin.loadImage("pumpkin-head.png");
    pEyeR.loadImage("pumpkin-eyeR.png");
    pEyeL.loadImage("pumpkin-eyeL.png");
    pMouth.loadImage("pumpkin-mouth.png");
    
    frank.loadImage("frank-head.png");
    fEyeR.loadImage("frank-eye.png");
    fEyeL.loadImage("frank-eye.png");
    fMouth.loadImage("frank-mouth.png");
    
    
    // to get a random face
    int mode = floor(ofRandom(2.999999)); // to get 0, 1, 2
    mMask.faceMode = mode;
    switch ( mode ) {
        case 0:
            mMask.setup(mummy, mEyeR, mEyeL, mMouth);
            
            break;
        case 1:
            mMask.setup(pumpkin, pEyeR, pEyeL, pMouth);
            break;
        case 2:
            mMask.setup(frank, fEyeR, fEyeL, fMouth);
            break;
        default:
            break;
    }
    
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
        
        ofLine(tracker.getImagePoint(48), tracker.getImagePoint(54));
        
        mMask.checkPresence();
	}

}

//--------------------------------------------------------------
void testApp::draw() {
	cam.draw(0, 0);
    
	ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);
    
    mMask.display();
   
}

void testApp::keyPressed(int key) {
	if(key == 'r') {
		tracker.reset();
	}
}







