#pragma once
#include "ofMain.h"

class ParticleVec2 {
    
public:
    ParticleVec2();
    void update();
    void draw();
    
    ofVec2f position;
    ofVec2f velocity;
    ofVec2f acceleration;
    float radius;
    float friction; // 摩擦力
};