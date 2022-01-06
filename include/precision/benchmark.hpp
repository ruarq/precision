#pragma once

#include <string>
#include <chrono>

#include "clock.hpp"
#include "context.hpp"
#include "unit.hpp"

namespace precision
{

class benchmark final
{
public:
	using function = void(*)(context&);

public:
	/**
	 * @brief construct a benchmark from a name and a function
	 */
	benchmark(const std::string &name, function bench_fn);

public:
	/**
	 * @brief change the run duration of the benchmark
	 * @param dur the run durations
	 */
	auto time(const duration &dur) -> benchmark&;

	/**
	 * @brief change the precision/unit that will be written in the results
	 * @note TODO(ruarq): do we really need this function?
	 */
	auto precision(const unit u) -> benchmark&;

public:
	const std::string name;
	function bench_fn;
	duration run_duration = std::chrono::seconds(1);
	unit target_unit = unit::ns;
};

}