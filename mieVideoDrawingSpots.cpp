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
    
    const int step = 4;
    const int size = 2;

    for(int i = 0; i < width; i+=step){
        for(int j = 0; j < height; j+=step){
            int index = (j * width + i)*3;
            unsigned char r = pixels[index];
            unsigned char g = pixels[index + 1];
            unsigned char b = pixels[index + 2];
            ofSetColor(255,0,0,100);
            ofCircle(ox+i, oy+j, size*(float)r/255.0);
            ofSetColor(0,255,0,100);
            ofCircle(ox+i, oy+j, size*(float)g/255.0);
            ofSetColor(0,0,255,100);
            ofCircle(ox+i, oy+j, size*(float)b/255.0);
        }
    }
    
    ofPopStyle();
};

