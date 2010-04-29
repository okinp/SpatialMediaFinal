/*
 *  wormParts.cpp
 *  otherSMfinal
 *
 *  Created by Nikolas Psaroudakis on 4/21/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "wormParts.h"

wormParts::wormParts(ofxVec3f _pos){
	pos=_pos;
	stiffness = 0.01; 
	damping = 0.9;
}
void wormParts::update(ofxVec3f _posOther){
	acc=stiffness*(_posOther-pos);
	vel+=acc;
	vel=damping*vel;
	pos+=vel;
}
void wormParts::draw(){
	ofEllipse(pos.x, pos.y, 8, 8);
	

}