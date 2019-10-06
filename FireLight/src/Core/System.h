#pragma once

#include "MessageSystem/Message.h"

class System
{
public:
	System();

	virtual void HandleMessage(Message msg) {}

	~System();
};

