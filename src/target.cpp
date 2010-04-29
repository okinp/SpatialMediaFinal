/*
 *  target.cpp
 *  flowDraw
 *
 *  Created by Nikolas Psaroudakis on 4/29/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "target.h"

target::target(){
	pos = ofxVec3f(0,0,0);
	width=120;
	height=150;
}

void target::draw(){
	ofRect(pos.x-width/2, pos.y-height/2, width, height);
}