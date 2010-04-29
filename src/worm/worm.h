/*
 *  worm.h
 *  otherSMfinal
 *
 *  Created by Nikolas Psaroudakis on 4/21/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef WORM
#define WORM

#include "ofMain.h"
#include "ofxVectorMath.h"
#include "wormParts.h"

class worm{
public:
	worm(ofxVec3f _pos, ofxVec3f _vel);
	void update();
	void draw();
	ofxVec3f vel;
	ofxVec3f pos;
	ofxVec3f acc;
	wormParts **Parts;
	int radius;
	int spacing;
	int numOfparts;
	
	
};







#endif