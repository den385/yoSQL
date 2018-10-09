#pragma once

#include <memory>
#include <fstream>

#include "processor/processor.h"
#include "meta_command.h"
#include "utils.h"
#include "terminal/terminal.h"



class EngineInstance
{
	DECLARE_NONCOPYABLE(EngineInstance)

	EngineInstance();
	~EngineInstance();

public:
	static EngineInstance& instance()
	{
		static EngineInstance instance;
		return instance;
	}

	bool Run();

	static SQLProcessor& processor() { return *instance().processor_; }
	static Terminal& terminal() { return *instance().terminal_; }

private:
	bool process_query(const std::string& input);                           // TODO: multi-threading

	bool process_meta_command(const std::string& s_command);
	MetaCommand parse_meta_command(const std::string& s_command);

	bool open_file(const std::string& filepath, bool is_new = false);       // TODO: add directory choice

private:
	std::fstream qdb_file_;

	std::unique_ptr<SQLProcessor> processor_;
	std::unique_ptr<Terminal> terminal_;
};
