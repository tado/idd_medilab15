#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    mesh.setMode(OF_PRIMITIVE_POINTS);
    pressed = false;
    for (int i = 0; i < num; i++) {
        particles[i].position = ofVec3f(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofRandom(-ofGetWidth(), ofGetWidth()));
        particles[i].height = ofGetWidth();
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    mesh.clear();
    for (int i = 0; i < num; i++) {
        particles[i].resetForce();
        if (pressed) {
            particles[i].addAttractionForce(mouseX, mouseY, 0, ofGetWidth() * 1.5, 1.0);
        }
        particles[i].update();
        particles[i].throughOfWalls();
        mesh.addVertex(ofVec3f(particles[i].position.x, particles[i].position.y, particles[i].position.z));
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(210);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    static GLfloat distance[] = { 0.0, 0.0, 1.0 };
    glPointParameterfv(GL_POINT_DISTANCE_ATTENUATION, distance);
    glPointSize(4000);
    mesh.draw();
    ofDisableBlendMode();
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
    pressed = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    pressed = false;
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
