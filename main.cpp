#include "screen.h"
#include "screenConfig.h"
#include "mieApp.h"
#include "mieVideoFactory.h"

#include "mieVideoDrawingSpots.h"
#include "mieVideoPassThrough.h"
#include "mieVideoHSVConv.h"
#include "mieVideoOpenCV.h"
#include "mieVideoContourFinder.h"
#include "mieVideoSightSteeler.h"

#include "ofAppGlutWindow.h"

//--------------------------------------------------------------
// これらの配列により、スクリーンを升目状に区分するビデオ領域それぞれが、どのカメラと接続されるのかを指定する。
// これらの配列の0番目の要素は、スクリーンを升目上に区分するビデオ領域のうち、左上の端を指定する。
// 配列の要素としては、USBカメラの通し番号(0からの通し番号)を代入する。
// 配列の要素は重複した値を取ることができ、そうして重複した箇所には同じカメラが接続されることになる。
int SINGLE_CAMERA_ID_ARRAY[] = {0};
int DOUBLE_CAMERA_ID_ARRAY[] = {0,1};
int TRIPLE_CAMERA_ID_ARRAY[] = {0,2,1};
int QUAD_CAMERA_ID_ARRAY[] = {0,0,0,0};

//--------------------------------------------------------------

int SINGLE_CAMERA = 1;// do not change
int DOUBLE_CAMERA = 2;// do not change
int TRIPLE_CAMERA = 3;// do not change

screenConfig SINGLE_VIDEO_CONFIG = *new screenConfig(1,1, SINGLE_CAMERA_ID_ARRAY);// do not change
screenConfig SIDE_BY_SIDE_VIDEO_CONFIG = *new screenConfig(2,1, TRIPLE_CAMERA_ID_ARRAY);// do not change
screenConfig TRIPLE_VIDEO_CONFIG = *new screenConfig(3,1, TRIPLE_CAMERA_ID_ARRAY);// do not change
screenConfig QUAD_VIDEO_CONFIG = *new screenConfig(2,2, QUAD_CAMERA_ID_ARRAY);// do not change

screen HMD_FULLSCREEN = *new screen(1280,720, OF_FULLSCREEN);// do not change
screen HMD_WINDOW = *new screen(1280,720, OF_WINDOW);// do not change

screen MBA_FULLSCREEN = *new screen(1400,900, OF_FULLSCREEN);// do not change
screen MBA_WINDOW = *new screen(1400,900, OF_WINDOW);// do not change

screen DEBUG_WINDOW = *new screen(640,480, OF_WINDOW);// do not change


//--------------------------------------------------------------
// ビデオ領域を加工して表示するアルゴリズムのうち、どこにどれを使うかの選択内容を指定する関数。
// 引数として、カメラの通し番号、ビデオ領域の通し番号、ビデオ領域の表示位置のx/y/width/height、動画取得用オブジェクトを与える。
// 返り値として、抽象クラスmieVideoの実装クラスいずれかのインスタンスまたは0を返す。0は「何も表示しない」の意味になる。
mieVideo* mieVideoFactory::create(const int cameraIndex, const int videoIndex,
                                  const float ox, const float oy, const int width, const int height,
                                  ofVideoGrabber *ofVideoGrabber){
    switch(videoIndex){
        case 0: //0番目のビデオ領域
            return new mieVideoPassThrough(cameraIndex, ox, oy, width, height, ofVideoGrabber);
            //return new mieVideoDrawingSpots(cameraIndex, ox, oy, width, height, ofVideoGrabber);
            //return new mieVideoHSVConv(cameraIndex, ox, oy, width, height, ofVideoGrabber);
        case 1: //1番目のビデオ領域
            return new mieVideoPassThrough(cameraIndex, ox, oy, width, height, ofVideoGrabber);
            //return new mieVideoDrawingSpots(cameraIndex, ox, oy, width, height, ofVideoGrabber);
            //
        case 2: //2番目のビデオ領域
            //return new mieVideoSightSteeler(cameraIndex, ox, oy, width, height, ofVideoGrabber);
            return new mieVideoPassThrough(cameraIndex, ox, oy, width, height, ofVideoGrabber);
        case 3: //3番目のビデオ領域
            return new mieVideoContourFinder(cameraIndex, ox, oy, width, height, ofVideoGrabber);
    }
}

screen createScreen(){
    // return HMD_WINDOW;     // HeadMountedDisplayサイズでのウィンドウで表示
    return HMD_FULLSCREEN; // HeadMountedDisplayサイズでのフルスクリーン表示
    // return MBA_WINDOW;     // MacBookAirの画面サイズでのウィンドウ表示
    // return MBA_FULLSCREEN; // MacBookAirの画面サイズでのフルスクリーン表示
    // return DEBUG_WINDOW;
}

mieApp * createMieApp(const screen screen){
    // 内蔵カメラx1　→ ビデオ領域1つ
    //return new mieApp(SINGLE_CAMERA, SINGLE_VIDEO_CONFIG, screen.width, screen.height);
    
    // 内蔵カメラx1+外部カメラx2 → そのうち外部カメラx2を用いて、ビデオ領域2つのサイドバイサイドでの「立体視」
    return new mieApp(TRIPLE_CAMERA, SIDE_BY_SIDE_VIDEO_CONFIG, screen.width, screen.height);
    
    // 内蔵カメラx1 → ビデオ領域4つで動作内容を比較
    // return new mieApp(SINGLE_CAMERA, QUAD_VIDEO_CONFIG, screen.width, screen.height);
}

//--------------------------------------------------------------
int main(){
	ofAppGlutWindow window; // do not change
    screen screen = createScreen();
    ofSetupOpenGL(&window, screen.width, screen.height, screen.mode); // do not change
    ofRunApp(createMieApp(screen)); // start the app
}
