#version 150

uniform sampler2DRect tex0;
uniform float lifeTime;
uniform vec2 resolution;

in vec2 texCoordVarying;

out vec4 outputColor;

void main()
{
    vec2 uv = texCoordVarying.xy / resolution.xy;
    
    vec4 color = texture(tex0, texCoordVarying);
    
    color.b = ((color.b / 2.0) + (1.0 - ((uv.x + uv.y) /2.0))) * abs(sin(lifeTime));
    color.r = ((color.r / 2.0) + (uv.x + uv.y) /2.0) * abs(cos(lifeTime));
    color.g = ((color.g / 2.0) + ((uv.x - uv.y)* 2.0)) * abs(sin(lifeTime)) * cos(lifeTime);
    
    outputColor = color;
}
