#include "ofApp.h"

void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    ofSetBackgroundAuto(false);
    mesh.setMode(OF_PRIMITIVE_POINTS);
    gui.setup();
    gui.add(size.setup("pint size", 2.0, 0.0, 4.0));
    gui.add(pointAlpha.setup("pint alpha", 5, 0, 63));
    gui.add(bgAlpha.setup("background alpha", 5, 0, 31));
}

void ofApp::update(){
}

void ofApp::draw(){
    ofSetColor(0, bgAlpha);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(255, pointAlpha);
    mesh.clear();
    glPointSize(size);
    for (int i = 0; i < NUM; i++) {
        walker[i].draw();
        ofVec3f pos = ofVec3f(walker[i].position.x,
                              walker[i].position.y,
                              0);
        mesh.addVertex(pos);
    }
    mesh.draw();
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    for (int i = 0; i < NUM; i++) {
        walker[i].position.set(ofGetWidth()/2, ofGetHeight()/2);
    }
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
