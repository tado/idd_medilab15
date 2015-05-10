#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    mesh.setMode(OF_PRIMITIVE_POINTS); // メッシュの頂点を点で描画
    glPointSize(3.0);
}

//--------------------------------------------------------------
void ofApp::update(){
    mesh.clear(); // メッシュを初期化
    for (int i = 0; i < num; i++) {
        particles[i].addForce(0, 0.2);
        particles[i].update();
        particles[i].bounceOffWalls();
        // 物体の位置をメッシュの頂点に格納
        mesh.addVertex(ofVec3f(particles[i].position.x, particles[i].position.y));
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    mesh.draw(); // メッシュを描画
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
        particles[i].position.set(x, y);
        particles[i].velocity.set(0, 0);
        float length = ofRandom(20.0);
        float angle = ofRandom(2.0 * PI);
        ofVec2f force = ofVec2f(length * cos(angle), length * sin(angle));
        particles[i].addForce(force);
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
