//
//  mask.cpp
//  ofApp
//
//  Created by Arielle Hein on 10/25/15.
//
//

#include "mask.h"

Mask::Mask(){
    opacity = 255;
    fadeOutSpeed = 10;
    fadeInSpeed = 20;
}

void Mask::setup(ofImage face, ofImage eyeR, ofImage eyeL, ofImage mouth){
    aFace = face;
    aEyeR = eyeR;
    aEyeL = eyeL;
    aMouth = mouth;
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
        default:
            break;
    }
    
    ofPopStyle();
    
}

void Mask::checkPresence() {
    if (left.x == 0) {
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
        ofScale(scaleFactor/1.5, rightEyeOpenScale/9.);
        aEyeL.draw(- aEyeL.width/2., - aEyeL.height/2);
    ofPopMatrix();
    
    ofPushMatrix();
        ofTranslate(eyeRPos.x, eyeRPos.y+aEyeR.height/2.);
        ofScale(scaleFactor/1.5, rightEyeOpenScale/9.);
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
        ofScale(scaleFactor, leftEyeOpenScale/4.);
        aEyeL.draw(- aEyeL.width/2., 0);
    ofPopMatrix();
    
    ofPushMatrix();
        ofTranslate(eyeRPos.x, eyeRPos.y-aEyeR.height/2);
        ofScale(scaleFactor, rightEyeOpenScale/4.);
        aEyeR.draw(- aEyeR.width/2., 0);
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
        aEyeL.draw(- aEyeL.width/2., aEyeR.height*2.5);
    ofPopMatrix();
    
    ofPushMatrix();
        ofTranslate(eyeRPos.x, eyeRPos.y-aEyeR.height/2);
        ofScale(scaleFactor/1.5, scaleFactor/1.5);
        aEyeR.draw(- aEyeR.width/2., aEyeR.height*2.5);
    ofPopMatrix();
}


