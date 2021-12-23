#include "precision/benchmark.hpp"

namespace precision
{

benchmark::benchmark(const std::string &name, function run)
	: name(name)
	, run(run)
	, runtime(default_runtime)
{
}

benchmark::benchmark(const std::string &name, function run, const benchmark_config &cfg)
	: name(name)
	, run(run)
	, runtime(cfg.runtime)
{
}

}