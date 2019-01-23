#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		int sectionX, sectionY, pad;
		
		ofRectangle sideBar, mainBody;
		
};
