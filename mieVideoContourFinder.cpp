//
//  mieVideoContourFinder.cpp
//  movingIntoEnlightenment
//
//  Created by 久保 裕也 on 2012/11/10.
//
//

#include "mieVideoContourFinder.h"

mieVideoContourFinder::mieVideoContourFinder() : mieVideoOpenCV(){};

mieVideoContourFinder::mieVideoContourFinder(const int cameraIndex, const float _ox, const float _oy, const int width, const int height,
                                           ofVideoGrabber *vidGrabber) :
mieVideoOpenCV(cameraIndex, _ox, _oy, width, height, vidGrabber){
};

void mieVideoContourFinder::setup(){
    mieVideoOpenCV::setup();
    grayImg.allocate(width, height);
    grayBg.allocate(width, height);
    grayDiff.allocate(width, height);
    bLearnBackground = true;
    threshold = 100;
};

void mieVideoContourFinder::update(){
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
        contourFinder.findContours(grayDiff, 30, (width*height)/3, 10, true);
    }
}

void mieVideoContourFinder::draw(){
    ofNoFill();
    ofSetColor(0xffffff);
    //colorImg.draw(ox, oy);
    //grayImage.draw(ox, oy);
    //grayDiff.draw(ox,oy);
    for(int i = 0; i < contourFinder.nBlobs; i++){
        contourFinder.blobs[i].draw(ox, oy);
    }
}

void mieVideoContourFinder::keyPressed(int key){
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
