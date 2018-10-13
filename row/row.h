#pragma once

#include <vector>

#include "dataunit/dataunit.h"

#include <boost/serialization/access.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>



class Row
{
	friend class boost::serialization::access;

public:
	Row() {};
	Row(const std::vector<DataUnit>& units) : units_(units) {};

private:
	template<class Archive>
    void serialize(Archive& ar, const unsigned int version = 0);

private:
	std::vector<DataUnit> units_;
};



template<class Archive>
void Row::serialize(Archive& ar, const unsigned int version)
{
	for (auto& unit : units_)
	{
		if (unit.is_int())
		{
			ar & unit.get<int>();
		}
		else if (unit.is_double())
		{
			ar & unit.get<double>();
		}
		else if (unit.is_bool())
		{
			ar & unit.get<bool>();
		}
		else if (unit.is_string())
		{
			ar & unit.get<std::string>();
		}
		else
		{
			ar & 0;
		}
	}
}