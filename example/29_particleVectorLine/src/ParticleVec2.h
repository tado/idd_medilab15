#pragma once
#include "ofMain.h"

class ParticleVec2 {
    
public:
    ParticleVec2();
    void update();
    void draw();
    
    void addForce(ofVec2f force);
    void addForce(float forceX, float forceY);
    
    void bounceOffWalls(); // 壁で跳ね返る
    void throughOffWalls(); // 反対側に突き抜ける
    
    ofVec2f position;
    ofVec2f velocity;
    ofVec2f acceleration;
    float friction;
    float radius;
    float mass;
    float maxx, maxy, minx, miny; // 枠の範囲
};