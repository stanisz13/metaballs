#version 330 core

in vec2 posPass;
out vec4 fragColor;

uniform float aRatio;
uniform int ballsNum;

const int MAX_BALLS_NUM = 20;

uniform vec2 ballsPos[MAX_BALLS_NUM];
uniform float radii[MAX_BALLS_NUM];
uniform vec3 colors[MAX_BALLS_NUM];

uniform mat2 mat;

const float epsilon = 0.00000001f;

bool equalsZero(const float a)
{
    return abs(a - epsilon) < epsilon;
}

void main()
{
    vec2 pos = posPass;
    pos.x *= aRatio;
    
    vec3 color = vec3(0.0f);
    for (int i = 0; i < ballsNum; ++i)
    {
        float curX = ballsPos[i].x - pos.x;
        float curY = ballsPos[i].y - pos.y;
        float dist = curX * curX + curY * curY;
        dist = sqrt(dist);

        color += colors[i] * (radii[i] / dist);
    }

    fragColor = vec4(color.xy * mat, color.z, 1.0f);
}
