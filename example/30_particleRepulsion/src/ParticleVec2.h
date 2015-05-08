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
    
    void bounceOffWalls();
    void throughOfWalls();
    
    void addAttractionForce(float x, float y, float radius, float scale);
    void addAttractionForce(ParticleVec2 &p, float radius, float scale);
    void addRepulsionForce(float x, float y, float radius, float scale);
    void addRepulsionForce(ParticleVec2 &p, float radius, float scale);
        
    ofVec2f position;
    ofVec2f velocity;
    ofVec2f acceleration;
    float friction;
    float radius;
    float mass;
};