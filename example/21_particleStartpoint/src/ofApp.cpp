#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){
    particle.update(); // 等速運動の更新
}

//--------------------------------------------------------------
void ofApp::draw(){
    particle.draw(); // 描画
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
// クリックした場所から、等速度運動を開始
void ofApp::mouseReleased(int x, int y, int button){
    particle.position = ofVec2f(x, y); // 初期位置
    particle.velocity = ofVec2f(0, 0); // 速度をリセット
    particle.acceleration = ofVec2f(ofRandom(-10, 10), ofRandom(-10, 10)); // 加速度を設定
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
