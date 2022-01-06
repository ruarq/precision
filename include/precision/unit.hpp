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

/**
 * @brief convert a unit from a string
 * @param s the string
 * @return appropriate unit or unit::none if the string does not contain a valid unit
 */
auto from_string(const std::string &s) -> unit;

/**
 * @brief convert a unit to a string
 * @param u the unit to convert
 * @return unit as string; throws if u is not valid
 */
auto to_string(const unit u) -> std::string;

}