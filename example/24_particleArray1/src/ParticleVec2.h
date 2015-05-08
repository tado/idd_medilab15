#pragma once
#include "ofMain.h"

class ParticleVec2 {
    
public:
    ParticleVec2();
    void setup(ofVec2f position, ofVec2f velocity);
    void setup(float positionX, float positionY, float velocityX, float velocityY);
    void update();
    void draw();
    
    void addForce(ofVec2f force);
    void addForce(float forceX, float forceY);
    
    ofVec2f position;
    ofVec2f velocity;
    ofVec2f acceleration;
    float friction;
    float radius;
    float mass;
};