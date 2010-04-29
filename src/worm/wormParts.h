/*
 *  wormParts.h
 *  otherSMfinal
 *
 *  Created by Nikolas Psaroudakis on 4/21/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef PARTS
#define PARTS

#include "ofMain.h"
#include "ofxVec3f.h"

class wormParts {
public:
	wormParts(ofxVec3f _pos, float _maxVel);
	void update(ofxVec3f _posOther);
	void draw();
	float maxVel;
	ofxVec3f pos;
	ofxVec3f acc;
	ofxVec3f vel;
	float stiffness;
	float damping;
};







#endif