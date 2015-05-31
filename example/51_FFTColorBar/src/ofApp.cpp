#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0);
    // FFTのサンプル数(2の累乗)を指定して初期化
    fft.setup(pow(2.0, 8.0));
}

//--------------------------------------------------------------
void ofApp::update(){
    fft.update(); // FFT更新
}

//--------------------------------------------------------------
void ofApp::draw(){
    // float型の配列にFFT結果を格納
    vector<float> buffer;
    buffer = fft.getBins();

    // グラフに描画
    ofSetLineWidth(ofGetWidth() / float(buffer.size()) / 2.0 - 0.5);
    for (int i = 0; i < buffer.size(); i++) {
        // 色を設定
        float hue = ofMap(i, 0, buffer.size(), 0, 160);
        ofColor col;
        col.setHsb(hue, 255, 255);
        ofSetColor(col);
        // 右
        float rx = ofMap(i, 0, buffer.size(), ofGetWidth() / 2.0, ofGetWidth());
        float y = ofMap(buffer[i], 0, 1, ofGetHeight(), 0);
        ofLine(rx, ofGetHeight(), rx, y);
        // 左
        float lx = ofMap(i, 0, buffer.size(), ofGetWidth() / 2.0, 0);
        ofLine(lx, ofGetHeight(), lx, y);
    }
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
