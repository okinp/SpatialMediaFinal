/*
 *  particle.h
 *  flowDraw
 *
 *  Created by Nikolas Psaroudakis on 4/28/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef PARTICLE
#define PARTICLE
#include "ofMain.h"
#include "ofxVectorMath.h"

class particle {
public:
	particle();
	void update();
	void draw();
	ofxVec3f pos;
	ofxVec3f vel;
	ofxVec3f acc;
};








#endif