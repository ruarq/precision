#pragma once

#include <cstdint>
#include <chrono>
#include <vector>
#include <numeric>

#include "clock.hpp"

namespace precision
{

class state final
{
public:
	state(const clock::duration &min_runtime);

public:
	/**
	 * @return whether the benchmark should keep running or not
	 */
	auto running() -> bool;

//private:
	bool first_run = true;
	std::vector<clock::duration> samples;
	clock::time_point last, start;
	clock::duration min_runtime;
};

}