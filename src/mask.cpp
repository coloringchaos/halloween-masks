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

void Mask::setup(ofImage face, ofImage eye){
    mFace = face;
    mEyeR = eye;
    mEyeL = eye;
}

void Mask::update(){
    
    float dist = ofDist(left.x, left.y, right.x, right.y);
    scaleFactor = dist/mFace.width;
    rotAngle = acos((right.x-left.x)/dist)*360./ TWO_PI;
    if (left.y > right.y) rotAngle *=-1.;

}

void Mask::draw(){
    ofPushMatrix();
        ofTranslate( position.x,   position.y );
        ofScale(scaleFactor, scaleFactor);
        ofPushMatrix();
            ofRotate(rotAngle);
            ofTranslate(- mFace.width/2,- mFace.height/2);
            mFace.draw(0,0);
        ofPopMatrix();
    ofPopMatrix();
    
    //eye drawing
    ofPushMatrix();
        ofTranslate(eyeLPos.x, eyeLPos.y+mEyeL.height/2.);
        ofScale(scaleFactor, leftEyeOpenScale/4.);
        mEyeL.draw(- mEyeL.width/2., mEyeL.height/2);
    ofPopMatrix();
    
    ofPushMatrix();
        ofTranslate(eyeRPos.x, eyeRPos.y+mEyeR.height/2.);
        ofScale(scaleFactor, rightEyeOpenScale/4.);
        mEyeR.draw(- mEyeR.width/2., mEyeR.height/2.);
    ofPopMatrix();
}