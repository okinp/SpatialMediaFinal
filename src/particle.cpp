/*
 *  particle.cpp
 *  flowDraw
 *
 *  Created by Nikolas Psaroudakis on 4/28/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "particle.h"

particle::particle(){



}
void particle::update(){
	vel+=acc;
	vel+=ofxVec3f(ofRandom(-3,3),ofRandom(-3,3),0);
	vel.limit(8);
	pos+=vel;
}
void particle::draw(){

	ofEllipse(pos.x, pos.y, 15, 15);


}