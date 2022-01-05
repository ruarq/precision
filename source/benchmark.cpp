#include "precision/benchmark.hpp"

namespace precision
{

benchmark::benchmark(const std::string &name, function run)
	: name(name)
	, run(run)
{
}

auto benchmark::time(const duration &dur) -> benchmark&
{
	run_duration = dur;
	return *this;
}

auto benchmark::precision(const unit u) -> benchmark&
{
	target_unit = u;
	return *this;
}

auto run_benchmark(benchmark &bench) -> benchmark_result
{
	context ctx(bench.run_duration);
	bench.run(ctx);

	auto samples = ctx.get_samples();
	return {
		.name = bench.name,
		.target_unit = bench.target_unit,
		.samples = samples
	};
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