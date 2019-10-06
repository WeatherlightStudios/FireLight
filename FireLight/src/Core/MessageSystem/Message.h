#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include "../GameObject.h"
#include "../Component.h"



class Message
{
public:
	Message(std::string type);
	Message(std::string type, Component* data);
	Message(std::string type, GameObject* data);
	~Message();

	std::string type() { return m_type; }
	GameObject* getGameObject() { return m_obj; }
	Component* getComponent() { return m_component; }

private:

	//The type of the  message
	std::string m_type;

	GameObject* m_obj = nullptr;
	Component* m_component = nullptr;




};

#endif