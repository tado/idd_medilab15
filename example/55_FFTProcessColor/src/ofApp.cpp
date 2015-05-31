#include "ofApp.h"

void ofApp::setup() {
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofBackground(0);
    // FFT初期設定
    fft.setup();
    fft.setNumFFTBins(16);
    fft.setNormalize(true);
    // GUI
    gui.setup();
    gui.add(level.setup("Input Level", 500, 0, 5000));
    gui.loadFromFile("settings.xml");
}

void ofApp::update() {
    fft.update();
}

void ofApp::draw() {
    // 低域、中域、高域の値を取得
    float lowValue = ofMap(fft.getLowVal(), 0, 1, 0, level);
    float midValue = ofMap(fft.getMidVal(), 0, 1, 0, level);
    float highValue = ofMap(fft.getHighVal(), 0, 1, 0, level);
    // 画面全体を塗る
    ofSetColor(lowValue, midValue, highValue);
    ofRect(0, 0, ofGetWidth(), ofGetHeight());
    // GUI
    gui.draw();
}
