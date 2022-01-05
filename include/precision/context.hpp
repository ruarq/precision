#pragma once

#include <cstddef>
#include <cstdint>
#include <chrono>
#include <vector>
#include <numeric>
#include <algorithm>

#include "util.hpp"
#include "clock.hpp"
#include "benchmark_result.hpp"

namespace precision
{

class context final
{
public:
	context(const duration &min_runtime);

public:
	/**
	 * @return whether the benchmark should keep running or not
	 */
	auto running() -> bool;

	/**
	 * @brief get the result of the benchmark the context belongs to
	 */
	auto get_samples() -> std::vector<sample>;

	/**
	 * @brief pause timing
	 */
	auto pause() -> void;

	/**
	 * @brief resume timing
	 */
	auto resume() -> void;

private:
	bool first_run = true;
	std::vector<sample> samples;
	clock::time_point last, start;
	duration current_runtime;
	duration min_runtime;
	bool paused = false;
};

}