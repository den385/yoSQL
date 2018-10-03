#pragma once

#include "command/command.h"



class SQLProcessor
{
public:
	void ProcessCommand(const SQLCommand& cmd);
};