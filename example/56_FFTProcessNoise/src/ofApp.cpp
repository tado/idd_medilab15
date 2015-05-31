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
    resolution.addListener(this, &ofApp::resolutionChanged);
    gui.setup();
    gui.add(level.setup("Input Level", 100, 0, 2000));
    gui.add(resolution.setup("Resolution", 256, 2, 1024));
    gui.add(noiseFrequency.setup("Noise Frequency", 80.0, 0.0001, 1024.0));
    gui.loadFromFile("settings.xml");
    // 画像初期化
    lowNoiseImg.allocate(resolution, resolution, OF_IMAGE_GRAYSCALE);
    midNoiseImg.allocate(resolution, resolution, OF_IMAGE_GRAYSCALE);
    highNoiseImg.allocate(resolution, resolution, OF_IMAGE_GRAYSCALE);
}

void ofApp::update() {
    fft.update();
    // 低域、中域、高域の値を取得
    float lowValue = ofMap(fft.getLowVal(), 0, 1, 0, level);
    float midValue = ofMap(fft.getMidVal(), 0, 1, 0, level);
    float highValue = ofMap(fft.getHighVal(), 0, 1, 0, level);
    // ノイズ生成
    int tmpIndex;
    // 低域
    ofPixelsRef lowPixels = lowNoiseImg.getPixelsRef();
    tmpIndex = 0;
    for( int y = 0; y < lowNoiseImg.getHeight(); y++ ){
        for( int x = 0; x < lowNoiseImg.getWidth(); x++ ){
            float tmpNoise = ofNoise(x / noiseFrequency, y / noiseFrequency, ofGetElapsedTimef());
            lowPixels[tmpIndex] = tmpNoise * lowValue;
            tmpIndex++;
        }
    }
    lowNoiseImg.update();
    // 中域
    ofPixelsRef midPixels = midNoiseImg.getPixelsRef();
    tmpIndex = 0;
    for( int y = 0; y < midNoiseImg.getHeight(); y++ ){
        for( int x = 0; x < midNoiseImg.getWidth(); x++ ){
            float tmpNoise = ofNoise(x / noiseFrequency * 2.0, y / noiseFrequency * 2.0, ofGetElapsedTimef() * 2.0);
            midPixels[tmpIndex] = tmpNoise * midValue;
            tmpIndex++;
        }
    }
    midNoiseImg.update();
    // 高域
    ofPixelsRef highPixels = highNoiseImg.getPixelsRef();
    tmpIndex = 0;
    for( int y = 0; y < highNoiseImg.getHeight(); y++ ){
        for( int x = 0; x < highNoiseImg.getWidth(); x++ ){
            float tmpNoise = ofNoise(x / noiseFrequency * 4.0, y / noiseFrequency * 4.0, ofGetElapsedTimef() * 4.0);
            highPixels[tmpIndex] = tmpNoise * highValue;
            tmpIndex++;
        }
    }
    highNoiseImg.update();
}

void ofApp::draw() {

    // ノイズ描画
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofSetColor(255, 0, 0);
    lowNoiseImg.draw(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(0, 255, 0);
    midNoiseImg.draw(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(0, 0, 255);
    highNoiseImg.draw(0, 0, ofGetWidth(), ofGetHeight());

    // GUI
    gui.draw();
}

void ofApp::resolutionChanged(int & resolution){
    lowNoiseImg.allocate(resolution, resolution, OF_IMAGE_GRAYSCALE);
    midNoiseImg.allocate(resolution, resolution, OF_IMAGE_GRAYSCALE);
    highNoiseImg.allocate(resolution, resolution, OF_IMAGE_GRAYSCALE);
}
