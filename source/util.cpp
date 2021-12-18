#include "precision/util.hpp"

namespace precision
{

auto validate_unit(const std::string &unit) -> bool
{
	const auto units = { "ns", "us", "ms", "s", "min", "h", "auto" };
	for (auto other : units)
	{
		if (unit == other)
		{
			return true;
		}
	}
	
	return false;
}

auto parse_unit(const std::string &s) -> std::string
{
	const std::regex regex("^\\d\\d*(\\.\\d\\d*)?[a-z]*$");
	if (std::regex_match(s.begin(), s.end(), regex))
	{
		return s.substr(s.find_last_of("0123456789") + 1);
	}
	else
	{
		return "";
	}
}

auto parse_runtime(const std::string &s) -> int64_t
{
	const auto value = std::stof(s);
	const auto unit = parse_unit(s);

	if (!validate_unit(unit))
	{
		return std::numeric_limits<int64_t>::infinity();
	}

	if (unit == "h")
	{
		return (int64_t)(value * h_to_ns);
	}
	else if (unit == "min")
	{
		return (int64_t)(value * min_to_ns);
	}
	else if (unit == "s")
	{
		return (int64_t)(value * s_to_ns);
	}
	else if (unit == "ms")
	{
		return (int64_t)(value * ms_to_ns);
	}
	else if (unit == "us")
	{
		return (int64_t)(value * us_to_ns);
	}
	else if (unit == "ns")
	{
		return (int64_t)(value);
	}
	else
	{
		return std::numeric_limits<int64_t>::infinity();
	}
}

}