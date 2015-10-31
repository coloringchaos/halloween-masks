//  mask.h
//  ofApp
//


#pragma once
#include "ofMain.h"
//#import <Syphon/Syphon.h>

class Mask {
public:
    Mask();
    void setup(ofImage face, ofImage eyeR, ofImage eyeL, ofImage mouth);
    void update();
    void display();
    
    void checkPresence();
    void updateMode();
    
    void drawMummy();
    void drawPumpkin();
    void drawFrank();
    void drawGhost();
    void drawVamp();

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
    
    int newMode;
    
//    ofxTimer myTimer;
    
private:
    ofImage aFace;
    ofImage aEyeR;
    ofImage aEyeL;
    ofImage aMouth;
};