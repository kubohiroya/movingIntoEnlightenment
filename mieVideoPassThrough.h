//
//  mieVideoSimple.h
//  movingIntoEnlightenment
//
//  Created by 久保 裕也 on 2012/11/07.
//
//

#pragma once
#include "mieVideo.h"

class mieVideoPassThrough : public mieVideo{
public:
    mieVideoPassThrough();
    mieVideoPassThrough(int cameraIndex, float ox, float oy, int width, int height, ofVideoGrabber *vidGrabber);

    void drawPixels(unsigned char * pixels);
    
private:

};
