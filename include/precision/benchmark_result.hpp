#pragma once

#include <vector>
#include <string>
#include <ostream>
#include <iomanip>
#include <algorithm>

#include "clock.hpp"
#include "sample.hpp"
#include "util.hpp"
#include "unit.hpp"

namespace precision
{

class benchmark_result final
{
public:
	std::string name;
	unit target_unit;
	std::vector<sample> samples;
};

/**
 * @brief write the benchmark results to out
 * @param out the std::ostream& to write the results to
 * @param results the benchmark results
 */
auto write_results_pretty(std::ostream &out, const std::vector<benchmark_result> &results) -> void;

}