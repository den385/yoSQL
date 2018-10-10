#pragma once

#include <SQLParserResult.h>
#include <sql/statements.h>



class SQLProcessor
{
public:
	void ProcessCommand(const hsql::SQLParserResult& parser_result);

private:
	void execute_select(const hsql::SelectStatement& statement);
	void execute_insert(const hsql::InsertStatement& statement);
};