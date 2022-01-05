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
	benchmark(const std::string &name, function run);

public:
	auto time(const duration &dur) -> benchmark&;
	auto precision(const unit u) -> benchmark&;

public:
	const std::string name;
	function run;
	duration run_duration = std::chrono::seconds(1);
	unit target_unit = unit::ns;
};

}