#include "RandomWalker.h"

RandomWalker::RandomWalker(){

    //初期位置を、画面内にランダムに設定
    position.x = ofRandom(ofGetWidth());
    position.y = ofRandom(ofGetHeight());
}

void RandomWalker::draw(){
    // 10回くりかえし
    for (int i = 0; i < 7; i++) {
        
        //上下左右同じ確率でランダムに移動
        position.x += ofRandom(-1.0, 1.05);
        position.y += ofRandom(-0.91, 0.9);
        
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
        
        //円を描く
        ofCircle(position.x, position.y, 1);
    }
}