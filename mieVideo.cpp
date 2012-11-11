//
//  mieVideo.cpp
//  movingIntoEnlightenment
//
//  Created by 久保 裕也 on 2012/11/06.
//
//

#include "mieVideo.h"

mieVideo::mieVideo(){
    //vidGrabber.setVerbose(true);
};

mieVideo::~mieVideo(){
};

mieVideo::mieVideo(const int _cameraIndex, const float _ox, const float _oy, const int _width, const int _height,
                   ofVideoGrabber * _vidGrabber){
    cameraIndex = _cameraIndex;
    width = _width;
    height = _height;
    ox = _ox;
    oy = _oy;
    vidGrabber = _vidGrabber;
};

void mieVideo::setup(){};
void mieVideo::update(){};
void mieVideo::draw(){};
void mieVideo::keyPressed(int key){};
    
void mieVideo::videoSettings(){
    vidGrabber->videoSettings();
};

