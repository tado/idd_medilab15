#pragma once

#include "ofMain.h"
#include "ofxLeapMotion.h"

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
    
    ofxLeapMotion leap; // Leap Motionのメインクラスをインスタンス化
    vector <ofxLeapMotionSimpleHand> simpleHands; // シンプルな手のモデルのvector配列
    ofEasyCam cam; //カメラ
    ofLight light; //ライト    
};
