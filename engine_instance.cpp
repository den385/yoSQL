#include "engine_instance.h"



EngineInstance::EngineInstance()
{
	// TODO: initialization here

	parser_ = std::make_unique<SQLParser>();
	processor_ = std::make_unique<SQLProcessor>();
}

EngineInstance::~EngineInstance()
{
	processor_.reset();
	parser_.reset();
}



bool EngineInstance::ProcessInput(const std::string& input)
{
	SQLCommand cmd = parser_->parse(input);

	if (cmd.is_exit)
		return false;

	processor_->ProcessCommand(cmd);

	return true;
}