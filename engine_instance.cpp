#include <iostream>

#include "engine_instance.h"

#include "SQLParser.h"
#include "boost/system/error_code.hpp"
#include "boost/algorithm/string.hpp"



EngineInstance::EngineInstance()
{
	processor_ = std::make_unique<SQLProcessor>();
	terminal_ = std::make_unique<Terminal>(std::cin, std::cout);
}

EngineInstance::~EngineInstance()
{
	if (qdb_file_.is_open())
		qdb_file_.close();

	terminal_.reset();
	processor_.reset();
}



bool EngineInstance::Run()
{
	while (true)
	{
		std::string query = terminal_->Read();

		if(!process_query(query))
			break;
	}
}



bool EngineInstance::process_query(const std::string& query)
{
	if (query.at(0) == '.')
		return process_meta_command(query);

	hsql::SQLParserResult result;
	hsql::SQLParser::parse(query, &result);

	if (result.isValid() && result.size() > 0)
		processor_->ProcessCommand(result);
	else
		return false;

	return true;
}



bool EngineInstance::open_file(const std::string& filepath, bool is_new)
{
	if (qdb_file_.is_open())
		qdb_file_.close();

	if (is_new)
		qdb_file_.open(filepath, std::ios::in);
	else
		qdb_file_.open(filepath);

	// qdb_file_ << "Writing this to a file.\n";
	// TODO: pager.reset(f) ?
	// reset pages, rows, tables etc.

	return true;
}



bool EngineInstance::process_meta_command(const std::string& s_command)
{
	MetaCommand meta_cmd = parse_meta_command(s_command);

	switch(meta_cmd.type)
	{
		case (MetaCommandType::MC_QUIT_OR_EXIT):
		{
			return false;
		}
		case (MetaCommandType::MC_OPEN_FILE):
		{
			if (meta_cmd.args.at(0) == "--new" && meta_cmd.args.size() == 2)
				open_file(meta_cmd.args.at(1), true);                               // open new file
			else if (meta_cmd.args.size() == 2)
				open_file(meta_cmd.args.at(0));                                     // open existing file

			break;
		}
		case (MetaCommandType::MC_UNRECOGNIZED_COMMAND):
		{
			return true;
		}
	}

	return true;
}

MetaCommand EngineInstance::parse_meta_command(const std::string& s_command)
{
	MetaCommand meta_cmd;

	std::vector<std::string> strs;
	boost::split(strs, s_command, boost::is_any_of(" "));

	if (s_command == ".exit" || s_command == ".quit")
	{
		meta_cmd = { MetaCommandType::MC_QUIT_OR_EXIT, {} };
	}
	else if (s_command == ".open")
	{
		std::vector<std::string> args;
		std::move(strs.begin() + 1, strs.end(), args.begin());

		meta_cmd = { MetaCommandType::MC_OPEN_FILE, std::move(args) };
	}
	else
	{
		meta_cmd = { MetaCommandType::MC_UNRECOGNIZED_COMMAND, {} };
	}

	return meta_cmd;
}