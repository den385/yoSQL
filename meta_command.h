#pragma once

#include <vector>
#include <string>



enum class MetaCommandType
{
  MC_QUIT_OR_EXIT,
  MC_OPEN_FILE,                     // has option --new
  MC_UNRECOGNIZED_COMMAND
};

struct MetaCommand
{
	MetaCommandType type;

	std::vector<std::string> args;
};