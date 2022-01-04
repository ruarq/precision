#pragma once

#include <string>
#include <stdexcept>
#include <chrono>

namespace precision
{

enum class unit
{
	none,
	ns, us, ms, s, min, h
};

auto from_string(const std::string &s) -> unit;
auto to_string(const unit u) -> std::string;

}