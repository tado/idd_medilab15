#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // 画面設定
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofBackground(31);
    // 照明とカメラ
    ofEnableLighting();
    light.setPosition(200, 300, 50);
    light.enable();
    cam.setOrientation(ofPoint(-20, 0, 0));
    // Leap Motion開始
    leap.open();
}

//--------------------------------------------------------------
void ofApp::update(){
    // Leap Motion SDKで用意されている手(Hand)のクラスを取得してvector配列へ
    vector <Hand> hands = leap.getLeapHands();
    
    // 手が検出されたら
    if( leap.isFrameNew() && hands.size() ){
        // vector配列に記憶した座標をクリア
        fingerPos.clear();
        spherePos.clear();
        sphereSize.clear();
        
        // 画面の大きさにあわせて、スケールをマッピング
        leap.setMappingX(-230, 230, -ofGetWidth()/2, ofGetWidth()/2);
        leap.setMappingY(90, 490, -ofGetHeight()/2, ofGetHeight()/2);
        leap.setMappingZ(-150, 150, -200, 200);
        
        for(int i = 0; i < hands.size(); i++){
            // 指の位置を取得
            for(int j = 0; j < hands[i].fingers().count(); j++){
                ofVec3f pt;
                const Finger & finger = hands[i].fingers()[j];
                pt = leap.getMappedofPoint( finger.tipPosition() );
                fingerPos.push_back(pt);
            }
            
            // 指がとりかこむ球体を取得
            ofVec3f sp = leap.getMappedofPoint(hands[i].sphereCenter());
            float r = hands[i].sphereRadius();
            spherePos.push_back(sp);
            sphereSize.push_back(r);
        }
    }
    
    // ofxLeapMotionに現在のフレームは古くなったことを通知
    leap.markFrameAsOld();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();
    cam.begin();
    // 検出された指の数だけくりかえし
    ofSetColor(200);
    for(int i = 0; i < fingerPos.size(); i++){
        // 検出された位置に球を描画
        ofSpherePrimitive sphere;
        sphere.setPosition(fingerPos[i].x, fingerPos[i].y, fingerPos[i].z);
        sphere.draw();
    }
    
    // 検出された指がとりかこむ球
    ofSetColor(255, 0, 0, 127);
    for(int i = 0; i < spherePos.size(); i++){
        // 検出された位置に球を描画
        ofSpherePrimitive sphere;
        sphere.setPosition(spherePos[i].x, spherePos[i].y, spherePos[i].z);
        sphere.setRadius(sphereSize[i]*1.5); //ここのスケールは今は目分量…
        sphere.draw();
    }
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
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
