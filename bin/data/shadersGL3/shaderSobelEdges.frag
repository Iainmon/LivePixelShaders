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

vec3 rgbtohsv(vec3 c) {
    vec4 K = vec4(0.0, -1.0 / 3.0, 2.0 / 3.0, -1.0);
    vec4 p = mix(vec4(c.bg, K.wz), vec4(c.gb, K.xy), step(c.b, c.g));
    vec4 q = mix(vec4(p.xyw, c.r), vec4(c.r, p.yzx), step(p.x, c.r));

    float d = q.x - min(q.w, q.y);
    float e = 1.0e-10;
    return vec3(abs(q.z + (q.w - q.y) / (6.0 * d + e)), d / (q.x + e), q.x);
}

vec3 hsvtorgb(vec3 c) {
    vec4 K = vec4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
    vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
    return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
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

    float edgeWeight = gx*gx + gy*gy;

    float edgeAngle = atan(gy / gx);
    
    vec3 hsvColor = vec3(edgeAngle, 1.0, edgeWeight); // First parameter is hue.
    
    vec3 rgbColor = hsvtorgb(hsvColor);
    vec4 rgbaColor = vec4(rgbColor.r, rgbColor.g, rgbColor.b, 1.0);
    
    
    outputColor = rgbaColor;
}

//    vec4 color = texture(tex0, p.xy);
//
//    color += vec4(0.0, edge, edge, 1.0);
