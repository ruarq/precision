#pragma once

#include <cstdint>
#include <chrono>

namespace precision
{

static constexpr int64_t us_to_ns		= 1'000;
static constexpr int64_t ms_to_ns		= 1'000 * us_to_ns;
static constexpr int64_t s_to_ns		= 1'000 * ms_to_ns;
static constexpr int64_t min_to_ns		= 60 * s_to_ns;
static constexpr int64_t h_to_ns		= 60 * min_to_ns;

static constexpr float ns_to_us			= 1.0f / (float)(us_to_ns);
static constexpr float ns_to_ms			= 1.0f / (float)(ms_to_ns);
static constexpr float ns_to_s			= 1.0f / (float)(s_to_ns);
static constexpr float ns_to_min		= 1.0f / (float)(min_to_ns);
static constexpr float ns_to_h			= 1.0f / (float)(h_to_ns);

/**
 * @brief time the runtime of a function
 */
template<typename Fn, typename... Args>
int64_t time(Fn fn, Args&&... args)
{
	auto start = std::chrono::high_resolution_clock::now();
	fn(args...);
	auto end = std::chrono::high_resolution_clock::now();

	return (end - start).count();
}

}
