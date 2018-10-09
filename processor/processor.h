#pragma once


#include "SQLParserResult.h"




class SQLProcessor
{
public:
	void ProcessCommand(const hsql::SQLParserResult& res);
};