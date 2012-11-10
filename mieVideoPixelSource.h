//
//  mieVideoPixelSource.h
//  movingIntoEnlightenment
//
//  Created by 久保 裕也 on 2012/11/11.
//
//

#pragma once
#include "mieVideo.h"
#include "ofxOpenCv.h"

class mieVideoPixelSource : public mieVideo{
public:
    mieVideoPixelSource();
    mieVideoPixelSource(const int cameraIndex, const float _ox, const float _oy, const int width, const int height,
                   ofVideoGrabber * vidGrabber);
    
    void setup();
    void update();
    void draw();
    
protected:
    virtual void drawPixels(unsigned char * pixels) = 0;
    
};
