#pragma once
#include "ofMain.h"

class ParticleVec2 {
    
public:
    ParticleVec2();
    void update();
    void draw();

    // 物体に力を加える（ベクトル版とX,Y版）
    void addForce(ofVec2f force);
    void addForce(float forceX, float forceY);
    
    ofVec2f position;
    ofVec2f velocity;
    ofVec2f acceleration;
    float radius;
    float friction;
    float mass; // 質量
};