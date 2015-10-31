#include "testApp.h"

using namespace ofxCv;

void testApp::setup() {
    
    //SYPHON STUFF
    mainOutputSyphonServer.setName("Screen Output");
    mClient.setup();
    mClient.setApplicationName("Simple Server");
    mClient.setServerName("");
    
//    cam.setDeviceID(1); //for external cam
    cam.setDeviceID(0); //for isight camera
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
    
    ghost.loadImage("ghost-head.png");
    gEyeR.loadImage("ghost-eyeR.png");
    gEyeL.loadImage("ghost-eyeL.png");
    gMouth.loadImage("ghost-mouth.png");
    
    vamp.loadImage("vamp-head2.png");
    vEyeR.loadImage("vamp-eyeR.png");
    vEyeL.loadImage("vamp-eyeL.png");
    vMouth.loadImage("vamp-mouth.png");
    
//    mode = floor(ofRandom(4.999999)); // to get 0, 1, 2, 3, 4
    
    mode = 4;
    
}

void testApp::exit() {
    tracker.waitForThread();
}

//--------------------------------------------------------------
void testApp::update() {
	cam.update();
    
    cout << "mode: " << mode << endl;

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
        case 3:
            mMask.setup(ghost, gEyeR, gEyeL, gMouth);
            break;
        case 4:
            mMask.setup(vamp, vEyeR, vEyeL, vMouth);
            break;
        default:
            break;
    }
    
//    if (mMask.opacity < 70 && mMask.opacity > 30) {
//        mode = floor(ofRandom(4.999999)); // to get 0, 1, 2, 3, 4
//        mMask.faceMode = mode;
//    }
}

//--------------------------------------------------------------
void testApp::draw() {
	cam.draw(0, 0);
    
	ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);
    
    mMask.display();
    
    // SYPHON STUFF
    mClient.draw(50, 50);
    mainOutputSyphonServer.publishScreen();
}

void testApp::keyPressed(int key) {
	if(key == 'r') {
		tracker.reset();
	}
}







