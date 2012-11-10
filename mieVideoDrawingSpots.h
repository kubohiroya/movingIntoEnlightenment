//
//  mieVideoDrawingSpots.h
//  movingIntoEnlightenment
//
//  Created by 久保 裕也 on 2012/11/06.
//
//

#pragma once
#include "mieVideoPixelSource.h"

class mieVideoDrawingSpots : public mieVideoPixelSource{
public:
    mieVideoDrawingSpots();
    mieVideoDrawingSpots(const int cameraIndex, const float _ox, const float _oy, const int width, const int height,
                         ofVideoGrabber * vidGrabber);

    void drawPixels(unsigned char * pixels);
};
