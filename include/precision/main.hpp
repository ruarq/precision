#pragma once

#include <vector>

#include "benchmark.hpp"

namespace precision
{

auto main(int argc, char **argv, const std::vector<benchmark> &benchmarks) -> int;

}