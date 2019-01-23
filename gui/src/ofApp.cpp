#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//dividing screen into 100 by 100 grid
	sectionX = (ofGetWindowWidth() / 100);
	sectionY = (ofGetWindowHeight() / 100);
	pad = sectionX * 2;
}

//--------------------------------------------------------------
void ofApp::update(){
	//will resize when window is resized
	sectionX = (ofGetWindowWidth() / 100);
	sectionY = (ofGetWindowHeight() / 100);

	sideBar.set(pad, sectionY * 15, sectionX * 28, sectionY * 80);
	mainBody.set((pad*2)+sectionX*28, sectionY * 15, (sectionX * 69) - pad, sectionY * 80);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(0, 0, 51);

	//DRAWING SECTION BOXES
	ofSetColor(0, 64, 128);
	ofDrawRectangle(sideBar);
	ofDrawRectangle(mainBody);

	//DRAWING OPTION BOXES
	//ofDrawRectangle(sectionX*2, sectionY* )

}
