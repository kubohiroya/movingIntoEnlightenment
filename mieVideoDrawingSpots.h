//
//  mieVideoDrawingSpots.h
//  movingIntoEnlightenment
//
//  Created by 久保 裕也 on 2012/11/06.
//
//

#pragma once
#include "mieVideo.h"

class mieVideoDrawingSpots : public mieVideo{
public:
    mieVideoDrawingSpots();
    mieVideoDrawingSpots(int cameraIndex, float _ox, float _oy, int width, int height, ofVideoGrabber * vidGrabber);

    void drawPixels(unsigned char * pixels);
};
