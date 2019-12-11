#version 150

uniform sampler2DRect tex0;

in vec2 texCoordVarying;
out vec4 outputColor;

vec3 lookup(vec2 p, float dx, float dy)
{
    vec2 uv = p.xy + vec2(dx, dy);
    vec4 c = texture(tex0, uv.xy);

    return c.xyz;

}

void main() {
    
//    vec2 p = texCoordVarying.xy;
//
//    float gx = 0.0;
//    gx += -1.0 * lookup(p, -1.0, -1.0);
//    gx += -2.0 * lookup(p, -1.0,  0.0);
//    gx += -1.0 * lookup(p, -1.0,  1.0);
//    gx +=  1.0 * lookup(p,  1.0, -1.0);
//    gx +=  2.0 * lookup(p,  1.0,  0.0);
//    gx +=  1.0 * lookup(p,  1.0,  1.0);
//
//    float gy = 0.0;
//    gy += -1.0 * lookup(p, -1.0, -1.0);
//    gy += -2.0 * lookup(p,  0.0, -1.0);
//    gy += -1.0 * lookup(p,  1.0, -1.0);
//    gy +=  1.0 * lookup(p, -1.0,  1.0);
//    gy +=  2.0 * lookup(p,  0.0,  1.0);
//    gy +=  1.0 * lookup(p,  1.0,  1.0);
//
//    float edge = gx*gx + gy*gy;
//
//    vec4 color = texture(tex0, p.xy);
//    color += vec4(0.0, edge, edge, 1.0);
//
////    vec4 color = vec4(1.0);
////    color = color - vec4(edge, edge, edge, 0.0);
//
//    outputColor = color;
    
    vec2 p = texCoordVarying.xy;
    
    vec3 kernelSum = vec3(0.0);
    
    kernelSum += 1.0 * lookup(p, -1.0, -1.0);
    kernelSum += 2.0 * lookup(p, -1.0,  0.0);
    kernelSum += 1.0 * lookup(p, -1.0,  1.0);
    
    kernelSum += 1.0 * lookup(p,  0.0, -1.0);
    kernelSum += 4.0 * lookup(p,  0.0,  0.0);
    kernelSum += 1.0 * lookup(p,  0.0,  1.0);
    
    kernelSum += 1.0 * lookup(p,  1.0, -1.0);
    kernelSum += 2.0 * lookup(p,  1.0,  0.0);
    kernelSum += 1.0 * lookup(p,  1.0,  1.0);
    
    vec3 averageColor = kernelSum / 9.0;
    
    outputColor = vec4(averageColor.r, averageColor.g, averageColor.b, 1.0);
}


