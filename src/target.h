/*
 *  target.h
 *  flowDraw
 *
 *  Created by Nikolas Psaroudakis on 4/29/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef TARGET
#define TARGET
#include "ofMain.h"
#include "ofxVectorMath.h"
class target{
public:
	ofxVec3f pos;
	float width;
	float height;
	target();
	void draw();
};





#endif