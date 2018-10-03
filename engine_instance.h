#pragma once

#include <memory>

#include "parser/parser.h"
#include "processor/processor.h"
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

	bool ProcessInput(const std::string& input); // TODO: multi-threading ?

	static SQLParser& parser() { return *instance().parser_; }
	static SQLProcessor& processor() { return *instance().processor_; }

private:
	std::unique_ptr<SQLParser> parser_;
	std::unique_ptr<SQLProcessor> processor_;
};
