//  mask.h
//  ofApp
//


#pragma once
#include "ofMain.h"

class Mask {
public:
    Mask();
    void setup(ofImage face, ofImage eye);
    void update();
    void draw();
    
    ofVec2f position;
    ofVec2f left, right, eyeLPos, eyeRPos;
    float leftEyeOpenScale,rightEyeOpenScale;
    float scaleFactor;
    float rotAngle;
    
private:
    ofImage mFace;
    ofImage mEyeR;
    ofImage mEyeL;
    
};