#pragma once

#include "benchmark.hpp"
#include "benchmark_result.hpp"

namespace precision
{

auto run_benchmark(benchmark &bench) -> benchmark_result;
auto run_benchmarks(std::vector<benchmark> benchmarks) -> std::vector<benchmark_result>;
auto run_empty_bench() -> benchmark_result;

}