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
	context(const clock::duration &min_runtime);

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
	auto min() const -> clock::duration;

	/**
	 * @brief get the mean sample
	 */
	auto mean() const -> clock::duration;

	/**
	 * @brief get the maximum sample
	 */
	auto max() const -> clock::duration;

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
	std::vector<clock::duration> samples;
	clock::time_point last, start;
	clock::duration current_runtime;
	clock::duration min_runtime;
	bool paused = false;
};

}