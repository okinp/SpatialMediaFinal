/*
 *  worm.cpp
 *  otherSMfinal
 *
 *  Created by Nikolas Psaroudakis on 4/21/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "worm.h"

worm::worm(ofxVec3f _pos, ofxVec3f _vel){
	maxVel=8;
	maxDist=10;
	pos=_pos;
	vel=_vel;
	numOfparts=20;   // 
	radius=8;
	spacing=0;
	Parts= new wormParts*[numOfparts];
	for (int i=0; i<numOfparts; i++) {
		Parts[i]=new wormParts(ofxVec3f(pos.x-i, pos.y,0), maxVel);
	}
}
void worm::update(){
	vel+=acc;
	vel.limit(maxVel);
	Parts[0]->pos+=vel;

	for (int i=1; i<numOfparts; i++) {
		Parts[i]->update(Parts[i-1]->pos);
	}

}
void worm::draw(){
	for (int i=0; i<numOfparts;i++){
		Parts[i]->draw();
		if (i>0) {
			float angle = atan2(Parts[i]->pos.y - Parts[i-1]->pos.y, Parts[i]->pos.x - Parts[i-1]->pos.x);
			float offSetY = -cos(angle)*15;
			float offSetX = sin(angle)*15;
			glBegin(GL_LINES);
			glColor4f(1,1,1,1);
			glVertex3f(Parts[i-1]->pos.x-offSetX, Parts[i-1]->pos.y-offSetY, Parts[i-1]->pos.z);
			glVertex3f(Parts[i-1]->pos.x+offSetX, Parts[i-1]->pos.y+offSetY, Parts[i-1]->pos.z);
			glEnd();
		}
	}

}