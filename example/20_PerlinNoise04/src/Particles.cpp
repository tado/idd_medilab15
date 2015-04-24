#include "Particles.h"

Particles::Particles(int _maxParticles){
    maxParticles = _maxParticles;
    numParticles = 0;
    friction = 0.01;
    mesh.setMode(OF_PRIMITIVE_POINTS);
}

void Particles::resetForce(){
    for(int i = 0; i < positions.size(); i++){
        forces[i] = ofVec2f(0, 0);
    }
}

void Particles::addForce(int count, ofVec2f force){
    forces[count] += force;
}

void Particles::addDampingForce(){
    for(int i = 0; i < positions.size(); i++){
        forces[i] -= velocitys[i] * friction;
    }
}

void Particles::resetOffWalls(){
    float minx = 0;
	float miny = 0;
	float maxx = ofGetWidth();
	float maxy = ofGetHeight();
	
    for(int i = 0; i < positions.size(); i++){
        if (positions[i].x > maxx){
            positions[i].x = minx;
        }
        if (positions[i].y > maxy){
            positions[i].y = miny;
        }
        if (positions[i].x < minx){
            positions[i].x = maxx;
        }
        if (positions[i].y < miny){
            positions[i].y = maxy;
        }
    }
}

void Particles::updatePos(){
    for(int i = 0; i < positions.size(); i++){
        velocitys[i] += forces[i];
        positions[i] += velocitys[i];
    }
}

void Particles::update(){
    for(int i = 0; i < positions.size(); i++){
        forces[i] = ofVec2f(0, 0);
        forces[i] -= velocitys[i] * friction;
        velocitys[i] += forces[i];
        positions[i] += velocitys[i];
    }
}

void Particles::draw(){
    mesh.clear();
    for (int i = 0; i < positions.size(); i++) {
        mesh.addVertex(ofVec3f(positions[i].x, positions[i].y));
        mesh.addColor(ofFloatColor(1.0,1.0,1.0));
    }
    mesh.draw();
}

void Particles::addParticle(ofVec2f _position, ofVec2f _velocity, ofColor _color){
    positions.push_back(_position);
    velocitys.push_back(_velocity);
    colors.push_back(_color);
    forces.push_back(ofVec2f(0, 0));
    numParticles++;
    
    if (positions.size() > maxParticles) {
        positions.pop_front();
        colors.pop_front();
        velocitys.pop_front();
        forces.pop_front();
        numParticles--;
    }
}