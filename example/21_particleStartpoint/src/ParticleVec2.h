#pragma once
#include "ofMain.h"

class ParticleVec2 {
    
public:
    ParticleVec2(); //コンストラクタ
    void update();
    void draw();
    
    ofVec2f position; //位置
    ofVec2f velocity; // 速度
    ofVec2f acceleration; // 加速度
    float radius; // 表示する円の半径
};