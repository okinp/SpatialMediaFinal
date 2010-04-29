/*
 *  wormParts.cpp
 *  otherSMfinal
 *
 *  Created by Nikolas Psaroudakis on 4/21/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "wormParts.h"

wormParts::wormParts(ofxVec3f _pos, float _maxVel){
	pos=_pos;
	stiffness = 4; 
	damping = 1;
	maxVel=_maxVel;
	
}
void wormParts::update(ofxVec3f _posOther){
	acc=_posOther-pos;
	ofxVec3f normAcc=acc.getNormalized();
	acc=stiffness*(_posOther-pos); //direction
	vel+=5*normAcc;
	vel.limit(maxVel);
	vel=damping*vel;
	pos+=vel;
}
void wormParts::draw(){
	ofEllipse(pos.x, pos.y, 8, 8);
	

}
