#pragma once

#include <string>
#include <chrono>

#include "clock.hpp"
#include "context.hpp"
#include "unit.hpp"

namespace precision
{

static constexpr auto default_runtime = std::chrono::seconds(1);

class benchmark final
{
public:
	using function = void(*)(context&);

public:
	benchmark(const std::string &name, function run);

public:
	auto time(const duration &dur) -> benchmark&;
	auto precision(const unit u) -> benchmark&;

public:
	const std::string name;
	function run;
	duration run_duration = default_runtime;
	unit target_unit = unit::ns;

	bool custom_time = false;
	bool custom_precision = false;
};

}