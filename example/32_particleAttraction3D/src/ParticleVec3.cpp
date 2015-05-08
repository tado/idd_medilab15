#include "ParticleVec3.h"

ParticleVec3::ParticleVec3(){
    radius = 5.0;
    friction = 0.01;
    mass = 1.0;
    position.set(ofGetWidth()/2.0, ofGetHeight()/2.0, 0);
    velocity.set(0, 0, 0);
    acceleration.set(0, 0, 0);
}

void ParticleVec3::setup(ofVec3f _position, ofVec3f _velocity){
    position = _position;
    velocity = _velocity;
}
void ParticleVec3::setup(float positionX, float positionY, float positionZ, float velocityX, float velocityY, float velocityZ){
    position = ofVec3f(positionX, positionY, positionZ);
    velocity = ofVec3f(velocityX, velocityY, velocityZ);
}

void ParticleVec3::update(){
    acceleration -= velocity * friction;
    velocity += acceleration;
    position += velocity;
    acceleration.set(0, 0, 0);
}

void ParticleVec3::draw(){
    ofCircle(position.x, position.y, radius);
}

void ParticleVec3::addForce(ofVec3f _force){
    acceleration += _force / mass;
}
void ParticleVec3::addForce(float forceX, float forceY, float forceZ){
    acceleration += ofVec3f(forceX, forceY, forceZ) / mass;
}

void ParticleVec3::bounceOffWalls(){
    bool bDampedOnCollision = false;
    bool bDidICollide = false;
    float minx = 0;
    float miny = 0;
    float maxx = ofGetWidth();
    float maxy = ofGetHeight();
    float maxz = depth;
    float minz = -depth;
    if (position.x > maxx){
        position.x = maxx;
        velocity.x *= -1;
        bDidICollide = true;
    } else if (position.x < minx){
        position.x = minx;
        velocity.x *= -1;
        bDidICollide = true;
    }
    if (position.y > maxy){
        position.y = maxy;
        velocity.y *= -1;
        bDidICollide = true;
    } else if (position.y < miny){
        position.y = miny;
        velocity.y *= -1;
        bDidICollide = true;
    }
    if (position.z > maxz){
        position.z = maxz;
        velocity.z *= -1;
        bDidICollide = true;
    } else if (position.z < minz){
        position.z = minz;
        velocity.z *= -1;
        bDidICollide = true;
    }
    if (bDidICollide == true && bDampedOnCollision == true){
        velocity *= 0.3;
    }
}

void ParticleVec3::throughOfWalls(){
    float minx = 0;
    float miny = 0;
    float maxx = ofGetWidth();
    float maxy = ofGetHeight();
    float maxz = depth;
    float minz = -depth;
    if (position.x < minx) {
        position.x = maxx;
    }
    if (position.y < miny) {
        position.y = maxy;
    }
    if (position.z < minz) {
        position.z = maxz;
    }
    if (position.x > maxx) {
        position.x = minx;
    }
    if (position.y > maxy) {
        position.y = miny;
    }
    if (position.z > maxz) {
        position.z = minz;
    }
}

void ParticleVec3::resetToRandomPos(){
    float minx = 0;
    float miny = 0;
    float maxx = ofGetWidth();
    float maxy = ofGetHeight();
    float maxz = depth;
    float minz = -depth;
    if (position.x < minx || position.y < miny || position.z < minz || position.x > maxx || position.y > maxy || position.z > maxz) {
        position.set(ofRandom(minx, maxx), ofRandom(miny, maxy), ofRandom(minz, maxz));
    }
}

void ParticleVec3::addRepulsionForce(float x, float y, float z, float radius, float scale){
    ofVec3f posOfForce;
    posOfForce.set(x,y,z);
    ofVec3f diff = position - posOfForce;
    float length = diff.length();
    bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
    if (bAmCloseEnough == true){
        float pct = 1 - (length / radius);
        diff.normalize();
        acceleration = acceleration + diff * scale * pct;
    }
}

void ParticleVec3::addRepulsionForce(ParticleVec3 &p, float radius, float scale){
    ofVec3f posOfForce;
    posOfForce.set(p.position.x, p.position.y, p.position.z);
    ofVec3f diff = position - posOfForce;
    float length = diff.length();
    bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
    if (bAmCloseEnough == true){
        float pct = 1 - (length / radius);
        diff.normalize();
        acceleration = acceleration + diff * scale * pct;
    }
}

void ParticleVec3::addAttractionForce(float x, float y, float z, float radius, float scale){
    ofVec3f posOfForce;
    posOfForce.set(x,y,z);
    ofVec3f diff = position - posOfForce;
    float length = diff.length();
    bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
    if (bAmCloseEnough == true){
        float pct = 1 - (length / radius);
        diff.normalize();
        acceleration = acceleration - diff * scale * pct;
    }
}

void ParticleVec3::addAttractionForce(ParticleVec3 &p, float radius, float scale){
    ofVec3f posOfForce;
    posOfForce.set(p.position.x, p.position.y, p.position.z);
    ofVec3f diff = position - posOfForce;
    float length = diff.length();
    bool bAmCloseEnough = true;
    if (radius > 0){
        if (length > radius){
            bAmCloseEnough = false;
        }
    }
    if (bAmCloseEnough == true){
        float pct = 1 - (length / radius);
        diff.normalize();
        acceleration = acceleration - diff * scale * pct;
    }
}