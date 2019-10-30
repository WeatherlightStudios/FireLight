#include "MessageBus.h"

std::unordered_map<std::string, std::vector<System*>> MessageBus::systems;

MessageBus::MessageBus()
{

}

void MessageBus::RegisterSystem(std::string type, System* system)
{
	systems[type].push_back(system);
}

void MessageBus::SendMessage(std::string type, Message msg)
{
	for (int i = 0; i < systems[type].size(); i++)
	{
		systems[type][i]->HandleMessage(msg);
	}
}

MessageBus::~MessageBus()
{

}