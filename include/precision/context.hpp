#pragma once

#include <cstddef>
#include <cstdint>
#include <chrono>
#include <vector>
#include <numeric>
#include <algorithm>

#include "util.hpp"
#include "clock.hpp"

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
	 * @brief get the sample count of the benchmark
	 */
	auto sample_count() const -> size_t;

	/**
	 * @brief get the minimum sample
	 */
	auto min() const -> duration;

	/**
	 * @brief get the mean sample
	 */
	auto mean() const -> duration;

	/**
	 * @brief get the maximum sample
	 */
	auto max() const -> duration;

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
	std::vector<duration> samples;
	clock::time_point last, start;
	duration current_runtime;
	duration min_runtime;
	bool paused = false;
};

}