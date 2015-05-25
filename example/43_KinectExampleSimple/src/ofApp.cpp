#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //画面設定
    ofSetFrameRate(60);
    // Kinect初期化
    kinect.init();
    kinect.open();
}

//--------------------------------------------------------------
void ofApp::update(){
    // Kinect状態更新
    kinect.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    // Kinectカメラから撮影した映像
    kinect.draw(0, 0, kinect.width, kinect.height);
    // Kinect深度情報付き映像
    kinect.drawDepth(kinect.width, 0, kinect.width, kinect.height);
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
