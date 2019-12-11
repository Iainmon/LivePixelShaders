#include "ofApp.h"


void ofApp::setup() {
    
    
    shaderBlurX.load("shadersGL3/shaderBlurX");
    shaderBlurY.load("shadersGL3/shaderBlurY");
    shaderSobel.load("shadersGL3/shaderSobel");
    shaderTest.load("shadersGL3/shaderTest");
    shaderFilter.load("shadersGL3/passthrough.vert", "shadersGL3/filter.frag");
    
    shaderFilterSwap1.load("shadersGL3/passthrough.vert", "shadersGL3/filterSwap1.frag");
    shaderFilterSwap2.load("shadersGL3/passthrough.vert", "shadersGL3/filterSwap2.frag");
    
    shaderFilterArtsy1.load("shadersGL3/passthrough.vert", "shadersGL3/filterArtsy1.frag");
    shaderFilterArtsy2.load("shadersGL3/passthrough.vert", "shadersGL3/filterArtsy2.frag");
    
    image.load("img.jpg");
    
    camWidth = 1280;
    camHeight = 720;
    
    ofSetWindowShape(camWidth * 2, camHeight * 3);
    
    vector<ofVideoDevice> devices = vidGrabber.listDevices();
    
    for (size_t i = 0; i < devices.size(); i++) {
        if (devices[i].bAvailable) {
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName;
        } else {
            ofLogNotice() << devices[i].id << ": " << devices[i].deviceName << " - unavailable ";
        }
    }
    
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(60);
    vidGrabber.initGrabber(camWidth, camHeight);

    ofSetVerticalSync(true);
    
    shaderRenderer.shaders.push_back(&shaderSobel);
    //shaderRenderer.setDrawTarget(&image);
    shaderRenderer.setDrawTarget(&vidGrabber);
    shaderRenderer.initialize(camWidth, camHeight);
    
    shaderRenderer2.shaders.push_back(&shaderFilter);
    //shaderRenderer.setDrawTarget(&image);
    shaderRenderer2.setDrawTarget(&vidGrabber);
    shaderRenderer2.initialize(camWidth, camHeight);
    
    shaderRendererFilter1.shaders.push_back(&shaderFilterSwap1);
    shaderRendererFilter1.setDrawTarget(&vidGrabber);
    shaderRendererFilter1.initialize(camWidth, camHeight);
    
    shaderRendererFilter2.shaders.push_back(&shaderFilterSwap2);
    shaderRendererFilter2.setDrawTarget(&vidGrabber);
    shaderRendererFilter2.initialize(camWidth, camHeight);
    
    shaderRendererFilter3.shaders.push_back(&shaderFilterArtsy1);
    shaderRendererFilter3.setDrawTarget(&vidGrabber);
    shaderRendererFilter3.initialize(camWidth, camHeight);
    
    shaderRendererFilter4.shaders.push_back(&shaderFilterArtsy2);
    shaderRendererFilter4.setDrawTarget(&vidGrabber);
    shaderRendererFilter4.initialize(camWidth, camHeight);
}

void ofApp::update(){
    
    ofBackground(100, 100, 100);

    vidGrabber.update();
    
}

void ofApp::draw() {
    
    shaderRenderer.draw(0, 0);
    shaderRenderer.lastLayer->draw(0, 0, camWidth, camHeight);
    
    shaderRenderer2.draw(0, 0);
    shaderRenderer2.lastLayer->draw(camWidth, 0, camWidth, camHeight);
    
    shaderRendererFilter1.draw(0, 0);
    shaderRendererFilter1.lastLayer->draw(0, camHeight, camWidth, camHeight);
    
    shaderRendererFilter2.draw(0, 0);
    shaderRendererFilter2.lastLayer->draw(camWidth, camHeight, camWidth, camHeight);
    
    shaderRendererFilter3.draw(0, 0);
    shaderRendererFilter3.lastLayer->draw(0, camHeight * 2, camWidth, camHeight);
    
    shaderRendererFilter4.draw(0, 0);
    shaderRendererFilter4.lastLayer->draw(camWidth, camHeight * 2, camWidth, camHeight);
    
}

















//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
