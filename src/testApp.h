#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "brush.h"
#include "flowfield.h"
#include "particle.h"
#include "worm.h"
#include "ofxPerlin.h"
#include "target.h"

class testApp : public ofBaseApp{
	
	public:
		
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
	brush *myBrush;
	flowfield *field;
	bool showField;
	worm *w;
	//vector <particle> Particles;
	vector <worm*> Worms;
	vector <int> removeMe;
	ofxPerlin noise;
	target myTarget;
	bool moveTarget;
	float forceTargetMagnitude;
};

#endif
	
