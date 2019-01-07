#version 330 core

in vec2 posPass;
out vec4 fragColor;

const int MAX_BALLS_NUM = 1;

uniform float ballsPosX[MAX_BALLS_NUM];
uniform float ballsPosY[MAX_BALLS_NUM];


const float epsilon = 0.00000001f;

bool equalsZaro(const float a)
{
    return abs(a - epsilon) < epsilon;
}

void main()
{
    vec3 color = vec3(0);

    vec2 pos = posPass;
    pos.x *= 1920.0f / 1080.0f;
    pos *= 5.0f;

    float distSum = 0.0f;
    for (int i = 0; i < MAX_BALLS_NUM; ++i)
    {
        float curX = ballsPosX[i] - pos.x;
        float curY = ballsPosY[i] - pos.y;
        float dist = curX * curX + curY * curY;
        distSum += dist;
    }
  
    if (!equalsZaro(distSum))
    {
        color.r = mix(0.0f, 1.0f, 1.0f/sqrt(distSum));
    }
    
    fragColor = vec4(color, 1.0f);
}
