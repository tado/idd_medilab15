#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

    ofSetLogLevel(OF_LOG_VERBOSE);

    openNIDevice.setup();//FromXML("openni/config/ofxopenni_config.xml");
    openNIDevice.setLogLevel(OF_LOG_VERBOSE);
    openNIDevice.addDepthGenerator();
    openNIDevice.addImageGenerator();   // comment this out
    openNIDevice.start();
    //openNIDevice.addInfraGenerator(); // and uncomment this to see infrared generator
                                        // or press the 'i' key when running

    verdana.loadFont(ofToDataPath("verdana.ttf"), 24);
}

//--------------------------------------------------------------
void ofApp::update(){
    openNIDevice.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(255, 255, 255);

    openNIDevice.drawDebug(); // draws all generators
    //openNIDevice.drawDepth(0, 0);
    //openNIDevice.drawImage(640, 0);

    ofSetColor(0, 255, 0);
	string msg = " MILLIS: " + ofToString(ofGetElapsedTimeMillis()) + " FPS: " + ofToString(ofGetFrameRate());
	verdana.drawString(msg, 20, ofGetHeight() - 26);

}

//--------------------------------------------------------------
void ofApp::exit(){
    openNIDevice.stop();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    switch (key) {
        case 'i':
            if (openNIDevice.isImageOn()){
                openNIDevice.removeImageGenerator();
                openNIDevice.addInfraGenerator();
                break;
            }
            if (openNIDevice.isInfraOn()){
                openNIDevice.removeInfraGenerator();
                openNIDevice.addImageGenerator();
                break;
            }
            break;
        default:
            break;
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

