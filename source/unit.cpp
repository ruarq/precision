#include "precision/unit.hpp"

namespace precision
{

auto from_string(const std::string &s) -> unit
{
	if (s == "ns")
	{
		return unit::ns;
	}
	else if (s == "us")
	{
		return unit::us;
	}
	else if (s == "ms")
	{
		return unit::ms;
	}
	else if (s == "s")
	{
		return unit::s;
	}
	else if (s == "min")
	{
		return unit::min;
	}
	else if (s == "h")
	{
		return unit::h;
	}
	else
	{
		return unit::none;
	}
}

auto to_string(const unit u) -> std::string
{
	switch (u)
	{
		case unit::ns:	return "ns";
		case unit::us:	return "us";
		case unit::ms:	return "ms";
		case unit::s:	return "s";
		case unit::min:	return "min";
		case unit::h:	return "h";

		case unit::none:
		default:
			throw std::runtime_error("precision::to_string() : invalid unit");
	}
}

}