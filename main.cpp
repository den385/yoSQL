#include <iostream>
#include <string>
#include <sstream>

#include "engine_instance.h"
#include "parser/parser.h"



void prompt()
{
	std::cout << "db > ";
}

void read_statement(std::istream& is, std::string& s)
{
	bool got_semicolon = false;
	std::string buf;

	while(!got_semicolon)
	{
		getline(is, buf);

		size_t pos = buf.find(';');

		if (pos != std::string::npos)
		{
			buf.resize(pos + 1);
			got_semicolon = true;
		}
		else
		{
			prompt();
		}

		if (!s.empty())
			s += " ";
		s += buf;
	}
}



int main(int argc, char* argv[])
{
	std::string query;

	while (true)
	{
		prompt();

		read_statement(std::cin, query);

		bool ok = EngineInstance::instance().ProcessQuery(query);

		if (!ok)
			break;
	}

	exit(EXIT_SUCCESS);
}
