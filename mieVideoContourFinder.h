//
//  mieVideoContourFinder.h
//  movingIntoEnlightenment
//
//  Created by 久保 裕也 on 2012/11/10.
//
//

#pragma once
#include "mieVideoOpenCV.h"

class mieVideoContourFinder : public mieVideoOpenCV{
public:
    mieVideoContourFinder();
    mieVideoContourFinder(const int cameraIndex, const float _ox, const float _oy, const int width, const int height,
                         ofVideoGrabber * vidGrabber);
    
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    ofxCvGrayscaleImage grayImg;
    ofxCvGrayscaleImage grayBg;
    ofxCvGrayscaleImage grayDiff;
    ofxCvContourFinder contourFinder;
  
    bool bLearnBackground;
    int threshold;
    
    
};
