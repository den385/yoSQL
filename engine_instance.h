#pragma once

#include <memory>

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

	bool ProcessQuery(const std::string& input); // TODO: multi-threading ?

	static SQLProcessor& processor() { return *instance().processor_; }

private:
	std::unique_ptr<MetaCommandParser> parser_;
	std::unique_ptr<SQLProcessor> processor_;
};
