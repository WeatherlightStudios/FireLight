#ifndef MESAGEBUS_H
#define MESAGEBUS_H

#include <vector>
#include <unordered_map>
#include <string>


#include "../System.h"
#include "Message.h"


class MessageBus
{
public:
	MessageBus();

	static void RegisterSystem(std::string type, System* system);

	static void SendMessage(std::string type, Message msg);

	~MessageBus();
private:

	static std::unordered_map<std::string, std::vector<System*>> systems;


};
#endif // !MESAGEBUS_H

