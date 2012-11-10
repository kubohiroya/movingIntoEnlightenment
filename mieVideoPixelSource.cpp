//
//  mieVideoPixelSource.cpp
//  movingIntoEnlightenment
//
//  Created by 久保 裕也 on 2012/11/11.
//
//

#include "mieVideoPixelSource.h"

mieVideoPixelSource::mieVideoPixelSource() : mieVideo::mieVideo(){};

mieVideoPixelSource::mieVideoPixelSource(const int cameraIndex, const float _ox, const float _oy, const int width, const int height,
                               ofVideoGrabber *vidGrabber) :
mieVideo::mieVideo(cameraIndex, _ox, _oy, width, height, vidGrabber){
};


void mieVideoPixelSource::setup(){
}

void mieVideoPixelSource::update(){
}

void mieVideoPixelSource::draw(){
    drawPixels(vidGrabber->getPixels());
}

