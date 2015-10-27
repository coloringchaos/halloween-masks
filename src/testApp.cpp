#include "testApp.h"

using namespace ofxCv;

void testApp::setup() {
	cam.initGrabber(1280, 720);
	tracker.setup();
    mummy.loadImage("mummy-head.png");
    pumpkin.loadImage("pumpkin-head.png");
    frank.loadImage("frank-head.png");
    eyeR.loadImage("mummy-eye.png");
    eyeL.loadImage("mummy-eye.png");
    
    

    mummyMask.setup(mummy, eyeR);
}

void testApp::exit() {
    tracker.waitForThread();
}

//--------------------------------------------------------------
void testApp::update() {
	cam.update();
    mummyMask.update();
	if(cam.isFrameNew()) {
        tracker.update(toCv(cam));
        
        //loop through array of masks here?
        
        mummyMask.position = tracker.getPosition();
        mummyMask.left =tracker.getImagePoint(0);    //left side of face
        mummyMask.right =tracker.getImagePoint(16);  //right side of face
        mummyMask.eyeLPos =tracker.getImagePoint(38);
        mummyMask.eyeRPos =tracker.getImagePoint(44);
        mummyMask.leftEyeOpenScale =tracker.getGesture(ofxFaceTracker::LEFT_EYE_OPENNESS);
        mummyMask.rightEyeOpenScale =tracker.getGesture(ofxFaceTracker::RIGHT_EYE_OPENNESS);

	}
    
   
    
}

//--------------------------------------------------------------
void testApp::draw() {
	cam.draw(0, 0);
//	ofSetLineWidth(2);
//	tracker.draw();
//    auto openEyeL = tracker.getGesture(ofxFaceTracker::LEFT_EYE_OPENNESS);
    
//    cout<<openEyeL<<endl;
    
	ofDrawBitmapString(ofToString((int) ofGetFrameRate()), 10, 20);
   
    mummyMask.draw();

}

void testApp::keyPressed(int key) {
	if(key == 'r') {
		tracker.reset();
	}
}