#include "DataCenter.h"
//#include <map>

DataCenter::DataCenter()
{

}

///INT
/*
inserisco nome di una mappa e un valore int
controlla se esiste una mappa con il nome che ho inserito
se esiste modifica il valore
se non esiste crea la mappa col valore inserito
*/
void DataCenter::setInt(std::string mapName, int value) {
	IntData[mapName] = value;	//nel caso non esistesse quel nome verrebbe creata automaticamente
}


/*
inserisco il nome del valore che voglio ricevere e me lo ritorna
*/
int DataCenter::getInt(std::string mapName) {
	return IntData[mapName];
}

///FLOAT
void DataCenter::setFloat(std::string mapName, float value) {
	FloatData[mapName] = value;
}

float DataCenter::getFloat(std::string mapName) {
	return FloatData[mapName];
}

///VECTOR3
void DataCenter::setVector3(std::string mapName, glm::vec3 value) {
	Vector3Data[mapName] = value;
}

glm::vec3 DataCenter::getVector3(std::string mapName) {
	return Vector3Data[mapName];
}

///BOOL
void DataCenter::setBool(std::string mapName, bool value) {
	BoolData[mapName] = value;
}

bool DataCenter::getBool(std::string mapName) {
	return BoolData[mapName];
}


DataCenter::~DataCenter()
{

}
