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
    mieVideoPassThrough(const int cameraIndex, const float ox, const float oy, const int width, const int height,
                        ofVideoGrabber *vidGrabber);

    void drawPixels(unsigned char * pixels);
    
private:

};
