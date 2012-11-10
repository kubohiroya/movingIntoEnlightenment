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
    mieVideoHSVConv(const int cameraIndex, const float ox, const float oy, const int widht, const int height,
                    ofVideoGrabber * ofVideoGrabber);
    
    void drawPixels(unsigned char * pixels);

private:
    static double max(const double a, const double b, const double c);
    static double min(const double a, const double b, const double c);
    static void convRGBtoHSV(const unsigned char r, const unsigned char g, const unsigned char b, double *h, double *s, double *v);
    static void convHSVtoRGB(const double h, const double s, const double v,  unsigned char *r,  unsigned char *g,  unsigned char *b);
};
