/*
 *  flowfield.cpp
 *  flowDraw
 *
 *  Created by Nikolas Psaroudakis on 4/22/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "flowfield.h"
flowfield::flowfield(int r){
	resolution=r;
	cols=ofGetScreenWidth()/resolution;
	rows=ofGetScreenHeight()/resolution;
	grid=new ofxVec3f*[rows];
	for (int i=0; i<rows; i++) {
		grid[i]=new ofxVec3f[cols];
	}
}
void flowfield::draw(){
	for (int i=0;i<cols;i++){
		for (int j=0; j<rows; j++) {
			drawVector(grid[j][i],i*resolution,j*resolution,1);
		}
	}
	//ofEllipse(checkMe.x,checkMe.y,20,20);
}

void flowfield::drawVector(ofxVec3f v, float x, float y, float scale){
    ofPushMatrix();
    float arrowsize = 4;
    // Translate to location to render vector
    ofTranslate(x,y);
	ofRotateZ(ofRadToDeg(atan2(v.y, v.x)));
	
    ofSetColor(100, 100,100);
    // Call vector heading function to get direction (note that pointing up is a heading of 0) and rotate
    
    // Calculate length of vector & scale it to be bigger or smaller if necessary
    float len = v.length()*scale;
    // Draw three lines to make an arrow (draw pointing up since we've rotate to the proper direction)
    ofLine(0,0,len,0);
    ofLine(len,0,len-arrowsize,+arrowsize/2);
    ofLine(len,0,len-arrowsize,-arrowsize/2);
    ofPopMatrix();
}
ofxVec3f flowfield::lookup(ofxVec3f look){
    int i = (int) constrain(look.x/resolution,0,cols-1);
    int j = (int) constrain(look.y/resolution,0,rows-1);
    return grid[j][i];
}
ofxVec3f flowfield::inverseLookup(int i, int j){
	
	return ofxVec3f(i*resolution,j*resolution,0);
	
	
}
void flowfield::set(ofxVec3f look){
	ofxVec3f brushCenter= ofxVec3f(ofGetAppPtr()->mouseX, ofGetAppPtr()->mouseY,0);
    int i = (int) constrain(look.x/resolution,0,cols-1);
    int j = (int) constrain(look.y/resolution,0,rows-1);
	ofxVec3f gridPos=ofxVec3f(i*resolution, j*resolution,0);
	checkMe=gridPos;
	ofxVec3f diff=brushCenter-gridPos;
	float length=diff.length();
	diff.normalize();
	diff*=1000/(length*length);
	grid[j][i]+=diff;
	grid[j][i]=grid[j][i].limit(resolution/2);
}
float flowfield::constrain(float in, float min, float max){
	if (in>max) {
		return max;
	} else if (in<min) {
		return min;
	} else {
		return in;
	}
}




