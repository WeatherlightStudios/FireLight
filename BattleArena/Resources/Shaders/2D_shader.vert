#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

struct sprite_data
{
    float rotation;
    vec2 scale
    vec2 offset;
};


out vec2 TexCoord;


uniform mat4 model;
uniform mat4 projection;

uniform vec2 textureSize;

void main()
{
    gl_Position = projection * model * vec4(aPos ,1.0);
    TexCoord = aTexCoord;
}