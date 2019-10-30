#version 330 core

out vec4 FragColor;

in vec3 Normal;  
in vec3 objColor;
in vec3 FragPos;


void main()
{


	//ambient
	vec3 lightColor = vec3(1,1,1);
	vec3 lightDirection = vec3(-0.2f, -1.0f, -0.3f);
	vec3 lightPos = vec3(1,5,1);
	float ambientStrenght = 0.01f;

	vec3 ambient = ambientStrenght * lightColor;


	// diffuse
	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(-lightDirection);
	float diff = max(dot(norm, lightDir), 0.0);
	vec3 diffuse = diff * lightColor;

	vec3 result = (ambient + diffuse) * objColor;


    FragColor = vec4(result, 1.0);
}