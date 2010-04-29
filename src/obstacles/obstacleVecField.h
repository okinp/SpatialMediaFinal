#ifndef OBSTACLEVECFIELD_H
#define OBSTACLEVECFIELD_H

#define OF_ADDON_USING_OFXVECTORMATH
#define OF_ADDON_USING_OFXOPENCV
#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxVectorMath.h"
//#include "ofAddons.h"

#define VECF_OUT    0
#define VECF_IN     1
#define VECF_AROUND 2

class obstacleVecField
{
    public:
        obstacleVecField();
        virtual ~obstacleVecField();

        void setup( int w_, int h_, int fieldW, int fieldH );

        void update( ofxCvGrayscaleImage & src, int fieldW, int fieldH);
        ofxVec2f	getGradientVector(int x, int y);
        // computerVecField();

        void draw(int x_, int y_, float scale = 1.f);

        int w,h;
        int fieldW, fieldH;
        int mode;

        ofxCvGrayscaleImage vecFieldImage;


    protected:
    private:
};



#endif // OBSTACLEVECFIELD_H
