#include "ParticleVec2.h"

ParticleVec2::ParticleVec2(){
    friction = 0.01; // 摩擦力の初期設定
    radius = 5.0;
    position = ofVec2f(ofGetWidth()/2.0, ofGetHeight()/2.0);
    velocity = ofVec2f(0, 0);
}

void ParticleVec2::update(){
    // 速度に比例して摩擦力を算出して加速度を変更
    acceleration -= velocity * friction;
    velocity += acceleration;
    position += velocity;
    acceleration.set(0, 0);
}

void ParticleVec2::draw(){
    ofCircle(position.x, position.y, radius);
}