//
//  mieVideoOpenCV.h
//  movingIntoEnlightenment
//
//  Created by 久保 裕也 on 2012/11/11.
//
//

#pragma once
#include "mieVideo.h"
#include "ofxOpenCv.h"

class mieVideoOpenCV : public mieVideo{
public:
    mieVideoOpenCV();
    mieVideoOpenCV(const int cameraIndex, const float _ox, const float _oy, const int width, const int height,
                         ofVideoGrabber * vidGrabber);
    
    void setup();
    void update();
    void draw();

    ofxCvColorImage colorImg;
};
