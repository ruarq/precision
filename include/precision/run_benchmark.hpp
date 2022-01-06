#pragma once

#include "benchmark.hpp"
#include "benchmark_result.hpp"

namespace precision
{

/**
 * @brief run a specific benchmark directly and get the results for it
 * @param bench the benchmark to benchmark
 * @return benchmark_result containing the results of the benchmark
 */
auto run_benchmark(benchmark &bench) -> benchmark_result;

/**
 * @brief run benchmarks directly and get a list of results for them
 * @param benchmarks the benchmarks to run
 * @return vector of benchmark_result
 */
auto run_benchmarks(std::vector<benchmark> benchmarks) -> std::vector<benchmark_result>;

/**
 * @brief run a empty benchmark for 1 second. used to ramp up processor speeds.
 */
auto run_empty_bench() -> benchmark_result;

}