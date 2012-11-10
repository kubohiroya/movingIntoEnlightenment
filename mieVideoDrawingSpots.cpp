//
//  mieVideoDrawingSpots.cpp
//  movingIntoEnlightenment
//
//  Created by 久保 裕也 on 2012/11/06.
//
//

#include "mieVideoDrawingSpots.h"

mieVideoDrawingSpots::mieVideoDrawingSpots() : mieVideoPixelSource::mieVideoPixelSource(){};

mieVideoDrawingSpots::mieVideoDrawingSpots(const int cameraIndex, const float _ox, const float _oy, const int width, const int height,
                                           ofVideoGrabber *vidGrabber) :
    mieVideoPixelSource(cameraIndex, _ox, _oy, width, height, vidGrabber){
};

void mieVideoDrawingSpots::drawPixels(unsigned char * pixels){

    ofPushStyle();
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);

    for(int i = 0; i < width; i+=10){
        for(int j = 0; j < height; j+=10){
            int index = (j * width + i)*3;
            unsigned char r = pixels[index];
            unsigned char g = pixels[index + 1];
            unsigned char b = pixels[index + 2];
            ofSetColor(255,0,0,100);
            ofCircle(ox+i, oy+j, 20.0*(float)r/255.0);
            ofSetColor(0,255,0,100);
            ofCircle(ox+i, oy+j, 20.0*(float)g/255.0);
            ofSetColor(0,0,255,100);
            ofCircle(ox+i, oy+j, 20.0*(float)b/255.0);
        }
    }
    
    ofPopStyle();
};

