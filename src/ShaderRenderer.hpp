//
//  ShaderRenderer.hpp
//  oFShaders
//
//  Created by Iain Moncrief on 12/9/19.
//

#pragma once

#include "ofMain.h"

typedef void (*DrawCallback)(float, float);

class ShaderRenderer {
    private:
    
    vector<ofFbo*> shaderLayers;
    
    DrawCallback drawFunction;
    ofBaseDraws *target;
    
    void renderShaders(float x, float y);
    
    public:
    
    ShaderRenderer();
    ~ShaderRenderer();
    
    vector<ofShader*> shaders;
    
    void initialize(int width, int height);
    
    void setDrawTarget(ofBaseDraws *_target);
    
//    void draw(float x, float y, float width, float height);
    void draw(float x, float y);
        
    ofFbo* lastLayer = nullptr;

};
