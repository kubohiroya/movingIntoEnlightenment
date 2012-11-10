#include "mieApp.h"

//--------------------------------------------------------------
mieApp::mieApp(){
};


mieApp::mieApp(const int _numCameras, const screenConfig __screenConfig, const int _screenWidth, const int _screenHeight){
    
    numCameras = _numCameras;
    _screenConfig = __screenConfig;
    
    int camWidth = _screenWidth / numCameras;
    int camHeight = _screenHeight;
  
    for(int cameraIndex = 0; cameraIndex < numCameras; cameraIndex++){
        ofVideoGrabber * thisVidGrabber = new ofVideoGrabber();
        thisVidGrabber->setDeviceID(cameraIndex);
        thisVidGrabber->initGrabber(camWidth, camHeight);
        vidGrabberArray[cameraIndex] = thisVidGrabber;
    }

    int videoIndex = 0;
    for(int y = 0; y < _screenConfig.rows; y++){
        for(int x = 0; x < _screenConfig.cols; x++){
            int cameraIndex = _screenConfig.cameraIndexArray[videoIndex];
            if(cameraIndex != -1 && cameraIndex < numCameras){
                ofVideoGrabber * vidGrabber = vidGrabberArray[cameraIndex];
                mieVideoArray[videoIndex] = mieVideoFactory::create(cameraIndex, videoIndex,
                                                          x * _screenWidth / _screenConfig.cols,
                                                          y * _screenHeight / _screenConfig.rows,
                                                          _screenWidth / _screenConfig.cols,
                                                          _screenHeight / _screenConfig.rows,
                                                          vidGrabber);
            }else{
                mieVideoArray[videoIndex] = 0;
            }
            videoIndex++;
        }
    }

};

//--------------------------------------------------------------
mieApp::~mieApp(){
    for(int cameraIndex = 0; cameraIndex < numCameras; cameraIndex++){
        vidGrabberArray[cameraIndex]->close();
    }
}

//--------------------------------------------------------------
void mieApp::setup(){
    ofBackground(0,0,0);
    ofEnableSmoothing();
    
    for(int i = _screenConfig.numVideos() - 1; 0 <= i; i--){
        if(mieVideoArray[i] == 0){
            continue;
        }
        mieVideoArray[i]->setup();
    }
}

//--------------------------------------------------------------
void mieApp::grabFrames(){
        for(int cameraIndex = 0; cameraIndex < numCameras; cameraIndex++){
            vidGrabberArray[cameraIndex]->grabFrame();
        }
}

void mieApp::updateVideos(){
    for(int i = _screenConfig.numVideos() - 1; 0 <= i; i--){
        if(mieVideoArray[i] == 0){
            continue;
        }
        mieVideoArray[i]->update();
    }
}

void mieApp::update(){

    grabFrames();
    
    updateVideos();
}

//--------------------------------------------------------------
void mieApp::draw(){
    ofSetHexColor(0xffffff);

    for(int i = _screenConfig.numVideos() - 1; 0 <= i; i--){
        if(mieVideoArray[i] == 0){
            continue;
        }
        mieVideoArray[i]->draw();
    }
}

//--------------------------------------------------------------
void mieApp::keyPressed(int key){

}

//--------------------------------------------------------------
void mieApp::keyReleased(int key){
    if(key == 's' || key == 'S'){
        /*
        for(int i = _screenConfig.numVideos() - 1; 0 <= i; i--){
            if(mieVideoArray[i] == 0){
               continue;
            }
            mieVideoArray[i]->videoSettings();
        }
         */
    }

    
}

//--------------------------------------------------------------
void mieApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void mieApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void mieApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void mieApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void mieApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void mieApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void mieApp::dragEvent(ofDragInfo dragInfo){ 

}