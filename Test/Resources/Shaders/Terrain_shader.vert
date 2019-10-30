#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec3 ourColor;
out vec3 Normal;
out vec4 WorldNormal;

uniform mat4 model;
uniform mat4 projection;

void main()
{
	gl_Position = projection * model * vec4(aPos, 1.0);
	Normal = aNormal;
	WorldNormal = normalize(vec4(aNormal, 1.0) * (model * vec4(aPos, 1.0)));
	ourColor = aNormal;
}