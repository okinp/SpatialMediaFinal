/*
 *  flowfield.h
 *  flowDraw
 *
 *  Created by Nikolas Psaroudakis on 4/22/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef FLOWFIELD
#define FLOWFIELD
#include "ofMain.h"
#include "ofxVectorMath.h"
#include "ofxPerlin.h"
class flowfield  {
public:
	flowfield(int r);
	int rows;
	int cols;
	int resolution;
	ofxVec3f **grid;
	void init(int maxMag);
	void draw();
	void drawVector(ofxVec3f v, float x, float y, float scale);
	ofxVec3f lookup(ofxVec3f look);
	ofxVec3f inverseLookup(int j, int i);
	void set(ofxVec3f look);
	float constrain(float in, float min, float max);
	ofxVec3f checkMe;
	ofxPerlin noise;
};







#endif