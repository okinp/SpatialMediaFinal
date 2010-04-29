/*
 *  brush.cpp
 *  flowDraw
 *
 *  Created by Nikolas Psaroudakis on 4/22/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "brush.h"

brush::brush(int r){
	resolution=r;
	bWidth=50;
	bHeight=50;
	cols=bWidth/resolution;
	rows=bWidth/resolution;
	grid=new ofxVec3f*[rows];
	for (int i=0; i<rows; i++) {
		grid[i]=new ofxVec3f[cols];
	}
	
}
void brush::apply(flowfield *f, ofxVec3f loc){
	for (int i=0; i<rows; i++) {
		for (int j=0; j<cols; j++) {
			ofxVec3f pos_local=ofxVec3f(pos.x+j*resolution-bWidth/2,pos.y+i*resolution-bHeight/2,0);
			f->set(pos_local);
		}
	}


}
void brush::draw(){
	for (int i=0;i<rows;i++){
		for (int j=0; j<cols; j++) {
			ofEllipse(pos.x+j*resolution-bWidth/2,pos.y+i*resolution-bHeight/2,3,3);
		}
	}
}