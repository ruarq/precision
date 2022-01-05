#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stdexcept>

#include <getopt.h>

#include "benchmark.hpp"

namespace precision
{

auto main(std::vector<benchmark> benchmarks, const int argc = 0, char **argv = nullptr) -> int;

}