//
//  mieVideoPassThrough.cpp
//  movingIntoEnlightenment
//
//  Created by 久保 裕也 on 2012/11/07.
//
//

#include "mieVideoPassThrough.h"

mieVideoPassThrough::mieVideoPassThrough() : mieVideo::mieVideo(){};

mieVideoPassThrough::mieVideoPassThrough(const int cameraIndex, const float ox, const float oy, const int width, const int height, ofVideoGrabber *_vidGrabber) :
mieVideo::mieVideo(cameraIndex, ox, oy, width, height, _vidGrabber){
};

void mieVideoPassThrough::setup(){};

void mieVideoPassThrough::update(){};

void mieVideoPassThrough::draw(){
    vidGrabber->draw(ox, oy, width, height);
};

