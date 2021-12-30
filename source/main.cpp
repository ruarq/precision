#include "precision/main.hpp"

namespace precision
{

auto main(const std::vector<benchmark> &benchmarks) -> int
{
	// find the benchmark with the longest name
	auto maxw = std::max_element(benchmarks.begin(), benchmarks.end(), [](const benchmark &a, const benchmark &b)
	{
		return a.name.size() < b.name.size();
	})->name.size();

	// maxw only >= 15
	maxw = std::max(maxw, (size_t)(15));

	std::cout << std::setw(maxw) << "Benchmark";
	std::cout << std::setw(20) << "Min";
	std::cout << std::setw(20) << "Mean";
	std::cout << std::setw(20) << "Max";
	std::cout << std::setw(15) << "Samples";
	std::cout << "\n";

	for (auto &[name, run, runtime] : benchmarks)
	{
		context ctx(runtime);
		run(ctx);

		auto min = ctx.min();
		auto mean = ctx.mean();
		auto max = ctx.max();

		std::cout << std::setw(maxw) << name;
		std::cout << std::setw(20) << min.count();
		std::cout << std::setw(20) << mean.count();
		std::cout << std::setw(20) << max.count();
		std::cout << std::setw(15) << ctx.sample_count();
		std::cout << "\n";
	}

	return 0;
}

}