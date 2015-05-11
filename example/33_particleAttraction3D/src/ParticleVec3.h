#pragma once
#include "ofMain.h"

class ParticleVec3 {
    
public:
    ParticleVec3();
    void addForce(ofVec3f force);
    void addForce(float forceX, float forceY, float forceZ);
    void update();
    void draw();
    
    void bounceOffWalls();
    void throughOffWalls();
    void resetToRandomPos();

    void addRepulsionForce(float x, float y, float z, float radius, float scale);
    void addRepulsionForce(ParticleVec3 &p, float radius, float scale);
    
    void addAttractionForce(float x, float y, float z, float radius, float scale);
    void addAttractionForce(ParticleVec3 &p, float radius, float scale);
    
    ofVec3f position;
    ofVec3f velocity;
    ofVec3f acceleration;
    float friction;
    float radius;
    bool bFixed;
    float mass;
    float depth;
    float minx, miny, minz;
    float maxx, maxy, maxz;
};