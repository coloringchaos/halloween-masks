//  mask.h
//  ofApp
//


#pragma once
#include "ofMain.h"

class Mask {
public:
    Mask();
    void setup(ofImage face, ofImage eyeR, ofImage eyeL);
    void update();
    
    void drawMummy();
    void drawPumpkin();
    void drawFrank();
    
    ofVec2f position;
    ofVec2f left, right, eyeLPos, eyeRPos;
    float leftEyeOpenScale, rightEyeOpenScale;
    float scaleFactor;
    float rotAngle;
    
private:
    ofImage aFace;
    ofImage aEyeR;
    ofImage aEyeL;
};