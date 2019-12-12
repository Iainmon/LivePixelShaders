//
//  ShaderRenderer.cpp
//  oFShaders
//
//  Created by Iain Moncrief on 12/9/19.
//

#include "ShaderRenderer.hpp"

ShaderRenderer::ShaderRenderer() {
    drawFunction = nullptr;
    target = nullptr;
    startTime = ofGetSystemTimeMillis();
}
ShaderRenderer::~ShaderRenderer() {
    
}

void ShaderRenderer::setDrawTarget(ofBaseDraws *_target) {
    target = _target;
}

void ShaderRenderer::initialize(int width, int height) {
    
    widthSize = width;
    heightSize = height;
    
    for (int i = 0; i < shaders.size(); i++) {
        ofFbo* layer = new ofFbo();
        layer->allocate(width, height);
        shaderLayers.push_back(layer);
    }
}

void ShaderRenderer::draw(float x, float y) {
    renderShaders(x, y);
}

void ShaderRenderer::renderShaders(float x, float y) {
    
    float lifeTime = ((float)(ofGetSystemTimeMillis() - startTime)) / 1000.0; // Time in seconds with decimal.
    
    const int layersToRender = shaderLayers.size();
    for (int i = 0; i < layersToRender; i++) {
        
        ofFbo* layer = shaderLayers[i];
        ofShader* shader = shaders[i];
        
        layer->begin();
        shader->begin();
        
        shader->setUniform1f("lifeTime", lifeTime);
        shader->setUniform2f("resolution", widthSize, heightSize);
        
        if (i == 0) {
            target->draw(x, y);
        } else {
            shaderLayers[i - 1]->draw(x, y);
        }
        
        shader->end();
        layer->end();

        
        lastLayer = layer;

    }
    
}

