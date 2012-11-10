//
//  mieVideoFactory.h
//  movingIntoEnlightenment
//
//  Created by 久保 裕也 on 2012/11/10.
//
//

//--------------------------------------------------------------
#pragma once

#include "mieVideo.h"
#include "mieVideo.h"
#include "mieVideo.h"
#include "mieVideoDrawingSpots.h"
#include "mieVideoPassThrough.h"
#include "mieVideoHSVConv.h"

class mieVideoFactory{
public:
    static mieVideo* create(int cameraIndex, int videoIndex,
                             float ox, float oy, int width, int height, ofVideoGrabber *ofVideoGrabber);
};

