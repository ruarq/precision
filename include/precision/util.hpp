#pragma once

#include <string>
#include <initializer_list>

namespace precision
{

/**
 * @brief check if a string is a supported unit
 */
inline bool validate_unit(const std::string &unit)
{
	auto units = { "ns", "us", "ms", "s", "min", "h", "auto" };
	for (auto other : units)
	{
		if (unit == other)
		{
			return true;
		}
	}
	
	return false;
}

}