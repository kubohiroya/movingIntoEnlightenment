//
//  mieVideo.h
//  movingIntoEnlightenment
//
//  Created by 久保 裕也 on 2012/11/06.
//
//

#pragma once

#include "ofMain.h"

class mieVideo {
public:
    
    mieVideo();
    mieVideo(const int cameraIndex, const float ox, const float oy, const int width, const int height,
             ofVideoGrabber * ofVideoGrabber);
    ~mieVideo();
    
    void update();
    void draw();
    void videoSettings();
    
    virtual void drawPixels(unsigned char * pixels) = 0;

    int cameraIndex;
    float ox, oy;
    int width;
    int height;
    
    ofVideoGrabber *vidGrabber;
    
private:

};
