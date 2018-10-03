#pragma once



namespace MetaCommands
{
	const std::string exit = ".exit";
	const std::string quit = ".quit";
	const std::String open = ".open";
}



struct MetaCommand
{
	bool is_exit {false};
};



class MetaCommandParser
{
	void parse(query);
};