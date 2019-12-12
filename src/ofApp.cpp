#include "ofApp.h"


void ofApp::setup() {
    
    ofSetDataPathRoot("../Resources/data/");
    
    image.load("img.jpg");
    
    camWidth = 1280;
    camHeight = 720;
    
    screenWidth = camWidth;
    screenHeight = camHeight;
    
    ofSetWindowShape(screenWidth, screenHeight);
    
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
    vidGrabber.setup(camWidth, camHeight);

    ofSetVerticalSync(true);
    
    
    vector<string> fragmentShaders = {
        "shadersGL3/filterRainbow.frag",
        "shadersGL3/shaderTimeTest.frag",
        "shadersGL3/shaderSobelEdges.frag",
        "shadersGL3/shaderSobel.frag",
        "shadersGL3/filter.frag",
        "shadersGL3/filterSwap1.frag",
        "shadersGL3/filterSwap2.frag",
        "shadersGL3/filterArtsy1.frag",
        "shadersGL3/filterArtsy2.frag"
    };
    
    // https://www.shadertoy.com/view/XlSczt
    
    ofShader* blurShader = new ofShader();
    blurShader->load("shadersGL3/passthrough.vert", "shadersGL3/shaderBlur.frag");
    
    for (int i = 0; i < fragmentShaders.size(); i++) {
        
        ofShader* shader = new ofShader();
        shader->load("shadersGL3/passthrough.vert", fragmentShaders[i]);
        
        ShaderRenderer* renderer = new ShaderRenderer();
        
//        if (i < 1) {
//            renderer->shaders.push_back(blurShader);
//        }
        
        renderer->shaders.push_back(shader);
        renderer->setDrawTarget(&vidGrabber);
        renderer->initialize(camWidth, camHeight);
        
        renderers.push_back(renderer);
    }
}

void ofApp::update(){
    
    ofBackground(100, 100, 100);

    vidGrabber.update();
    
}

void ofApp::draw() {
    
    renderers[activeShaderIndex]->draw(0, 0);
    renderers[activeShaderIndex]->lastLayer->draw(0, 0, screenWidth, screenHeight);
    
}

void ofApp::saveFramebufferToImage() {
    ofPixels pix;
    ofImage img;
    
    renderers[activeShaderIndex]->lastLayer->getTexture().readToPixels(pix);
    
    img.setFromPixels(pix);
    img.save("export.png");
}

void ofApp::keyPressed(int key){
    
}

void ofApp::keyReleased(int key) {
    
    switch (key) {
        case OF_KEY_RIGHT:
            activeShaderIndex++;
            break;
            
        case OF_KEY_LEFT:
            activeShaderIndex--;
            break;
            
        case 's':
            saveFramebufferToImage();
            break;
            
        default:
            break;
    }
    
    activeShaderIndex = ofClamp(activeShaderIndex, 0.0, renderers.size() - 1);
}



void ofApp::windowResized(int w, int h){
    screenWidth = w;
    screenHeight = h;
}



void ofApp::mouseMoved(int x, int y){
    
}

void ofApp::mouseDragged(int x, int y, int button){
    
}

void ofApp::mousePressed(int x, int y, int button){
    
}

void ofApp::mouseReleased(int x, int y, int button){
    
}

void ofApp::gotMessage(ofMessage msg){
    
}

void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
