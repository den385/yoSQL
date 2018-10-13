#include "dataunit.h"



bool DataUnit::is_empty()
{
	return col_value_.empty();
}

bool DataUnit::is_int()
{
	return col_value_.type() == typeid(int);
}

bool DataUnit::is_bool()
{
	return col_value_.type() == typeid(bool);
}

bool DataUnit::is_double()
{
	return col_value_.type() == typeid(double);
}

bool DataUnit::is_string()
{
	try
	{
		boost::any_cast<std::string>(&col_value_);
		return true;
	}
	catch (const boost::bad_any_cast&)
	{
		return false;
	}
}
