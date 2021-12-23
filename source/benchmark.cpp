#include "precision/benchmark.hpp"

namespace precision
{

benchmark::benchmark(const std::string &name, function run, const clock::duration &runtime)
	: name(name)
	, run(run)
	, runtime(runtime)
{
}

}