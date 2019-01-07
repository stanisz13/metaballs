#version 330 core

in vec2 posPass;

out vec4 fragColor;

void main()
{
    vec3 color = vec3(0);

    vec2 pos = posPass;
    pos.y *= 1080.0f / 1920.0f;
    pos *= 5.0f;
    
    float dist = pos.x*pos.x + pos.y * pos.y;
    
    color.r = mix(0.0f, 1.0f, 1.0f/dist);
    
    fragColor = vec4(color, 1.0f);
}
