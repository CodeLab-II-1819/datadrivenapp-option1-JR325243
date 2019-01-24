#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofTrueTypeFont.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		int sectionX, sectionY, pad, titlePosX;
		
		ofRectangle sideBar, mainBody;

		ofTrueTypeFont textFont;
		
};
