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
	std::vector<sample> samples;
	unit target_unit;
};

auto write_results(std::ostream &out, const std::vector<benchmark_result> &results) -> void;

}