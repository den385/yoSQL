#include "processor/processor.h"



void SQLProcessor::ProcessCommand(const hsql::SQLParserResult& sql_cmd)
{
	const hsql::SQLStatement* statement = sql_cmd.getStatement(0);

	if (statement->isType(hsql::StatementType::kStmtSelect))
	{
		auto select = dynamic_cast<const hsql::SelectStatement*>(statement);
		execute_select(*select);
	}
	else if (statement->isType(hsql::StatementType::kStmtInsert))
	{
		auto insert = dynamic_cast<const hsql::InsertStatement*>(statement);
		execute_insert(*insert);
	}
}



void SQLProcessor::execute_select(const hsql::SelectStatement& select_statement)
{
	auto expr_list = select_statement.selectList;
	auto table = select_statement.fromTable;
	auto table_name = table->name;
	auto table_schema = table->schema;



//	Row row;
//
//	for (uint32_t i = 0; i < table.num_rows; i++)
//	{
//		auto slot = row_slot(table, i);
//		deserialize_row(*slot.first.get(), slot.second, row);
//		print_row(row);
//	}
//
//	return EXECUTE_SUCCESS;
}

void SQLProcessor::execute_insert(const hsql::InsertStatement& insert_statement)
{
//	if (table.num_rows >= TABLE_MAX_ROWS)
//		return EXECUTE_TABLE_FULL;
//
//	// TODO: change for:
//	// TODO: table.insert(statement.row);
//	auto slot = row_slot(table, table.num_rows);
//	serialize_row(statement.row_to_insert, *slot.first.get(), slot.second);
//	table.num_rows++;
//
//	return EXECUTE_SUCCESS;
}



//enum ExecuteResult
//{
//	EXECUTE_SUCCESS,
//	EXECUTE_TABLE_FULL
//};
//
//enum MetaCommandResult
//{
//	META_COMMAND_EXIT,
//	META_COMMAND_SUCCESS,
//	META_COMMAND_UNRECOGNIZED_COMMAND
//};




//MetaCommandResult do_meta_command(const std::string& input_buffer)
//{
//	if (input_buffer == MetaCommands::exit)
//	{
//		return META_COMMAND_EXIT;
//	}
//	else
//	{
//		return META_COMMAND_UNRECOGNIZED_COMMAND;
//	}
//}