#version 150

uniform sampler2DRect tex0;

in vec2 texCoordVarying;
out vec4 outputColor;

float lookup(vec2 p, float dx, float dy)
{
    vec2 uv = p.xy + vec2(dx, dy);
    vec4 c = texture(tex0, uv.xy);

    return (c.r + c.g + c.b) / 3.0;

}

void main()
{
    vec2 p = texCoordVarying.xy;

    float gx = 0.0;
    gx += -1.0 * lookup(p, -1.0, -1.0);
    gx += -2.0 * lookup(p, -1.0,  0.0);
    gx += -1.0 * lookup(p, -1.0,  1.0);
    gx +=  1.0 * lookup(p,  1.0, -1.0);
    gx +=  2.0 * lookup(p,  1.0,  0.0);
    gx +=  1.0 * lookup(p,  1.0,  1.0);

    float gy = 0.0;
    gy += -1.0 * lookup(p, -1.0, -1.0);
    gy += -2.0 * lookup(p,  0.0, -1.0);
    gy += -1.0 * lookup(p,  1.0, -1.0);
    gy +=  1.0 * lookup(p, -1.0,  1.0);
    gy +=  2.0 * lookup(p,  0.0,  1.0);
    gy +=  1.0 * lookup(p,  1.0,  1.0);

    float edge = gx*gx + gy*gy;

    vec4 color = texture(tex0, p.xy);
    color += vec4(0.0, edge, edge, 1.0);
    
//    vec4 color = vec4(1.0);
//    color = color - vec4(edge, edge, edge, 0.0);
    
    outputColor = color;
}

