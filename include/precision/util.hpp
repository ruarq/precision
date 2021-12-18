#pragma once

#include <string>
#include <initializer_list>

namespace precision
{

/**
 * @brief check if a string is a supported unit
 */
auto validate_unit(const std::string &unit) -> bool;

}