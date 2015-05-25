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
    // パーティクル初期化
    for (int i = 0; i < NUM; i++) {
        particles[i].position.set(ofRandom(-ofGetWidth()/2.0, ofGetWidth()/2.0),
                                  ofRandom(-ofGetHeight()/2.0, ofGetHeight()/2.0),
                                  ofRandom(-ofGetHeight()/2.0, ofGetHeight()/2.0));
        particles[i].friction = 0.005;
        particles[i].minx = -ofGetWidth()/2.0;
        particles[i].maxx = ofGetWidth()/2.0;
        particles[i].miny = -ofGetWidth()/2.0;
        particles[i].maxy = ofGetWidth()/2.0;
        particles[i].minz = -ofGetWidth()/2.0;
        particles[i].maxz = ofGetWidth()/2.0;
    }
    // メッシュ初期化
    mesh.setMode(OF_PRIMITIVE_POINTS);
    static GLfloat distance[] = { 0.0, 0.0, 1.0 };
    glPointParameterfv(GL_POINT_DISTANCE_ATTENUATION, distance);
    glPointSize(3000);
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
        }
    }
    
    // ofxLeapMotionに現在のフレームは古くなったことを通知
    leap.markFrameAsOld();
    
    // メッシュとパーティクル更新
    mesh.clear();
    for (int i = 0; i < NUM; i++) {
        for (int j = 0; j < fingerPos.size(); j++) {
            particles[i].addAttractionForce(fingerPos[j].x, fingerPos[j].y, fingerPos[j].z, ofGetWidth(), 0.1);
        }
        particles[i].update();
        particles[i].throughOffWalls();
        mesh.addVertex(particles[i].position);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableDepthTest();
    // カメラ開始
    cam.begin();
    // 検出された指の数だけくりかえし
    ofSetColor(255, 127, 0, 127);
    for(int i = 0; i < fingerPos.size(); i++){
        // 検出された位置に球を描画
        ofSpherePrimitive sphere;
        sphere.setPosition(fingerPos[i].x, fingerPos[i].y, fingerPos[i].z);
        sphere.draw();
    }
    // メッシュ描画
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    ofSetColor(255);
    mesh.draw();
    ofDisableBlendMode();
    // カメラ終了
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
