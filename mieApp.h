#pragma once

#include "ofMain.h"
#include "mieVideo.h"
#include "mieVideoFactory.h"
#include "screenConfig.h"

#define MAX_NUM_CAMERAS 3
#define MAX_NUM_VIDEOS 4

class mieApp : public ofBaseApp{
	public:
        mieApp();
        mieApp(int numCameras, screenConfig screenConfig, int screenWidth, int screenHeight);
        ~mieApp();

		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    int numCameras;
    ofVideoGrabber *vidGrabberArray[MAX_NUM_CAMERAS];
    mieVideo* mieVideoArray[MAX_NUM_VIDEOS];
    
    
    private:
    
        screenConfig _screenConfig;

};
