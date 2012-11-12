//
//  mieVideoSightSteeler.cpp
//  movingIntoEnlightenment
//
//  Created by 久保 裕也 on 2012/11/12.
//
//

#include "mieVideoSightSteeler.h"

mieVideoSightSteeler::mieVideoSightSteeler() : mieVideoOpenCV(){};

mieVideoSightSteeler::mieVideoSightSteeler(const int cameraIndex, const float _ox, const float _oy, const int width, const int height,
                                             ofVideoGrabber *vidGrabber) :
mieVideoOpenCV(cameraIndex, _ox, _oy, width, height, vidGrabber){
};

void mieVideoSightSteeler::setup(){
    mieVideoOpenCV::setup();
    grayImg.allocate(width, height);
    grayBg.allocate(width, height);
    grayDiff.allocate(width, height);
    bLearnBackground = true;
    threshold = 100;
};

void mieVideoSightSteeler::update(){
    bool bNewFrame = false;
    bNewFrame = vidGrabber->isFrameNew();
    if(bNewFrame){
        colorImg.setFromPixels(vidGrabber->getPixels(), width, height);
        grayImg = colorImg;
        if(bLearnBackground == true){
            grayBg = grayImg;
            bLearnBackground = false;
        }
        grayDiff.absDiff(grayBg, grayImg);
        grayDiff.threshold(threshold);

    }
}

void mieVideoSightSteeler::draw(){
    ofNoFill();
    ofSetColor(0xffffff);
    //colorImg.draw(ox, oy);
    //grayImage.draw(ox, oy);
    //grayDiff.draw(ox,oy);
    

}

void mieVideoSightSteeler::keyPressed(int key){
    switch(key){
        case ' ':
            bLearnBackground = true;
            break;
        case '+':
            threshold++;
            if(255 < threshold){
                threshold = 255;
            }
            break;
        case '-':
            threshold--;
            if(threshold < 0){
                threshold = 0;
            }
            break;
    }
}

