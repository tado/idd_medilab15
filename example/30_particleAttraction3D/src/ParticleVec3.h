#pragma once
#include "ofMain.h"

class ParticleVec3 {
    
public:
    ParticleVec3();
    void setup(ofVec3f position, ofVec3f velocity);
    void setup(float positionX, float positionY, float positionZ, float velocityX, float velocityY, float velocityZ);
    void resetForce();
    void addForce(ofVec3f force);
    void addForce(float forceX, float forceY, float forceZ);
    void updateForce();
    void updatePos();
    void update();
    void draw();
    
    void bounceOffWalls();
    void throughOfWalls();
    void resetToRandomPos();

    void addRepulsionForce(float x, float y, float z, float radius, float scale);
    void addRepulsionForce(ParticleVec3 &p, float radius, float scale);
    
    void addAttractionForce(float x, float y, float z, float radius, float scale);
    void addAttractionForce(ParticleVec3 &p, float radius, float scale);
    
    ofVec3f position;
    ofVec3f velocity;
    ofVec3f force;
    float friction;
    float radius;
    bool bFixed;
    float mass;
    float height;
};