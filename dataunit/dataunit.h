#pragma once

#include <boost/any.hpp>



class DataUnit
{
public:
	enum class datatype
	{
		Integer, Boolean, String, Double
	};

	DataUnit(datatype type, boost::any& value) : schema_type_(type), col_value_(value) {}

	template<typename R> R get() { return boost::any_cast<R>(col_value_); }

	bool is_empty();
	bool is_int();
	bool is_bool();
	bool is_double();
	bool is_string();

private:
	datatype schema_type_;

	boost::any col_value_;
};