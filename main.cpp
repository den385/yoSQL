#include <iostream>
#include <string>
#include <sstream>

#include "row.h"
#include "table.h"


void prompt() { printf("db > "); }



enum MetaCommandResult
{
	META_COMMAND_EXIT,
	META_COMMAND_SUCCESS,
	META_COMMAND_UNRECOGNIZED_COMMAND
};

enum PrepareResult
{
	PREPARE_SUCCESS,
	PREPARE_SYNTAX_ERROR,
	PREPARE_UNRECOGNIZED_STATEMENT
};

enum ExecuteResult
{
	EXECUTE_SUCCESS,
	EXECUTE_TABLE_FULL
};

enum StatementType
{
	STATEMENT_INSERT,
	STATEMENT_SELECT
};



struct Statement
{
    StatementType type;

	Row row_to_insert;  // only used by insert statement
};



namespace MetaCommands
{
	const std::string exit = ".exit";
}

namespace Commands
{
	const std::string insert = "insert";
	const std::string select = "select";
}



MetaCommandResult do_meta_command(const std::string& input_buffer)
{
	if (input_buffer == MetaCommands::exit)
	{
		return META_COMMAND_EXIT;
	}
	else
	{
		return META_COMMAND_UNRECOGNIZED_COMMAND;
	}
}

PrepareResult prepare_statement(const std::string& input_buffer, Statement& statement)
{
	std::istringstream ss(input_buffer);
	std::string cmd;
	ss >> cmd;

	if (cmd == Commands::insert)
	{
		statement.type = STATEMENT_INSERT;

		uint32_t id;
		std::string username, email;

		ss >> id >> username >> email;

		statement.row_to_insert = Row(id, std::move(username), std::move(email));

		if (ss.fail())
			return PREPARE_SYNTAX_ERROR;

		return PREPARE_SUCCESS;
	}
	else if (cmd == Commands::select)
	{
		statement.type = STATEMENT_SELECT;

		return PREPARE_SUCCESS;
	}
	else
		return PREPARE_UNRECOGNIZED_STATEMENT;
}

ExecuteResult execute_insert(const Statement& statement, Table& table)
{
	if (table.num_rows >= TABLE_MAX_ROWS)
		return EXECUTE_TABLE_FULL;

	// TODO: change for:
	// TODO: table.insert(statement.row);
	auto slot = row_slot(table, table.num_rows);
	serialize_row(statement.row_to_insert, *slot.first.get(), slot.second);
	table.num_rows++;

	return EXECUTE_SUCCESS;
}

ExecuteResult execute_select(const Statement& statement, Table& table)
{
	Row row;

	for (uint32_t i = 0; i < table.num_rows; i++)
	{
		auto slot = row_slot(table, i);
		deserialize_row(*slot.first.get(), slot.second, row);
		print_row(row);
	}

	return EXECUTE_SUCCESS;
}

ExecuteResult execute_statement(const Statement& statement, Table& table)
{
	switch (statement.type)
	{
		case (STATEMENT_INSERT):
			return execute_insert(statement, table);
		case (STATEMENT_SELECT):
			return execute_select(statement, table);
	}
}



int main(int argc, char* argv[])
{
	auto table = std::make_unique<Table>();

	std::string input_buffer;

	while (true)
	{
		prompt();

		std::getline(std::cin, input_buffer);

		if (input_buffer.at(0) == '.')
		{
			auto meta_command = do_meta_command(input_buffer);

			switch (meta_command)
			{
				case (META_COMMAND_EXIT):
					exit(EXIT_SUCCESS);
				case (META_COMMAND_SUCCESS):
					continue;
				case (META_COMMAND_UNRECOGNIZED_COMMAND):
					std::cout << "Unrecognized command: " << input_buffer << std::endl;
					continue;
			}
		}

		Statement statement;
		auto prepare_result = prepare_statement(input_buffer, statement);

		switch (prepare_result)
		{
			case (PREPARE_SUCCESS):
				break;
			case (PREPARE_SYNTAX_ERROR):
				std::cout << "Syntax error. Could not parse statement." << std::endl;
				continue;
			case (PREPARE_UNRECOGNIZED_STATEMENT):
				std::cout << "Unrecognized keyword at start of '" << input_buffer << "'." << std::endl;
				continue;
		}

		switch (execute_statement(statement, *table.get()))
		{
			case (EXECUTE_SUCCESS):
				std::cout << "Executed." << std::endl;
				break;
			case (EXECUTE_TABLE_FULL):
				std::cout << "Error: Table full." << std::endl;
				break;
		}
	}
}
