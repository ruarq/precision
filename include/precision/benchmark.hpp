#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <limits>
#include <algorithm>
#include <vector>

#include "time.hpp"

namespace precision
{

using func = void(*)();
struct result;

struct benchmark_config final
{
	std::string unit = "ns";				///< time unit {ns,ms,s,min,h}
	int64_t min_runtime = 0.5 * s_to_ns;	///< min runtime in nanoseconds
};

/**
 * @brief used to register and create benchmarks
 */
struct benchmark final
{
	benchmark(const char *name, func run);

	const char *name;
	func run;
};

/**
 * @brief stores the result of a benchmark
 */
struct result final
{
	const char *name = nullptr;
	int64_t min = std::numeric_limits<int64_t>::max();	///< min runtime of a function in nanoseconds
	int64_t mean = 0;									///< mean runtime of a function in nanoseconds
	int64_t max = std::numeric_limits<int64_t>::min();	///< max runtime of a function in nanoseconds
	size_t iterations = 0;
};

auto run(const std::vector<benchmark> &benchmarks, const benchmark_config &config = benchmark_config()) -> std::vector<result>;

}
