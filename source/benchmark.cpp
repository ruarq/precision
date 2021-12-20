#include "precision/benchmark.hpp"

namespace precision
{

benchmark::benchmark(const std::string &name, function run)
	: name(name)
	, run(run)
{
}

}