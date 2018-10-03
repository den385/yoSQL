#pragma once

#include <string>

#include "command/command.h"



class SQLParser
{
public:
	SQLCommand parse(const std::string& statement);
};