#version 330 core

in vec2 posPass;
out vec4 fragColor;

uniform float aRatio;

const int MAX_BALLS_NUM = 3;

uniform float ballsPosX[MAX_BALLS_NUM];
uniform float ballsPosY[MAX_BALLS_NUM];
uniform float radii[MAX_BALLS_NUM];

const float epsilon = 0.00000001f;

bool equalsZero(const float a)
{
    return abs(a - epsilon) < epsilon;
}

void main()
{
    vec3 color = vec3(0);

    vec2 pos = posPass;
    pos.x *= aRatio;
    
    float sum = 0.0f;
    for (int i = 0; i < MAX_BALLS_NUM; ++i)
    {
        float curX = ballsPosX[i] - pos.x;
        float curY = ballsPosY[i] - pos.y;
        float dist = curX * curX + curY * curY;
        dist = sqrt(dist);
        sum += radii[i] / dist;
    }
    
    if (!equalsZero(sum))
    {
        color.r = sum;
    }
    
    fragColor = vec4(color, 1.0f);
}
