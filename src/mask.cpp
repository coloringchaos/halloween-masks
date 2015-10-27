//
//  mask.cpp
//  ofApp
//
//  Created by Arielle Hein on 10/25/15.
//
//

#include "mask.h"

Mask::Mask(){
   
}

void Mask::setup(ofImage face, ofImage eyeR, ofImage eyeL){
    aFace = face;
    aEyeR = eyeR;
    aEyeL = eyeL;
    
}

void Mask::update(){
    float dist = ofDist(left.x, left.y, right.x, right.y);
    scaleFactor = dist/aFace.width;
    rotAngle = acos((right.x-left.x)/dist)*360./ TWO_PI;
    if (left.y > right.y) rotAngle *=-1.;
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


