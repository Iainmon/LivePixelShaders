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
//    newColor.r = color.r * remap(0.0, color.r*2.0, color.g);
//    newColor.g = color.g * remap(0.0, color.g*2.0, color.b);
//    newColor.b = color.b * remap(0.0, color.b*2.0, color.r);
    
    newColor.r = color.r;
    newColor.g = color.b;
    newColor.b = color.g;

    
    // Artsy filters
    
//    newColor.r = color.r;
//    newColor.g = color.g;
//    newColor.b = 0.5;
    
//    newColor.r = (color.r + color.g + color.b) / 3.0;
//    newColor.g = 0.5;
//    newColor.b = 0.5;
    
    outputColor = newColor;
}
