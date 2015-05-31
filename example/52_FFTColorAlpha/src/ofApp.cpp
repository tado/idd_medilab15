#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(0);
    // FFTのサンプル数(2の累乗)を指定して初期化
    fft.setup(pow(2.0, 10.0));
    // GUI
    gui.setup();
    gui.add(saturation.setup("Saturation", 127, 0, 255));
    gui.loadFromFile("settings.xml");
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
    ofSetLineWidth(ofGetWidth() / float(buffer.size()) / 2.0);
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    for (int i = 0; i < buffer.size(); i++) {
        // 色を設定
        float hue = ofMap(i, 0, buffer.size(), 0, 160);
        float br = ofMap(buffer[i], 0, 1, 0, 255);
        ofColor col;
        col.setHsb(hue, saturation, br);
        ofSetColor(col);
        // 右
        float rx = ofMap(i, 0, buffer.size(), 0, ofGetWidth() / 2.0);
        ofLine(rx, -ofGetWidth() / 2.0, rx, ofGetWidth() / 2.0);
        // 左
        float lx = ofMap(i, 0, buffer.size(), 0, -ofGetWidth() / 2.0);
        ofLine(lx, -ofGetWidth() / 2.0, lx, ofGetWidth() / 2.0);
    }
    ofPopMatrix();
    gui.draw(); // GUI描画
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
