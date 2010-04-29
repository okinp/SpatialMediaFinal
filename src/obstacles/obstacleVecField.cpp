#include "obstacleVecField.h"


obstacleVecField::obstacleVecField()
{
    //ctor
}

obstacleVecField::~obstacleVecField()
{
    //dtor
}

void obstacleVecField::setup( int w_, int h_, int fW, int fH )
{
    w = w_;
    h = h_;

    fieldW = fW;
    fieldH = fH;

    vecFieldImage.allocate(w,h);

}

void obstacleVecField::update( ofxCvGrayscaleImage & src, int fieldW, int fieldH)
{
    // scale image
    if( src.width != w || src.height != h ) vecFieldImage.scaleIntoMe( src );
    else                                    vecFieldImage = src;


}


//------------------------------------------------------------------------------------
ofxVec2f	obstacleVecField::getGradientVector(int x, int y)
{


	unsigned char * pixels = vecFieldImage.getPixels();

    ofxVec2f dir 		= ofxVec2f(0,0);
	ofxVec2f dirIn     	= ofxVec2f(0,0);
	ofxVec2f dirAround 	= ofxVec2f(0,0);
	ofxVec2f dirOut 		= ofxVec2f(0,0);

	int nw = (y+1) * w + (x-1);
	int n_ = (y+1) * w + (x);
	int ne = (y+1) * w + (x+1);

	int _w = (y) * w + (x-1);
	int me = (y) * w + (x);
	int _e = (y) * w + (x+1);

	int sw = (y-1) * w + (x-1);
	int s_ = (y-1) * w + (x);
	int se = (y-1) * w + (x+1);

	int total = w * h;

	if( y > 1 && x > 1 && x < w-1 && y < h-1)
	{

        float top   =  (pixels[nw]) + (pixels[n_]) + (pixels[ne]) ;
        float bot   =  (pixels[sw]) + (pixels[s_]) + (pixels[se]) ;
        float lef  	=  (pixels[nw]) + (pixels[_w]) + (pixels[sw]) ;
        float rig 	=  (pixels[ne]) + (pixels[_e]) + (pixels[se]) ;

        switch(mode)
        {
         case VECF_OUT:      dir.set( (lef/3.f)-(rig/3.f),(top/3.f)-(bot/3.f) );        break;
         case VECF_IN:       dir.set( (rig/3.f)-(lef/3.f),(bot/3.f)-(top/3.f) );        break;
         case VECF_AROUND:   dir.set( (bot/3.f)-(top/3.f),- ( (rig/3.f)-(lef/3.f) ) );  break;
        }

	}

	return dir;//.25*dirOut+.75*dirAround;
}

void obstacleVecField::draw(int x_, int y_, float scale)
{

    float scaleX = fieldW / (float)w;
    float scaleY = fieldH / (float)h;

    for( int x = 1; x < w; x+= 10)
    {
        for( int y = 1; y < h; y+= 10)
        {
            ofxVec2f dir = getGradientVector(x,y);
            dir.normalize();
            if(dir.length() >  0)
            {
                ofLine(x*scaleX ,(y*scaleY),(x*scaleX)+10*dir.x,(scaleY*y)+10*dir.y);
                ofCircle(x*scaleX ,y*scaleY,2);
            }
        }
    }

}
