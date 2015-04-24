#include "RandomWalker.h"

RandomWalker::RandomWalker(){
    //初期位置を画面中心に
    position.x = ofGetWidth()/2.0;
    position.y = ofGetHeight()/2.0;
    
    //移動確率をランダムに
    left = ofRandom(0.9, 1.0);
    right = ofRandom(0.9, 1.0);
    top = ofRandom(0.9, 1.0);
    bottom = ofRandom(0.9, 1.0);
}

void RandomWalker::update(){
    //上下左右同じ確率でランダムに移動
    position.x += ofRandom(-left, right);
    position.y += ofRandom(-top, bottom);
    
    /*
    // 画面からはみ出たら、反対側から出現
    if (position.x < 0) {
        position.x = ofGetWidth();
    }
    if (position.x > ofGetWidth()) {
        position.x = 0;
    }
    if (position.y < 0) {
        position.y = ofGetHeight();
    }
    if (position.y > ofGetHeight()) {
        position.y = 0;
    }
     */
}