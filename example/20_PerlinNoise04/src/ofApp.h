#pragma once

#include "ofMain.h"
#include "Particles.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void scaleXChanged(float & scaleX);
    void scaleYChanged(float & scaleY);
    void updateNoise();

    int width, height;

    ofImage myImage;
	unsigned char * pixels;

    int particleNum;
    Particles *particles;

    ofxPanel gui;
    ofxFloatSlider scaleX;
    ofxFloatSlider scaleY;
    ofxFloatSlider speed;
    ofxFloatSlider friction;
};
