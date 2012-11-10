//
//  screenConfig.h
//  movingIntoEnlightenment
//
//  Created by 久保 裕也 on 2012/11/10.
//
//

#pragma once

#include "ofMain.h"


class screenConfig{
    
public:
    screenConfig();
    screenConfig(int cols, int rows, int* cameraIndexArray);
        
    int numVideos();
    
    int cols, rows;
    int *cameraIndexArray;
};