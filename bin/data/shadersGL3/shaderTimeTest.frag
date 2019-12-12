#version 150

uniform sampler2DRect tex0;
uniform float lifeTime;

in vec2 texCoordVarying;
out vec4 outputColor;

void main()
{
    vec4 color = texture(tex0, texCoordVarying);
    
    vec4 newColor = vec4(1.0);
    
    newColor.r = abs(sin(lifeTime));
    newColor.g = color.b;
    newColor.b = color.g;
    
    outputColor = newColor;
}
