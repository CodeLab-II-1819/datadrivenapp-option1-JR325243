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

	//Assigning title settings
	TitleFont.load("ARLRDBD.TTF", sectionX * 3);
	OptionFont.load("ARLRDBD.TTF", sectionX * 2);
	TweetFont.load("ARLRDBD.TTF", sectionX);

	sideBar.set(pad, sectionY * 15, sectionX * 28, sectionY * 82);
	mainBody.set((pad*2)+sectionX*28, sectionY * 2, (sectionX * 69) - pad, sectionY * 140);
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(0, 0, 51);

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
	
	//DRAWING TITLE
	ofSetColor(255);
	TitleFont.drawString("TweetScan", pad, sectionY * 10);

	//DRAWING OPTION TEXT
	ofSetColor(0);
	OptionFont.drawString("Count All", pad + sectionX * 2.5, sectionY * 21);
	OptionFont.drawString("Money", pad + sectionX * 2.5, sectionY * 29);
	OptionFont.drawString("Politics", pad + sectionX * 2.5, sectionY * 37);
	OptionFont.drawString("@JLo", pad + sectionX * 2.5, sectionY * 45);
	OptionFont.drawString("Custom Date", pad + sectionX * 2.5, sectionY * 53);
	OptionFont.drawString("Paris", pad + sectionX * 2.5, sectionY * 61);
	OptionFont.drawString("Dreamworks", pad + sectionX * 2.5, sectionY * 69);
	OptionFont.drawString("Uber", pad + sectionX * 2.5, sectionY * 77);
	OptionFont.drawString("Custom Search", pad + sectionX * 2.5, sectionY * 85);
	OptionFont.drawString("Print All", pad + sectionX * 2.5, sectionY * 93);

	//DRAWING TWEET EXAMPLE
	TweetFont.drawString("Thanks @NikeFootball for the new boots. Feel good. Look great. Time to let my feet do the talking.", (pad * 2) + sectionX * 30, sectionY * 10);
	TweetFont.drawString("03/11/2016	12.57pm", (pad * 2) + sectionX * 30, sectionY * 16);

}
