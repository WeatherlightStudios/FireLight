#version 330 core

out vec4 FragColor;

 in vec3 Normal;
 in vec3 FragPos;

void main()
{
	vec3 objectColor = vec3(1.0f,0.0f,0.0f);
	vec3 lightColor = vec3(1.0f,1.0f,1.0f);
	
	vec3 ambientColor = vec3(1.0f,0.0f,(1.0f / 255) * 72);
	vec3 ambientColor2 = vec3(1.0f,0.0f,(1.0f / 255) * 144);

	vec3 norm = normalize(Normal);
	vec3 lightDir = normalize(vec3(-2.0f,3.0f,-1.0f) - FragPos);  
	float diff = max(dot(norm, lightDir), 0.0) * 0.5 + 0.5;
	if(diff >= 0.5f)
	{
		vec3 diffuse = diff * lightColor;
		float ambientStrength = 0.2;
	    vec3 ambient = ambientStrength * lightColor;
		vec3 result = (ambient + diffuse) * objectColor;
		FragColor = vec4(result, 1.0);
	}

	if(diff <= 0.5f)
	{
		vec3 diffuse = diff * lightColor;
		float ambientStrength = 0.2;
	    vec3 ambient = ambientStrength * lightColor;
		vec3 result = (ambient + diffuse) * ambientColor;
		FragColor = vec4(result, 1.0);
	}
	else if(diff <= 0.5f)
	{
		vec3 diffuse = diff * lightColor;
		float ambientStrength = 0.2;
	    vec3 ambient = ambientStrength * lightColor;
		vec3 result = (ambient + diffuse) * ambientColor2;
		FragColor = vec4(result, 1.0);

	}

}