#version 150

uniform sampler2DRect tex0;

in vec2 texCoordVarying;
out vec4 outputColor;

float remap( float minval, float maxval, float curval ) {
    return ( curval - minval ) / ( maxval - minval );
}

void main()
{
    vec4 color = texture(tex0, texCoordVarying);
    
    vec4 newColor = vec4(1.0);
    newColor.r = color.g;
    newColor.g = color.r;
    newColor.b = color.b;

    outputColor = newColor;
}

