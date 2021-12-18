#pragma once

#include <ostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>

#include "benchmark.hpp"
#include "time.hpp"

namespace precision
{

/**
 * @brief formats time in ns to be printed by write_formatted in @a unit
 */
auto format_time(const int64_t ns, std::string unit) -> std::string;

/**
 * @brief write a table of the results to out
 */
auto write_formatted(std::ostream &out, const std::vector<result> &results, const benchmark_config &config = benchmark_config()) -> std::ostream&;

}