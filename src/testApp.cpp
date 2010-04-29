#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	ofSetWindowTitle("template project");
	ofBackground(0, 0, 0);
	ofSetColor(255, 255, 255);
	ofSetFrameRate(60); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.
	myBrush=new brush(10);
	field=new flowfield(20);
	showField=true;
	noise.noiseSeed((int) ofRandom(0, 10000));
	moveTarget =false;
	forceTargetMagnitude=15;
}

//--------------------------------------------------------------
void testApp::update(){
	if (showField) {
		myBrush->pos.x=mouseX;
		myBrush->pos.y=mouseY;
	} else {
		removeMe.clear();
		for (int i=0; i<Worms.size(); i++) {
			ofxVec3f wPos=Worms[i]->Parts[0]->pos;
			//cout << wPos.x<< " ";
			Worms[i]->acc=field->lookup(wPos);
			ofxVec3f forceTarget=myTarget.pos-Worms[i]->Parts[0]->pos;
			forceTarget.normalize();
			forceTarget*=forceTargetMagnitude;
			Worms[i]->acc+=forceTarget;
			Worms[i]->update();
			if (Worms[i]->checkTargetAndBounds(myTarget)) {
				removeMe.push_back(i);
			}
		}
		for (int i =0; i<removeMe.size(); i++){
			Worms.erase(Worms.begin()+removeMe[i]);		
			
		}
	}
	///check if the worms are in the target or outside of the screen
	
	
	
	
	
	
	
	
	if (moveTarget){
		myTarget.pos=ofxVec3f(mouseX,mouseY,0);
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	if (showField) {
		myBrush->draw();
		field->draw();
	} else {
		for (int i=0; i<Worms.size(); i++) {
			Worms[i]->draw();
		}
	}
	myTarget.draw();
}


//--------------------------------------------------------------
void testApp::keyPressed  (int key){
	if (key == 'f'){
		ofToggleFullscreen();
	}
	if (key=='c') {
		showField=!showField;
	}
	if (key=='n') {
		field->init(10);
	}
	if (key=='t') {
		moveTarget=!moveTarget;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	if (showField){
	myBrush->apply(field, ofxVec3f(x,y,0));
	}
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	if (!showField) {
		//w = new worm(ofxVec3f(x,y,0),ofxVec3f(0,0,0));
		Worms.push_back(new worm(ofxVec3f(x,y,0),ofxVec3f(0,0,0)));
		//particle p;
		//p.pos.x=x;
		//p.pos.y=y;
		//Particles.push_back(p);
	}
	
}


//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}
