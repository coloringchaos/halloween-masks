//
//  mask.cpp
//  ofApp
//

#include "mask.h"
#include "ofxTimer.h"

Mask::Mask(){
    opacity = 255;
    fadeOutSpeed = 20;
    fadeInSpeed = 30;
}

void Mask::setup(ofImage face, ofImage eyeR, ofImage eyeL, ofImage mouth){
    aFace = face;
    aEyeR = eyeR;
    aEyeL = eyeL;
    aMouth = mouth;
    
//    myTimer.setup();
}

void Mask::update(){
    float dist = ofDist(left.x, left.y, right.x, right.y);
    scaleFactor = dist/aFace.width;
    rotAngle = acos((right.x-left.x)/dist)*360./ TWO_PI;
    if (left.y > right.y) rotAngle *=-1.;
}

void Mask::display() {
    ofPushStyle();
    ofSetColor(255, opacity);
    
    switch ( faceMode ) {
        case 0:
            drawMummy();
            break;
        case 1:
            drawPumpkin();
            break;
        case 2:
            drawFrank();
            break;
        case 3:
            drawGhost();
            break;
        case 4:
            drawVamp();
            break;
        default:
            break;
    }
    ofPopStyle();
}

void Mask::checkPresence() {
    if (left.x == 0) {
//        cout << "no mask" << endl;
        if (opacity > 0) {
            opacity -= fadeOutSpeed;
        } else {
            opacity = 0;
        }
        position = prevPosition;
        left = prevLeft;
        right = prevRight;
        eyeLPos = prevEyeLPos;
        eyeRPos = prevEyeRPos;
    } else {
//        cout << "yes mask" << endl;
        if (opacity < 255) {
            opacity += fadeInSpeed;
        } else {
            opacity = 255;
        }
        prevPosition = position;
        prevLeft = left;
        prevRight = right;
        prevEyeLPos = eyeLPos;
        prevEyeRPos = eyeRPos;
    }
    
//    newMode = floor(ofRandom(4.999999)); // to get 0, 1, 2, 3, 4
    
}


void Mask::drawMummy(){
    ofPushMatrix();
        ofTranslate( position.x,   position.y );
        ofScale(scaleFactor*1.3, scaleFactor*1.3);
        ofPushMatrix();
            ofRotate(rotAngle);
            ofTranslate(- aFace.width/2,- aFace.height/1.7);
            aFace.draw(0,0);
        ofPopMatrix();
    ofPopMatrix();
    
    ofPushMatrix();
        ofTranslate(eyeLPos.x, eyeLPos.y+aEyeL.height/2.);
//        ofScale(scaleFactor/1.8, rightEyeOpenScale/9.);
        ofScale(scaleFactor/1.2, scaleFactor/1.2);
        aEyeL.draw(- aEyeL.width/2., - aEyeL.height/2);
    ofPopMatrix();
    
    ofPushMatrix();
        ofTranslate(eyeRPos.x, eyeRPos.y+aEyeR.height/2.);
//        ofScale(scaleFactor/1.8, rightEyeOpenScale/9.);
        ofScale(scaleFactor/1.2, scaleFactor/1.2);
        aEyeR.draw(- aEyeR.width/2., - aEyeR.height/2.);
    ofPopMatrix();
}

void Mask::drawPumpkin(){
    ofPushMatrix();
        ofTranslate( position.x,   position.y );
        ofScale(scaleFactor*1.5, scaleFactor*1.5);
        ofPushMatrix();
            ofRotate(rotAngle);
            ofTranslate(- aFace.width/2,- aFace.height/1.7);
            aFace.draw(0,0);
        ofPopMatrix();
    ofPopMatrix();
    
    ofPushMatrix();
        ofTranslate(eyeLPos.x, eyeLPos.y-aEyeL.height/2);
//        ofScale(scaleFactor, leftEyeOpenScale/4.);
        ofScale(scaleFactor, scaleFactor);
        aEyeL.draw(- aEyeL.width/2., aEyeL.height/2); //change height to fix eyes
    ofPopMatrix();
    
    ofPushMatrix();
        ofTranslate(eyeRPos.x, eyeRPos.y-aEyeR.height/2);
//        ofScale(scaleFactor, leftEyeOpenScale/4.);
        ofScale(scaleFactor, scaleFactor);
        aEyeR.draw(- aEyeR.width/2., aEyeR.height/2);
    ofPopMatrix();
}

void Mask::drawFrank(){
    ofPushMatrix();
        ofTranslate( position.x,   position.y );
        ofScale(scaleFactor*1.2, scaleFactor*1.2);
        ofPushMatrix();
            ofRotate(rotAngle);
            ofTranslate(- aFace.width/2,- aFace.height/1.7);
            aFace.draw(0,0);
        ofPopMatrix();
    ofPopMatrix();
    
    ofPushMatrix();
        ofTranslate(eyeLPos.x, eyeLPos.y-aEyeL.height/2);
        ofScale(scaleFactor/1.5, scaleFactor/1.5);
        aEyeL.draw(- aEyeL.width/2., aEyeR.height*3.2);
    ofPopMatrix();
    
    ofPushMatrix();
        ofTranslate(eyeRPos.x, eyeRPos.y-aEyeR.height/2);
        ofScale(scaleFactor/1.5, scaleFactor/1.5);
        aEyeR.draw(- aEyeR.width/2., aEyeR.height*3.2);
    ofPopMatrix();
}


void Mask::drawGhost(){
    ofPushMatrix();
        ofTranslate( position.x,   position.y );
        ofScale(scaleFactor*1.5, scaleFactor*1.5);
        ofPushMatrix();
            ofRotate(rotAngle);
            ofTranslate(- aFace.width/2,- aFace.height/2);
            aFace.draw(0,0);
        ofPopMatrix();
    ofPopMatrix();
    
    //trying to fix eye movement
    ofPushMatrix();
        ofTranslate(eyeLPos.x, eyeLPos.y);
        ofScale(scaleFactor/1.3, scaleFactor/1.3);
        ofPushMatrix();
            ofRotate(rotAngle*2);
            ofTranslate(- aEyeL.width/2,- aEyeL.height);
            aEyeL.draw(0, 0);
        ofPopMatrix();
    ofPopMatrix();
    
    ofPushMatrix();
        ofTranslate(eyeRPos.x, eyeRPos.y);
        ofScale(scaleFactor/1.3, scaleFactor/1.3);
        ofPushMatrix();
            ofRotate(rotAngle*2);
            ofTranslate(- aEyeR.width,- aEyeR.height);
            aEyeR.draw(0, 0);
        ofPopMatrix();
    ofPopMatrix();
    
//
//    ofPushMatrix();
//        ofTranslate(eyeLPos.x, eyeLPos.y);
//        ofScale(scaleFactor/1.3, scaleFactor/1.3);
//        aEyeL.draw(- aEyeL.width/2, - aEyeR.height);
//    ofPopMatrix();
//    
//    ofPushMatrix();
//        ofTranslate(eyeRPos.x, eyeRPos.y);
//        ofScale(scaleFactor/1.3, scaleFactor/1.3);
//        aEyeR.draw(- aEyeR.width, - aEyeR.height);
//    ofPopMatrix();
    
}


void Mask::drawVamp(){
    ofPushMatrix();
        ofTranslate( position.x,   position.y );
        ofScale(scaleFactor*1.2, scaleFactor*1.2);
        ofPushMatrix();
            ofRotate(rotAngle);
            ofTranslate(- aFace.width/2,- aFace.height/1.7);
            aFace.draw(0,0);
        ofPopMatrix();
    ofPopMatrix();
    
    ofPushMatrix();
        ofTranslate(eyeLPos.x, eyeLPos.y);
        ofScale(scaleFactor/2., scaleFactor/2.);
//        aEyeL.draw(- aEyeL.width/2., aEyeR.height);
    ofPopMatrix();
    
    ofPushMatrix();
        ofTranslate(eyeRPos.x, eyeRPos.y);
        ofScale(scaleFactor/2., scaleFactor/2.);
//        aEyeR.draw(- aEyeR.width/1.5, aEyeL.height);
    ofPopMatrix();
}


