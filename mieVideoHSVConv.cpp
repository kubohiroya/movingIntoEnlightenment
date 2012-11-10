//
//  mieVideoHSV.cpp
//  movingIntoEnlightenment
//
//  Created by 久保 裕也 on 2012/11/10.
//
//

#include "mieVideoHSVConv.h"

mieVideoHSVConv::mieVideoHSVConv(){};
mieVideoHSVConv::mieVideoHSVConv(const int cameraIndex, const float ox, const float oy, const int width, const int height, ofVideoGrabber * ofVideoGrabber):mieVideo(cameraIndex, ox, oy, width, height, ofVideoGrabber){
};

void mieVideoHSVConv::drawPixels(unsigned char * pixels){
    
    ofPushStyle();
    
    for(int i = 0; i < width; i+=10){
        for(int j = 0; j < height; j+=10){
            int index = (j * width + i)*3;
            
            unsigned char r = pixels[index];
            unsigned char g = pixels[index + 1];
            unsigned char b = pixels[index + 2];

            double h = 0.0;
            double s = 0.0;
            double v = 0.0;

            convRGBtoHSV(r, g, b, &h, &s, &v);//rgb値からhsv値を生成
            
            s = 0.0;//彩度値を0.0で上書き(彩度0.0→モノクロ)
            
            convHSVtoRGB(h, s, v, &r, &g, &b);//hsv値からrgb値を生成
            
            ofSetColor(r,g,b,255);
            ofCircle(ox+i, oy+j, 5.0);
            
        }
    }
    ofPopStyle();
}



double mieVideoHSVConv::min(const double a, const double b, const double c){
    if(a <= b && a <= c){
        return	a;
    }
    if(b <= a && b <= c){
        return	b;
    }
    return	c;
}

double mieVideoHSVConv::max(const double a, const double b, const double c){
    if(b <= a && c <= a){
        return	a;
    }
    if(a <= b && c <= b){
        return	b;
    }
    return	c;
}


void mieVideoHSVConv::convRGBtoHSV(const unsigned char r, const unsigned char g, const unsigned char b, double* dH, double* dS, double* dV){
    double	dR;
    double	dG;
    double	dB;
    double	dMax;
    double	dMin;
    double	dDiff;
    
    //RGB->HSV変換時のR,G,Bは 0.0～1.0
    dR = r	/ 255.0;
    dG = g	/ 255.0;
    dB = b	/ 255.0;
    
    dMax = max(dR,dG,dB);
    dMin = min(dR,dG,dB);
    
    if(dMax == 0.0){
        (*dS) = 0.0;
        (*dV) = 0.0;
        return;
    }
    
    dDiff = dMax - dMin;
    (*dV) = dMax;
    (*dS) = dDiff / dMax;
    //dS = dMax - dMin;			//円錐色空間時のS
    
    if(dR == dMax){
        (*dH) = 60 * (dG - dB) / dDiff;
    }else if(dG == dMax){
        (*dH) = 60 * (dB - dR) / dDiff + 120;
    }else{
        (*dH) = 60 * (dR - dG) / dDiff + 240;
    }
    //上の計算ではdHが負になることがある
    if((*dH) < 0){
        (*dH) = (*dH) + 360;
    }
    return;
}



void mieVideoHSVConv::convHSVtoRGB(const double dH, const double dS,double dV, unsigned char *r, unsigned char *g, unsigned char *b){
    if(dS == 0.0){
        (*r)	= (unsigned char)(dV * 255);
        (*g)	= (*r);
        (*b)	= (*r);
        return;
    }
    
    double	f;
    double	p;
    double	q;
    double	t;
    int		nHi;
    
    nHi = (int)(dH / 60) % 6;
    if(nHi < 0){
        nHi *= -1;		//dHが負のときの対策
    }
    f = dH / 60 - nHi;
    p = dV * (1 - dS);
    q = dV * (1 - f * dS);
    t = dV * (1 - (1 - f) * dS);
    
    //計算結果のR,G,Bは0.0～1.0なので255倍
    dV = dV * 255;
    p = p * 255;
    q = q * 255;
    t = t * 255;
    
    if(dV > 255){
        dV = 255;
    }
    if(t > 255){
        t = 255;
    }
    if(p > 255){
        p = 255;
    }
    if(q > 255){
        q = 255;
    }
    
    if(nHi == 0){
        (*r)	= (unsigned char)dV;
        (*g)	= (unsigned char)t;
        (*b)	= (unsigned char)p;
        return;
    }
    if(nHi == 1){
        (*r)	= (unsigned char)q;
        (*g)	= (unsigned char)dV;
        (*b)	= (unsigned char)p;
        return;
    }
    if(nHi == 2){
        (*r)	= (unsigned char)p;
        (*g)	= (unsigned char)dV;
        (*b)   = (unsigned char)t;
        return;
    }
    if(nHi == 3){
        (*r)	= (unsigned char)p;
        (*g)	= (unsigned char)q;
        (*b)   = (unsigned char)dV;
        return;
    }
    if(nHi == 4){
        (*r) = (unsigned char)t;
        (*g) = (unsigned char)p;
        (*b) = (unsigned char)dV;
        return;
    }
    
    //if(nHi == 5)
    //{
    (*r)	= (unsigned char)dV;
    (*g)	= (unsigned char)p;
    (*b)	= (unsigned char)q;
    return;
    //}
}
