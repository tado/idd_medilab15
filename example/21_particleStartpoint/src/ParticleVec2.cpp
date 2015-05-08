#include "ParticleVec2.h"

ParticleVec2::ParticleVec2() :
radius(5.0), friction(0.01), mass(1.0),
position(ofVec2f(ofGetWidth()/2.0, ofGetHeight()/2.0)), velocity(ofVec2f(0, 0))
{
}

void ParticleVec2::setup(ofVec2f _position, ofVec2f _velocity){
    position = _position;
    velocity = _velocity;
}
void ParticleVec2::setup(float positionX, float positionY, float velocityX, float velocityY){
    position = ofVec2f(positionX, positionY);
    velocity = ofVec2f(velocityX, velocityY);
}

void ParticleVec2::update(){
    force = velocity * -friction;
    velocity += force;
    position += velocity;
}

void ParticleVec2::draw(){
    ofCircle(position.x, position.y, radius);
}