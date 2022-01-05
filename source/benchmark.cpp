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
	custom_time = true;
	run_duration = dur;
	return *this;
}

auto benchmark::precision(const unit u) -> benchmark&
{
	custom_precision = true;
	target_unit = u;
	return *this;
}

}