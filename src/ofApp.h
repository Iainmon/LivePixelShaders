#pragma once

#include "ofMain.h"
#include "ShaderRenderer.hpp"

class ofApp : public ofBaseApp {
	public:
    
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
    
    vector<ShaderRenderer*> renderers;
    
    ofVideoGrabber vidGrabber;
    int camWidth;
    int camHeight;
    
    ofImage image;
    
    int screenWidth;
    int screenHeight;
    
    int activeShaderIndex = 0;
};
