#pragma once

#include "ofMain.h"
#include "ofxProcessFFT.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    
    ProcessFFT fft;         // FFT分析
    ofxPanel gui;           // GUI
    ofxFloatSlider level;   // 入力レベル調整
};
