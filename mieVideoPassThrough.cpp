//
//  mieVideoPassThrough.cpp
//  movingIntoEnlightenment
//
//  Created by 久保 裕也 on 2012/11/07.
//
//

#include "mieVideoPassThrough.h"

mieVideoPassThrough::mieVideoPassThrough() : mieVideo::mieVideo(){};

mieVideoPassThrough::mieVideoPassThrough(int cameraIndex, float ox, float oy, int width, int height, ofVideoGrabber *_vidGrabber) :
mieVideo(cameraIndex, ox, oy, width, height, _vidGrabber){
};

void mieVideoPassThrough::drawPixels(unsigned char * pixels){
    vidGrabber->draw(ox, oy, width, height);
};

