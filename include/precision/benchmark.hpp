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
	benchmark(const char *name, func fn)
		: name(name)
		, fn(fn)
	{
	}

	const char *name;
	func fn;
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

inline std::vector<result> run(const std::vector<benchmark> &benchmarks, const benchmark_config &config = benchmark_config())
{
	std::vector<result> results;
	for (auto [name, fn] : benchmarks)
	{
		int64_t total_time = 0;
		result res;
		res.name = name;

		while (total_time < config.min_runtime)
		{
			const int64_t t = time(fn);

			total_time += t;
			++res.iterations;
			
			if (t < res.min)
			{
				res.min = t;
			}
			if (t > res.max)
			{
				res.max = t;
			}
		}

		res.mean = total_time / res.iterations;
		results.push_back(res);
	}

	std::sort(results.begin(), results.end(), [](const result &a, const result &b)
	{
		return a.iterations > b.iterations;
	});

	return results;
}

}
