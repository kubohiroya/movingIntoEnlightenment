//
//  mieVideoOpenCV.cpp
//  movingIntoEnlightenment
//
//  Created by 久保 裕也 on 2012/11/11.
//
//

#include "mieVideoOpenCV.h"

mieVideoOpenCV::mieVideoOpenCV() : mieVideo(){};

mieVideoOpenCV::mieVideoOpenCV(const int cameraIndex, const float _ox, const float _oy, const int width, const int height,
                                           ofVideoGrabber *vidGrabber) :
mieVideo(cameraIndex, _ox, _oy, width, height, vidGrabber){
};

void mieVideoOpenCV::setup(){
    colorImg.allocate(width, height);
};

void mieVideoOpenCV::update(){
    
    bool isNewFrame = false;
    
    isNewFrame = vidGrabber->isFrameNew();

    if(isNewFrame){
        colorImg.setFromPixels(vidGrabber->getPixels(), width, height);
    }
}

void mieVideoOpenCV::draw(){
    
    colorImg.draw(ox, oy);
    
};