#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	//assigning fonts
	textFont.load("ARLRDBD.TTF", 32);

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

	titlePosX = ofGetWindowWidth() / 4;

	sideBar.set(pad, sectionY * 15, sectionX * 28, sectionY * 82);
	mainBody.set((pad*2)+sectionX*28, sectionY * 2, (sectionX * 69) - pad, sectionY * 140);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(0, 0, 51);

	//DRAWING TITLE
	ofSetColor(255);
	textFont.drawString("TweetScan", pad, sectionY * 10);

	//DRAWING SECTION BOXES
	ofSetColor(0, 64, 128);
	ofDrawRectangle(sideBar);
	ofDrawRectangle(mainBody);

	//DRAWING OPTION BOXES
	ofSetColor(200, 200, 200);
	for (int i = 16; i <= 95; i += 8.9) {
		ofDrawRectangle(pad + sectionX, sectionY * i, sectionX * 26, sectionY * 6.9);
	}

	//DRAWING TWEET BOXES
	for (int i = 3; i <= 110; i += 17) {
		ofDrawRectangle((pad * 2) + sectionX * 29, sectionY * i, (sectionX * 67) - pad, sectionY * 15);
	}
	

}
