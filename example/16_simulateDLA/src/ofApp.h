#pragma once

#include "ofMain.h"
#include "AggParticle.h"

class ofApp : public ofBaseApp{

public:
	void setup();
	void update();
	void draw();
	void mouseReleased(int x, int y, int button);
	void mouseDragged(int x, int y, int button);


	int width, height;
	int particleCount;
	AggParticle *mParticles;
	bool *field;
    ofVboMesh mesh;
};
