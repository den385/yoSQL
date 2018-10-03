#include "processor/processor.h"



void SQLProcessor::ProcessCommand(const SQLCommand& cmd)
{
	// TODO: switch .meta-cmd vs sql-cmd
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
//
//
//
//
//ExecuteResult execute_insert(const Statement& statement, Table& table)
//{
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
//}
//
//ExecuteResult execute_select(const Statement& statement, Table& table)
//{
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
//}
//
//ExecuteResult execute_statement(const Statement& statement, Table& table)
//{
//	switch (statement.type)
//	{
//		case (STATEMENT_INSERT):
//			return execute_insert(statement, table);
//		case (STATEMENT_SELECT):
//			return execute_select(statement, table);
//	}
//}
//
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