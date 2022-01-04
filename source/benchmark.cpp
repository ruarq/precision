#include "precision/benchmark.hpp"

namespace precision
{

benchmark::benchmark(const std::string &name, function run)
	: name(name)
	, run(run)
	, run_duration(default_runtime)
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

}