/*
 *  brush.h
 *  flowDraw
 *
 *  Created by Nikolas Psaroudakis on 4/22/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef BRUSH
#define BRUSH
#include "ofMain.h"
#include "ofxVectorMath.h"
#include "flowfield.h"
class brush{
public:
	brush(int r);
	int rows;
	int cols;
	int resolution;
	int bWidth, bHeight;
	ofxVec3f pos;
	ofxVec3f **grid;
	void apply(flowfield *f, ofxVec3f loc);
	void draw();
};





#endif