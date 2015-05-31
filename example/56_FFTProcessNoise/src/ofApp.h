#pragma once

#include "ofMain.h"
#include "ofxProcessFFT.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    void resolutionChanged(int & resolution);
    
    ProcessFFT fft;             // FFT分析
    ofImage lowNoiseImg;        // ノイズ画像低域
    ofImage midNoiseImg;        // ノイズ画像中域
    ofImage highNoiseImg;       // ノイズ画像高域
    
    ofxPanel gui;                   // GUI
    ofxFloatSlider level;           // 入力レベル調整
    ofxIntSlider resolution;        // ノイズ解像度
    ofxFloatSlider noiseFrequency;   // ノイズ周波数
};
