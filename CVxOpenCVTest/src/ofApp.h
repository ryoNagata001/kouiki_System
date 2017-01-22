#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void resetBackgroundPressed();
    
    ofVideoGrabber cam;
    ofxCv::ContourFinder contourFinder;
    ofxCv::RunningBackground background;
    ofImage thresholded;
    
    ofxPanel gui;
    ofxFloatSlider bgThresh;
    ofxFloatSlider contourThresh;
    ofxButton resetBackgroundButton;
    ofxFloatSlider setBPM;
    int k;
    bool t;
    ofxButton t1;
};
