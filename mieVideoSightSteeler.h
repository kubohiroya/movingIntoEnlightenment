//
//  mieVideoSightSteeler.h
//  movingIntoEnlightenment
//
//  Created by 久保 裕也 on 2012/11/12.
//
//
#pragma once
#include "mieVideoOpenCV.h"

class mieVideoSightSteeler : public mieVideoOpenCV{
public:
    mieVideoSightSteeler();
    mieVideoSightSteeler(const int cameraIndex, const float _ox, const float _oy, const int width, const int height,
                          ofVideoGrabber * vidGrabber);
    
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    ofxCvGrayscaleImage grayImg;
    ofxCvGrayscaleImage grayBg;
    ofxCvGrayscaleImage grayDiff;
    
    bool bLearnBackground;
    int threshold;
    
};
