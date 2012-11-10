//
//  screenConfig.cpp
//  movingIntoEnlightenment
//
//  Created by 久保 裕也 on 2012/11/10.
//
//

#include "screenConfig.h"

screenConfig::screenConfig(){};
screenConfig::screenConfig(int _cols, int _rows, int* _cameraIndexArray){
    cols = _cols;
    rows = _rows;
    cameraIndexArray = _cameraIndexArray;
};


int screenConfig::numVideos(){
    return cols * rows;
}
