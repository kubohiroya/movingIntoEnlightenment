//
//  mieVideoHSV.h
//  movingIntoEnlightenment
//
//  Created by 久保 裕也 on 2012/11/10.
//
//

#pragma once
#include "mieVideo.h"

class mieVideoHSVConv : public mieVideo{
public:
    mieVideoHSVConv();
    mieVideoHSVConv(int cameraIndex, float ox, float oy, int widht, int height, ofVideoGrabber * ofVideoGrabber);
    
    void drawPixels(unsigned char * pixels);

private:
    static double max(double a, double b, double c);
    static double min(double a, double b, double c);
    static void convRGBtoHSV(unsigned char r, unsigned char g, unsigned char b, double *h, double *s, double *v);
    static void convHSVtoRGB(double h, double s, double v,  unsigned char *r,  unsigned char *g,  unsigned char *b);
};
