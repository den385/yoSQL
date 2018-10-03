#include "meta_command_parser/meta_command_parser.h"





//enum PrepareResult
//{
//	PREPARE_SUCCESS,
//	PREPARE_SYNTAX_ERROR,
//	PREPARE_UNRECOGNIZED_STATEMENT
//};
//
//
//enum StatementType
//{
//	STATEMENT_INSERT,
//	STATEMENT_SELECT
//};
//
//
//
//struct Statement
//{
//	StatementType type;
//
//	Row row_to_insert;  // only used by insert statement
//};
//
//
//

//
//namespace Commands
//{
//	const std::string insert = "insert";
//	const std::string select = "select";
//}
//
//
//
//
//
//PrepareResult prepare_statement(const std::string& input_buffer, Statement& statement)
//{
//	std::istringstream ss(input_buffer);
//	std::string cmd;
//	ss >> cmd;
//
//	if (cmd == Commands::insert)
//	{
//		statement.type = STATEMENT_INSERT;
//
//		uint32_t id;
//		std::string username, email;
//
//		ss >> id >> username >> email;
//
//		statement.row_to_insert = Row(id, std::move(username), std::move(email));
//
//		if (ss.fail())
//			return PREPARE_SYNTAX_ERROR;
//
//		return PREPARE_SUCCESS;
//	}
//	else if (cmd == Commands::select)
//	{
//		statement.type = STATEMENT_SELECT;
//
//		return PREPARE_SUCCESS;
//	}
//	else
//		return PREPARE_UNRECOGNIZED_STATEMENT;
//}



SQLCommand SQLParser::parse(const std::string& statement)
{
	return SQLCommand {true};

//	if (statement.at(0) == '.')
//	{
//		auto meta_command_parser = do_meta_command(input_buffer);
//
//		switch (meta_command_parser)
//		{
//			case (META_COMMAND_EXIT):
//				exit(EXIT_SUCCESS);
//			case (META_COMMAND_SUCCESS):
//				continue;
//			case (META_COMMAND_UNRECOGNIZED_COMMAND):
//				std::cout << "Unrecognized command: " << input_buffer << std::endl;
//				continue;
//		}
//	}
//
//	Statement statement;
//	auto prepare_result = prepare_statement(statement, statement);
//
//	switch (prepare_result)
//	{
//		case (PREPARE_SUCCESS):
//			break;
//		case (PREPARE_SYNTAX_ERROR):
//			std::cout << "Syntax error. Could not parse statement." << std::endl;
//			continue;
//		case (PREPARE_UNRECOGNIZED_STATEMENT):
//			std::cout << "Unrecognized keyword at start of '" << input_buffer << "'." << std::endl;
//			continue;
//	}
//
//	switch (execute_statement(statement, *table.get()))
//	{
//		case (EXECUTE_SUCCESS):
//			std::cout << "Executed." << std::endl;
//			break;
//		case (EXECUTE_TABLE_FULL):
//			std::cout << "Error: Table full." << std::endl;
//			break;
//	}
}