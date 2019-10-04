#ifndef MESAGEBUS_H
#define MESAGEBUS_H

#include <vector>
#include <unordered_map>
#include <string>


#include "../System.h"
#include "Message.h"


class MessageBuss
{
public:
	MessageBuss();

	void RegisterSystem(std::string type, System* system);

	void SendMessage(std::string type, Message msg);

	~MessageBuss();
private:

	std::unordered_map<std::string, std::vector<System*>> systems;


};
#endif // !MESAGEBUS_H

