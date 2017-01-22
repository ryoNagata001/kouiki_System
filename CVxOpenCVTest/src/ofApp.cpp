#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    cam.initGrabber(ofGetWidth(), ofGetHeight());
    contourFinder.setMinAreaRadius(20);
    contourFinder.setMaxAreaRadius(200);
    background.setLearningTime(900);
    background.setThresholdValue(20);
    ofSetFrameRate(setBPM/60);
    
    resetBackgroundButton.addListener(this, &ofApp::resetBackgroundPressed);//関数のアドレスを渡している
    gui.setup();
    gui.add(bgThresh.setup("Background thresh", 50, 0, 100));
    gui.add(contourThresh.setup("contour finder thresh", 127, 0, 255));
    gui.add(resetBackgroundButton.setup("reset background"));
    gui.add(setBPM.setup("set BPM", 100, 0, 240));
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    if(cam.isFrameNew()){
        background.setThresholdValue(bgThresh);//閾値を設定、どの程度異なっていたら描画するか
        background.update(cam, thresholded);//camのインプットを設定した閾値で二値化
        thresholded.update();//画像を更新
        
        contourFinder.setThreshold(contourThresh);//輪郭の閾値を設定
        contourFinder.findContours(thresholded);//画像から輪郭を抽出
    }
    
    if (k < setBPM/60 * 8){
        k += 1;
    }else{
        k = 0;
    }
    if (k == 0){
        resetBackgroundPressed();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetLineWidth(2);
    ofSetColor(255);
    thresholded.draw(0,0);//imageを描画
    
    ofSetLineWidth(1);
    ofSetColor(255, 0, 0);
    contourFinder.draw();//輪郭を描画
    
    gui.draw();//GUIを描画
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void ofApp::resetBackgroundPressed(){
        background.reset();
}


