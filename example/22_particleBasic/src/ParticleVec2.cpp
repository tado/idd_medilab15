#include "ParticleVec2.h"

ParticleVec2::ParticleVec2(){
    // 初期設定
    radius = 5.0;
    position = ofVec2f(ofGetWidth()/2.0, ofGetHeight()/2.0);
    velocity = ofVec2f(0, 0);
}

void ParticleVec2::update(){
    velocity += acceleration; // 加速度から速度を算出
    position += velocity; // 速度から位置を変更
    acceleration.set(0, 0); // 加速度をリセット
}

void ParticleVec2::draw(){
    ofCircle(position.x, position.y, radius); // 円を描画
}