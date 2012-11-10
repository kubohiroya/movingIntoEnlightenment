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

mieVideo::mieVideo(int _cameraIndex, float _ox, float _oy, int _width, int _height, ofVideoGrabber * _vidGrabber){
    cameraIndex = _cameraIndex;
    width = _width;
    height = _height;
    ox = _ox;
    oy = _oy;
    vidGrabber = _vidGrabber;
};

void mieVideo::update(){
};

void mieVideo::draw(){
    drawPixels(vidGrabber->getPixels());
};

void mieVideo::videoSettings(){
    vidGrabber->videoSettings();
};

