#include "AggParticle.h"

void AggParticle::setup(bool *_field, int _w, int _h){
	field = _field;
	w = _w;
	h = _h;
	stuck = false;
	reset();
}

void AggParticle::reset(){
	do {
		x = ofRandom(0, ofGetWidth());
		y = ofRandom(0, ofGetHeight());
	} while (field[y * ofGetWidth() + x]);
}

void AggParticle::update(){
	if(!stuck){
		
		// random walk
		x += round(ofRandom(-1, 1));
		y += round(ofRandom(-1, 1));
		
		// check border
		if(x < 0) x = w;
		if(y < 0) y = h;
		if(x > w) x = 0;
		if(y > h) y = 0;
		
		// check alone
		if(!alone()){
			stuck = true;
			field[y * w + x] = true;
		}
	}
}

bool AggParticle::alone(){
	int cx = x;
	int cy = y;
	
	int lx = cx - 1;
	int rx = cx + 1;
	int ty = cy - 1;
	int by = cy + 1;
	
	if(cx <= 0 || cx >= w || lx <= 0 || lx >= w || rx <= 0 || rx >= w ||
	   cy <= 0 || cy >= h || ty <= 0 || ty >= h || by <= 0 || by >= h){
		return true;
	}
	
	cy *= w;
	by *= w;
	ty *= w;
	
	if(field[cx + ty] || field[lx + cy] || field[rx + cy] || field[cx + by]){
		return false;
	}
	
	if(field[lx + ty] || field[lx + by] || field[rx + ty] || field[rx + by]){
		return false;
	}
	
	return true;
}