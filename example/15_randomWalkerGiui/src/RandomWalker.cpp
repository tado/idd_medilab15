#include "RandomWalker.h"

RandomWalker::RandomWalker(){
    position.x = ofGetWidth()/2;
    position.y = ofGetHeight()/2;
    top = ofRandom(1.0);
    bottom = ofRandom(1.0);
    left = ofRandom(1.0);
    right = ofRandom(1.0);
}

void RandomWalker::draw(){
    position.x += ofRandom(-left, right);
    position.y += ofRandom(-top, bottom);
    
    if (position.x < 0) {
        position.x = ofGetWidth();
    }
    if (position.x > ofGetWidth()) {
        position.x = 0;
    }
    if (position.y < 0) {
        position.y = ofGetHeight();
    }
    if (position.y > ofGetHeight()) {
        position.y = 0;
    }
}