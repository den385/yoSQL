#pragma once

#include <sstream>
#include <mutex>


class Terminal
{
public:
	Terminal(std::istream& is, std::ostream& os) : is_(is), os_(os) {}

	std::string Read();
	void Write(const std::string& message);

private:
	void prompt();
	void read_statement( std::string& s);

private:
	std::istream& is_;
	std::ostream& os_;

	std::mutex read_mx;
	std::mutex write_mx;
};