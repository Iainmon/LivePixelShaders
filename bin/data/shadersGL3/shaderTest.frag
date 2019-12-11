#version 150

uniform sampler2DRect tex0;

in vec2 texCoordVarying;
out vec4 outputColor;

// Gaussian weights from http://dev.theomader.com/gaussian-kernel-calculator/

void main()
{
    vec4 color = texture(tex0, texCoordVarying);
    
    outputColor = color;
}
