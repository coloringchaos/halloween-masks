//  mask.h
//  ofApp
//


#pragma once
#include "ofMain.h"

class Mask {
public:
    Mask();
    void setup(ofImage face, ofImage eyeR, ofImage eyeL, ofImage mouth);
    void update();
    void display();
    
    void checkPresence();
    
    void drawMummy();
    void drawPumpkin();
    void drawFrank();

    float opacity;
    float fadeOutSpeed;
    float fadeInSpeed;
    
    int faceMode;
    ofVec2f position;
    ofVec2f left, right, eyeLPos, eyeRPos;
    ofVec2f prevPosition, prevLeft, prevRight, prevEyeLPos, prevEyeRPos;
    
    float leftEyeOpenScale, rightEyeOpenScale;
    float scaleFactor;
    float rotAngle;
    
private:
    ofImage aFace;
    ofImage aEyeR;
    ofImage aEyeL;
    ofImage aMouth;
    

};