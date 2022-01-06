#include "precision/run_benchmark.hpp"

namespace precision
{

auto run_benchmark(benchmark &bench) -> benchmark_result
{
	context ctx(bench.run_duration);
	bench.bench_fn(ctx);

	auto samples = ctx.get_samples();
	return {
		.name = bench.name,
		.target_unit = bench.target_unit,
		.samples = samples
	};
}

auto run_benchmarks(std::vector<benchmark> benchmarks) -> std::vector<benchmark_result>
{
	std::vector<benchmark_result> results;

	// warm up the processor
	run_empty_bench();

	for (auto &bench : benchmarks)
	{
		results.push_back(run_benchmark(bench));
	}

	return results;
}

auto run_empty_bench() -> benchmark_result
{
	benchmark empty{
		"empty",
		[](auto &ctx) {
			while (ctx.running());
		}
	};

	return run_benchmark(empty);
}

}