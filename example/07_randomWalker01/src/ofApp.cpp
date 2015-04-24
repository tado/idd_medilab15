#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //画面初期設定
    ofSetFrameRate(60);
    ofBackground(0);
    
    //初期位置を画面の中心に
    pos.x = ofGetWidth()/2;
    pos.y = ofGetHeight()/2;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    //上下左右同じ確率でランダムに移動
    pos.x += ofRandom(-1, 1);
    pos.y += ofRandom(-1, 1);
    
    //円(点)を描く
    ofSetColor(255);
    ofCircle(pos.x, pos.y, 2);
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
