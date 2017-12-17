#pragma once
#include <string>
#include <FireLight.h>
#include <map>

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

	//bool
	void setBool(std::string mapName, bool value);
	bool getBool(std::string mapName);
	
	~DataCenter();

private:


	/*
	le map sono variabili che contengono coppie di valori
	in questo caso sono una stringa e un int
	per assegnare un vaalore o ricevere un valore entro nella map
	come se fosse un array, ma uso una stringa invece di un int index

	quindi le mappe sono array identificate da stringhe
	*/

	///INT
	std::map<std::string, int> IntData;
	///FLOAT
	std::map<std::string, float> FloatData;
	///VECTOR3
	std::map<std::string, glm::vec3> Vector3Data;
	///BOOL
	std::map<std::string, bool> BoolData;
	
};

