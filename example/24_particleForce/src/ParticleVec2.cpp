#include "ParticleVec2.h"

ParticleVec2::ParticleVec2(){
    radius = 5.0;
    friction = 0.01;
    mass = 1.0;
    position = ofVec2f(ofGetWidth()/2.0, ofGetHeight()/2.0);
    velocity = ofVec2f(0, 0);
}

void ParticleVec2::update(){
    acceleration -= velocity * friction;
    velocity += acceleration;
    position += velocity;
    acceleration.set(0, 0);
}

void ParticleVec2::draw(){
    ofCircle(position.x, position.y, radius);
}

void ParticleVec2::addForce(ofVec2f force){
    acceleration += force / mass; // a = F/m
}

void ParticleVec2::addForce(float forceX, float forceY){
    acceleration += ofVec2f(forceX, forceY) / mass; // a = F/m
}
