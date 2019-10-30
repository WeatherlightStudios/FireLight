#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec3 Normal;
in vec4 WorldNormal;

uniform float _GrassSlopeThreshold;
uniform float _GrassBlendAmount;


void main()
{
	vec3 lightColor = vec3(1,1,1);
	vec3 lightDirection = vec3(-0.2f, -1.0f, -0.3f);
	vec3 lightPos = vec3(1,3,1);


	vec3 TerrainColor = vec3((1.0f / 255) * 92, (1.0f / 255) * 150, (1.0f / 255) * 5);
	vec3 GrassColor = vec3((1.0f / 255) * 117, (1.0f / 255) * 65, (1.0f / 255) * 0);
	vec3 SnowColor = vec3(1,1,1);


	float slope = 1.0f - WorldNormal.y;
	float grassBlendHeight = _GrassSlopeThreshold * (1 - _GrassBlendAmount);
	float grassWeight = 1 - clamp((slope - grassBlendHeight)/(_GrassSlopeThreshold - _GrassBlendAmount), 0.0f, 1.0f);


	vec3 objColor = GrassColor * grassWeight + TerrainColor * (1-grassWeight);

	float ambientStrenght = 0.1f;

	vec3 ambient = ambientStrenght * lightColor;

	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(-lightDirection);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * lightColor;

	vec3 result = (ambient + diffuse) * objColor;

	FragColor = vec4(result,1.0f);
}