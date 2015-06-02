#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0);

    fft.setup();
    fft.setNumFFTBins(16);
    fft.setNormalize(true);
    
    noise.freqR.set(0.2, 0.2);
    noise.freqG.set(0.4, 0.4);
    noise.freqB.set(0.8, 0.8);
    noise.speed.set(ofRandom(1.0), ofRandom(2.0), ofRandom(4.0));

    gui.setup();
    gui.add(level.setup("Input Level", 1.0, 0, 20.0));
    gui.add(noiseFrequency.setup("Noise Frequency", 80.0, 0.0, 4.0));
    gui.add(noiseSpeed.setup("Noise Speed", 1.0, 0.0, 10.0));
    gui.loadFromFile("settings.xml");
    showGui = true;
}

//--------------------------------------------------------------
void ofApp::update(){
    fft.update();

    float lowValue = ofMap(fft.getLowVal(), 0, 1, 0, level);
    float midValue = ofMap(fft.getMidVal(), 0, 1, 0, level);
    float highValue = ofMap(fft.getHighVal(), 0, 1, 0, level);
    
    noise.mul.set(lowValue, midValue, highValue);
    noise.add.set(lowValue, midValue, highValue);
    noise.freqR.set(noiseFrequency, noiseFrequency);
    noise.freqG.set(noiseFrequency * 2.0, noiseFrequency * 2.0);
    noise.freqB.set(noiseFrequency * 4.0, noiseFrequency * 4.0);
    noise.speed.set(noiseSpeed, noiseSpeed * 1.2, noiseSpeed * 1.5);
}

//--------------------------------------------------------------
void ofApp::draw(){
    noise.draw();
    if (showGui) {
        gui.draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'g') {
        if (showGui) {
            showGui = false;
            ofHideCursor();
        } else {
            showGui = true;
            ofShowCursor();
        }
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
