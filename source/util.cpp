#include "precision/util.hpp"

namespace precision
{

auto validate_unit(const std::string &unit) -> bool
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