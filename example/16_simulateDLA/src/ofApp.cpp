#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    
    particleCount = 200000;
    
    width = ofGetWidth();
    height = ofGetHeight();
    
    mesh.setMode(OF_PRIMITIVE_POINTS);
    
    //initialize field
    field = new bool[width * height];
    for(int i = 0; i < width * height; i++){
        field[i] = false;
    }
    
    //setup aggregation particles
    mParticles = new AggParticle[particleCount];
    for(int i = 0; i < particleCount; i++){
        AggParticle temp;
        temp.setup(field, width, height);
        mParticles[i] = temp;
    }
}

void ofApp::update(){
    for(int i = 0; i < particleCount; i++){
        mParticles[i].update();
    }
}

void ofApp::draw(){
    ofVboMesh mesh;
    mesh.setMode(OF_PRIMITIVE_POINTS);
    
    for (int i = 0; i < particleCount; i++) {
        mesh.addVertex(ofVec2f(mParticles[i].x, mParticles[i].y));
        if(mParticles[i].stuck){
            mesh.addColor(ofFloatColor(1.0, 1.0, 1.0));
        } else {
            mesh.addColor(ofFloatColor(0.5, 0.5, 0.5));
        }
    }
    
    ofSetColor(255);
    mesh.draw();
}

void ofApp::mouseReleased(int x, int y, int button){
    field[y * width + x] = true;
}

void ofApp::mouseDragged(int x, int y, int button){
    field[y * width + x] = true;
}