#pragma once

#include "ofMain.h"
#include "ofxKinect.h"
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
    
    ofxKinect kinect;       // Kinectインスタンス
    ofImage kinectImage;    // Kinectカメラ映像
    ofImage depthImage;     // Kinect深度映像
    ofEasyCam cam;          // カメラ
    
    ofxPanel gui;
    ofxFloatSlider positionZ;
    ofxFloatSlider scaleZ;
    ofxFloatSlider pointSize;
    ofxIntSlider step;
};
