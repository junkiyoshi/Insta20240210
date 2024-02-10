#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	int span = 30;
	for (int x = span; x < ofGetWindowWidth() - span; x += span) {

		for (int y = span; y < ofGetWindowHeight() - span; y += span) {

			auto noise_value = ofNoise(x * 0.0035, y * 0.0035, ofGetFrameNum() * 0.03);

			auto right = x == ofGetWindowWidth() - span * 2 ? 0.5 : ofNoise((x + span) * 0.0035, y * 0.0035, ofGetFrameNum() * 0.03);
			auto left = x == span ? 0.5 : ofNoise((x - span) * 0.0035, y * 0.0035, ofGetFrameNum() * 0.03);
			auto up = y == span ? 0.5 : ofNoise(x * 0.0035, (y - span) * 0.0035, ofGetFrameNum() * 0.03);
			auto down = y == ofGetWindowHeight() - span * 2 ? 0.5 : ofNoise(x * 0.0035, (y + span) * 0.0035, ofGetFrameNum() * 0.03);

			if (noise_value < 0.35) {

				ofSetColor(0);
				ofDrawRectangle(x, y, span, span);

				ofSetColor(255);
				if(right >= 0.35 && right <= 0.65){ ofDrawLine(x + span, y, x + span, y + span); }
				if(left >= 0.35 && left <= 0.65){ ofDrawLine(x, y, x, y + span); }
				if(up >= 0.35 && up <= 0.65){ ofDrawLine(x, y, x + span, y); }
				if(down >= 0.35 && down <= 0.65){ ofDrawLine(x, y + span, x + span, y + span); }
			}
			else if (noise_value > 0.65) {

				ofSetColor(255);
				ofDrawRectangle(x, y, span, span);

				ofSetColor(0);
				if (right >= 0.35 && right <= 0.65) { ofDrawLine(x + span, y, x + span, y + span); }
				if (left >= 0.35 && left <= 0.65) { ofDrawLine(x, y, x, y + span); }
				if (up >= 0.35 && up <= 0.65) { ofDrawLine(x, y, x + span, y); }
				if (down >= 0.35 && down <= 0.65) { ofDrawLine(x, y + span, x + span, y + span); }
			}
			else {
				
				ofSetColor(239);
				ofDrawCircle(x + span * 0.5, y + span * 0.5, span * 0.15);
			}
		}
	}

	/*
	int start = 30;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}