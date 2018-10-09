#pragma once

#include <memory>

#include "processor/processor.h"
#include "meta_command.h"
#include "utils.h"



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

	bool ProcessQuery(const std::string& input); // TODO: multi-threading ?

	static SQLProcessor& processor() { return *instance().processor_; }

private:
	bool process_meta_command(const std::string& s_command);
	MetaCommand parse_meta_command(const std::string& s_command);

	bool open_file(const std::string& filename, bool is_new = false);

private:
	std::unique_ptr<SQLProcessor> processor_;
};
