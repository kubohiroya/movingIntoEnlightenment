#これは何？

openFrameworks v0072上のデモアプリケーションです。
openFrameworksで適当な空プロジェクトを作成して、srcフォルダの中身をコレで入れ替えれば動作するものと思われます。

# どうやって設定・拡張するの？

各種の動作設定は、 main.cpp 内でいずれかのコメントアウト内容の編集などで行います。

また、新しいビデオ効果を加えたい場合には、その実現のしくみをmieVideoクラスのサブクラスとして実装し、
mieVideoFactory::create関数の中でそのクラスのインスタンスを必要に応じて返すことで実現できます。

# 新しいビデオ効果を加える際の手順

mieVideoクラスのサブクラスを作る場合には、クラス名がmieVideoで始まるクラスを参考にすること。
仮に、Hogeというビデオ効果を加えたいとするならば、次のような手順となる。

## mieVideoHoge.hを次のような内容で作成

    #pragma once
    #include "mieVideo.h"

    class mieVideoHoge : public mieVideo{
    public:
        mieVideoHoge();
        mieVideoHoge(int cameraIndex, float _ox, float _oy, int width, int height, ofVideoGrabber * vidGrabber);

        void drawPixels(unsigned char * pixels);
    };

## mieVideoHoge.cppを次のような内容で作成

    #include "mieVideoHoge.h"

    mieVideoHoge::mieVideoHoge() : mieVideo::mieVideo(){};

    mieVideoHoge::mieVideoHoge(int cameraIndex, float _ox, float _oy, int width, int height, ofVideoGrabber *vidGrabber) :
    mieVideo(cameraIndex, _ox, _oy, width, height, vidGrabber){
    };

    void mieVideoHoge::drawPixels(unsigned char * pixels){

        ofPushStyle();
    
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE);

        for(int i = 0; i < width; i+=10){
            for(int j = 0; j < height; j+=10){
                int index = (j * width + i)*3;
                unsigned char r = pixels[index];
                unsigned char g = pixels[index + 1];
                unsigned char b = pixels[index + 2];

                // このへんでいろいろ描画する
                ofSetColor(255,0,0,100);
                ofCircle(ox+i, oy+j, 20.0*(float)r/255.0);
                ofSetColor(0,255,0,100);
                ofCircle(ox+i, oy+j, 20.0*(float)g/255.0);
                ofSetColor(0,0,255,100);
                ofCircle(ox+i, oy+j, 20.0*(float)b/255.0);
            }
        }
    
        ofPopStyle();
    };

## mieVideoHoge.cppのdrawPixels関数内で、ビデオ効果による表示内容の描画をするコードを書く。


