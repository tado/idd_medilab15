#pragma once
#include "ofMain.h"

class ParticleVec2 {
    
public:
    ParticleVec2();
    void update();
    void draw();
    void addForce(ofVec2f force);
    void addForce(float forceX, float forceY);
    void bounceOffWalls();
    void throughOffWalls();
    
    // 引き付ける力
    void addAttractionForce(float x, float y, float radius, float scale);
    void addAttractionForce(ParticleVec2 &p, float radius, float scale);
    // 反発する付ける力
    void addRepulsionForce(float x, float y, float radius, float scale);
    void addRepulsionForce(ParticleVec2 &p, float radius, float scale);
        
    ofVec2f position;
    ofVec2f velocity;
    ofVec2f acceleration;
    float friction;
    float radius;
    float mass;
    float maxx, maxy, minx, miny;
};