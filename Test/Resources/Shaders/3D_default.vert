#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

uniform mat4 model;
uniform mat4 projection;

uniform vec3 MyColor;

out vec3 objColor;
out vec3 Normal;
out vec3 FragPos;

void main()
{
	gl_Position = projection * model * vec4(aPos, 1.0f);
	FragPos = vec3(model * vec4(aPos, 1.0f));
	Normal = aNormal;
	objColor = vec3(0.8f);
}
