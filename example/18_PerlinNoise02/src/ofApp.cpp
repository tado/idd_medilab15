#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    ofSetLineWidth(2);
    
    width = ofGetWidth();
    height = ofGetHeight();
    
    myImage.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_GRAYSCALE);
    pixels = myImage.getPixels();
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            float scaleX = mouseX / 500.0;
            float scaleY = mouseY / 500.0;
            float noiseX = ofMap(i, 0, width, 0, scaleX);
            float noiseY = ofMap(j, 0, width, 0, scaleY);
            int noiseVal = ofNoise(noiseX, noiseY) * 255;
            pixels[j * width + i] = noiseVal;
        }
    }
    myImage.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(127);
    myImage.draw(0, 0);
    
    int skip = 20;
    ofSetColor(0, 127, 255);
    for (int j = 0; j < height; j += skip) {
        for (int i = 0; i < width; i += skip) {
            int val = pixels[j * width + i];
            int rot = ofMap(val, 0, 255, 0, 360);
            ofPushMatrix();
            ofTranslate(i, j);
            ofRotateZ(rot);
            ofLine(0, -skip / 2.0, 0, skip / 2.0);
            ofPopMatrix();
        }
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
