#include <iostream>
#include <string>
#include <thread>

#include "terminal/terminal.h"
#include "engine_instance.h"



void Terminal::prompt()
{
	std::cout << "db > ";
}

void Terminal::read_statement(std::string& s)
{
	bool got_semicolon = false;
	std::string buf;

	while(!got_semicolon)
	{
		getline(is_, buf);

		if (buf[0] == '.')
		{
			s += buf;
			break;
		}

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



std::string Terminal::Read()
{
	std::string query;

	{
		std::lock_guard<std::mutex> write_lock (write_mx);
		prompt();
	}

	{
		std::lock_guard<std::mutex> read_lock (read_mx);
		read_statement(query);
	}

	return query;
}

void Terminal::Write(const std::string& message)
{
	std::lock_guard<std::mutex> write_lock (write_mx);

	os_ << message;
}