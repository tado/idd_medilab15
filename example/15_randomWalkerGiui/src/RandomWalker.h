#pragma once
#include "ofMain.h"

class RandomWalker {
public:
    RandomWalker(); // コンストラクター
    void draw();
    
    ofVec2f position;
    float top, bottom, left, right;
};
