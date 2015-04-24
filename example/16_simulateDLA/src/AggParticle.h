#pragma once

#include "ofMain.h"

class AggParticle {
	
public:
	
	void setup(bool *_field, int _w, int _h);
	void reset();
	void update();
	bool alone();
	
	int x, y, w, h;
	bool stuck;
	bool *field;
	
};
