#include "Message.h"



Message::Message(std::string type)
{
	m_type = type;
}
Message::Message(std::string type, Component* data)
{
	m_type = type;
	m_component = data;
}
Message::Message(std::string type, GameObject* data)
{
	m_type = type;
	m_obj = data;
}

Message::~Message()
{

}