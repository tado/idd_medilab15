#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    mesh.setMode(OF_PRIMITIVE_POINTS);
    glPointSize(3.0);
}

//--------------------------------------------------------------
void ofApp::update(){
    mesh.clear();
    for (int i = 0; i < particles.size(); i++) {
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
    // キー入力で全消去
    particles.clear();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    // 一度に100個ずつ生成
    for (int i = 0; i < 100; i++) {
        // まずテンポラリーなオブジェクトを生成して初期設定する
        ParticleVec2 p;
        p.position = ofVec2f(x, y);
        float length = ofRandom(2.0);
        float angle = ofRandom(2.0 * PI);
        ofVec2f velocity = ofVec2f(length * cos(angle), length * sin(angle));
        p.velocity = velocity;
        // 生成したオブジェクトを可変長配列の末尾に追加
        particles.push_back(p);
    }
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
