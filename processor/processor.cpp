#include "processor/processor.h"
#include "engine_instance.h"
#include "row/row.h"

#include <sql/Expr.h>
#include <boost/serialization/vector.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>



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
	std::vector<hsql::Expr*>* expr_list = select_statement.selectList;

	EngineInstance::terminal().Write("Got this\n");
	EngineInstance::terminal().Write("\tselect ");

	for(auto& e : *expr_list)
	{
		if (e->getName())
			EngineInstance::terminal().Write(e->name);

		if (e->type == hsql::ExprType::kExprStar)
			EngineInstance::terminal().Write("*");
	}

	std::string table_name = select_statement.fromTable->getName();
	std::string s = " from " + table_name + ";\n";
	EngineInstance::terminal().Write(s);



	std::ostringstream ss;

	std::vector<DataUnit> units;
	boost::any v = 123;
	DataUnit u(DataUnit::datatype::Integer, v);
	units.push_back(u);
	Row r(units);

	{
		boost::archive::text_oarchive oa(ss);

		oa << r;
	}

	EngineInstance::terminal().Write(ss.str());


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