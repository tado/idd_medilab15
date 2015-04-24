#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);

    width = ofGetWidth();
    height = ofGetHeight();

    myImage.allocate(width, height, OF_IMAGE_GRAYSCALE);
    pixels = myImage.getPixels();

    float scaleX = ofRandom(3.0, 10.0);
    float scaleY = ofRandom(3.0, 10.0);
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            float noiseX = ofMap(i, 0, width, 0, scaleX);
            float noiseY = ofMap(j, 0, width, 0, scaleY);
            int noiseVal = ofNoise(noiseX, noiseY) * 255;
            pixels[j * width + i] = noiseVal;
        }
    }
    myImage.update();

    particleNum = 40000;
    particles = new Particles(particleNum);
    particles->friction = 0.015;

    for (int i = 0; i < particleNum; i++) {
        ofVec3f position = ofVec3f(ofRandom(width), ofRandom(height));
        particles->addParticle(position);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

    float speed = 0.1;
    particles->resetForce();
    for (int i = 0; i < particleNum; i++) {
        int val = pixels[int(particles->positions[i].y) * width + int(particles->positions[i].x)];
        int angle = ofMap(val, 0, 255, 0, PI*2.0);
        ofVec3f force;
        force.x = cos(angle) * speed;
        force.y = sin(angle) * speed;
        particles->addForce(i, force);
    }
    particles->addDampingForce();
    particles->updatePos();
    particles->resetOffWalls();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(127);
    myImage.draw(0, 0);

    ofSetColor(255);
    particles->draw();
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
