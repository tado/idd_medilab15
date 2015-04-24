#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //画面初期設定
    ofSetFrameRate(60);
    ofBackground(0);
    
    //画面を更新せず、加算合成していく
    ofSetBackgroundAuto(false);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    ofSetColor(0, 0, 0, 23);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    
    // 色を設定
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofSetColor(255);
    
    // RandomWalkerを100個表示
    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.clear();
    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < walkerNum; i++) {
            walker[i].update();
            mesh.addVertex(ofVec3f(walker[i].position.x, walker[i].position.y));
            mesh.addColor(ofFloatColor(0.1, 0.1, 0.1));
        }
    }
    mesh.draw();
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
    for (int i = 0; i < walkerNum; i++) {
        walker[i].position.x = x;
        walker[i].position.y = y;
    }
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
