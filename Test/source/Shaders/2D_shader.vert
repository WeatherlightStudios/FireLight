#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

out vec2 TexCoord;


uniform mat4 model;
//uniform mat4 view;
uniform mat4 projection;

//uniform vec2 row;
//uniform vec2 offset;

void main()
{
    gl_Position = projection * model * vec4(aPos ,1.0);
    TexCoord = aTexCoord; //vec2((offset.x + aTexCoord.x) / row.x, (offset.y + aTexCoord.y) / row.y);
}