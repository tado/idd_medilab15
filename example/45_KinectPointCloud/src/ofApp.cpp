#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    
    kinect.setRegistration(true); // カメラ画像と深度カメラのずれを解消
    kinect.init(); // Kinect初期化
    kinect.open(); // Kinect開始
}

//--------------------------------------------------------------
void ofApp::update(){
    kinect.update(); // Kinect更新
}

//--------------------------------------------------------------
void ofApp::draw(){
    int w = 640;
    int h = 480;
    ofMesh mesh; // Meshを準備
    mesh.setMode(OF_PRIMITIVE_POINTS); // Meshの頂点を点で描画
    // 指定した間隔で全てのピクセルの位置と色を取得
    int step = 2;
    for(int y = 0; y < h; y += step) {
        for(int x = 0; x < w; x += step) {
            if(kinect.getDistanceAt(x, y) > 0) {
                mesh.addColor(kinect.getColorAt(x,y));
                mesh.addVertex(kinect.getWorldCoordinateAt(x, y));
            }
        }
    }
    glPointSize(3); // 描画する点の大きさ
    
    cam.begin();  // カメラ開始
    ofPushMatrix();
    ofScale(1, -1, -1); // 上下と前後を反転
    ofTranslate(0, 0, -1000); // 全体位置を後ろへ
    ofEnableDepthTest(); // 奥の物体を隠すように
    mesh.draw(); // メッシュ描画
    ofDisableDepthTest();
    ofPopMatrix();
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
