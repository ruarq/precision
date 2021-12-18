#pragma once

#include <string>
#include <initializer_list>
#include <regex>
#include <limits>

#include "time.hpp"

namespace precision
{

/**
 * @brief check if a string is a supported unit
 */
auto validate_unit(const std::string &unit) -> bool;

/**
 * @brief parse a unit from a string.
 * the format of @p s is expected to match the regex /^\d\d*(\.\d\d*)?[a-z]*$/g
 */
auto parse_unit(const std::string &s) -> std::string;

/**
 * @brief takes any "time string" and returns the given time in nanoseconds
 * @return time in ns or infinity if @p s is not valid
 */
auto to_ns(const std::string &s) -> int64_t;

}