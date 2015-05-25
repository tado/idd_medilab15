#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面設定
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(31);
    // 照明とカメラ
    ofEnableLighting();
    light.setPosition(200, 300, 50);
    light.enable();
    cam.setOrientation(ofPoint(-20, 0, 0));
    // Leap Motion開始
    leap.open();
}

//--------------------------------------------------------------
void ofApp::update(){
    // 検出された手の数だけ、ofxLeapMotionSimpleHandのvector配列に追加
    simpleHands = leap.getSimpleHands();
    
    // フレーム更新して、手が検出されたら
    if( leap.isFrameNew() && simpleHands.size() ){
        // 画面の大きさにあわせて、スケールをマッピング
        leap.setMappingX(-230, 230, -ofGetWidth()/2, ofGetWidth()/2);
        leap.setMappingY(90, 490, -ofGetHeight()/2, ofGetHeight()/2);
        leap.setMappingZ(-150, 150, -200, 200);
    }
    
    // ofxLeapMotionに現在のフレームは古くなったことを通知
    leap.markFrameAsOld();
}

//--------------------------------------------------------------
void ofApp::draw(){
    // 奥の物体を隠す
    ofEnableDepthTest();
    // 検出された数だけ、手を描画
    cam.begin();
    for(int i = 0; i < simpleHands.size(); i++){
        simpleHands[i].debugDraw();
    }
    cam.end();
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
