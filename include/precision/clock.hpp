#pragma once

#include <chrono>

namespace precision
{

using clock = std::chrono::high_resolution_clock;
using duration = std::chrono::duration<int64_t, std::nano>;

}