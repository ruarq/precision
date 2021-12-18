#include "precision/benchmark.hpp"

namespace precision
{

benchmark::benchmark(const char *name, func fn)
	: name(name)
	, fn(fn)
{
}

auto run(const std::vector<benchmark> &benchmarks, const benchmark_config &config) -> std::vector<result>
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