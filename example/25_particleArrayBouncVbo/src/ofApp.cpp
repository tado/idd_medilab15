#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    for (int i = 0; i < num; i++) {
        float length = ofRandom(20.0);
        float angle = ofRandom(2.0 * PI);
        ofVec2f velocity = ofVec2f(length * cos(angle), length * sin(angle));
        particles[i].velocity = velocity;
    }
    mesh.setMode(OF_PRIMITIVE_POINTS);
    glPointSize(3.0);
}

//--------------------------------------------------------------
void ofApp::update(){
    mesh.clear();
    for (int i = 0; i < num; i++) {
        particles[i].resetForce();
        particles[i].addForce(0, 0.2);
        particles[i].update();
        particles[i].bounceOffWalls();
        mesh.addVertex(ofVec3f(particles[i].position.x, particles[i].position.y));
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
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
    for (int i = 0; i < num; i++) {
        particles[i].position = ofVec2f(x, y);
        float length = ofRandom(20.0);
        float angle = ofRandom(2.0 * PI);
        ofVec2f velocity = ofVec2f(length * cos(angle), length * sin(angle));
        particles[i].velocity = velocity;
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
