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

    ofShader shaderBlurX;
    ofShader shaderBlurY;
    
    ofShader shaderSobel;
    
    ofShader shaderFilter;
    
    ofShader shaderFilterSwap1;
    ofShader shaderFilterSwap2;
    
    ofShader shaderFilterArtsy1;
    ofShader shaderFilterArtsy2;

    
    ofShader shaderTest;
    ShaderRenderer shaderRenderer;
    ShaderRenderer shaderRenderer2;

    ShaderRenderer shaderRendererFilter1;
    ShaderRenderer shaderRendererFilter2;
    
    ShaderRenderer shaderRendererFilter3;
    ShaderRenderer shaderRendererFilter4;
    
    ofVideoGrabber vidGrabber;
    int camWidth;
    int camHeight;
    
    ofImage image;
};
