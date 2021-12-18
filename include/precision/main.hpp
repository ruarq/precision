#pragma once

#include <iostream>
#include <getopt.h>

#include "benchmark.hpp"
#include "write_formatted.hpp"
#include "util.hpp"

namespace precision
{

auto main(int argc, char **argv, const std::vector<benchmark> &benchmarks) -> int;

}
