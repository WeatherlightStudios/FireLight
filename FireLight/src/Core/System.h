#pragma once

#include "MessageSystem/Message.h"

class System
{
public:
	System();
	virtual void Init() {}
	virtual void Debug() {}

	void MesageHandling(Message* msg);
	~System();
};

