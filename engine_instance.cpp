#include "engine_instance.h"

#include "SQLParser.h"


EngineInstance::EngineInstance()
{
	processor_ = std::make_unique<SQLProcessor>();
}

EngineInstance::~EngineInstance()
{
	processor_.reset();
}



bool EngineInstance::ProcessQuery(const std::string& query)
{
    hsql::SQLParserResult result;
    hsql::SQLParser::parse(query, &result);

    result.getStatement(0)->is(hsql::)



    if (result.isValid() && result.size() > 0) {
        const hsql::SQLStatement* statement = result.getStatement(0);

        if (statement.isType(hsql::SelectStatement)) {
            const hsql::SelectStatement* select = (const hsql::SelectStatement*) statement;
            /* ... */
        }
    }













	SQLCommand cmd = parser_->parse(input);

	if (cmd.is_exit)
		return false;

	processor_->ProcessCommand(cmd);

	return true;
}