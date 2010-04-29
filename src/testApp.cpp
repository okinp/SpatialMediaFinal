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
}

//--------------------------------------------------------------
void testApp::update(){
	if (showField) {
		myBrush->pos.x=mouseX;
		myBrush->pos.y=mouseY;
	} else {
		for (int i=0; i<Worms.size(); i++) {
			ofxVec3f wPos=Worms[i]->Parts[0]->pos;
			cout << wPos.x<< " ";
			Worms[i]->acc=field->lookup(wPos);
			//Adding a force towards the mouse  (we'll remove it later on);
			//ofxVec3f diff= (ofxVec3f(mouseX, mouseY,0)-Worms[i]->Parts[0]->pos);
			//diff.normalize();
			//diff*=10;
			//Worms[i]->acc+=diff;
			////////////////////////////////
			Worms[i]->update();
		}
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
