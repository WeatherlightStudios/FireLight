#pragma once
#include <string>
#include <FireLight.h>

class DataCenter
{
public:
	DataCenter();
	
	//Int
	void setInt(std::string mapName, int value);
	int getInt(std::string mapName);
	
	//Float
	void setFloat(std::string mapName, float value);
	float getFloat(std::string mapName);
	
	//vec3
	void setVector3(std::string mapName, glm::vec3 value);
	glm::vec3 getVector3(std::string mapName);
	
	~DataCenter();

private:

	
	
};

