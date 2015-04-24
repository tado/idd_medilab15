#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    
    width = ofGetWidth();
    height = ofGetHeight();
    
    myImage.allocate(ofGetWidth(), ofGetHeight(), OF_IMAGE_GRAYSCALE);
    pixels = myImage.getPixels();
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            float scaleX = mouseX / 100.0;
            float scaleY = mouseY / 100.0;
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
    myImage.draw(0, 0);
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
