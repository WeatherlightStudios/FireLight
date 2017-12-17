#include "DataCenter.h"
#include <map>

DataCenter::DataCenter()
{

}

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



DataCenter::~DataCenter()
{

}
