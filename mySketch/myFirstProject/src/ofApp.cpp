#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(60);
    ofSetCircleResolution(64);
    position.x = ofRandom(ofGetWidth());
    position.y = ofRandom(ofGetHeight());
    velocity.x = ofRandom(-5, 5);
    velocity.y = ofRandom(-5, 5);
}

//--------------------------------------------------------------
void ofApp::update(){
    position += velocity;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    ofCircle(position.x, position.y, 20);
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
