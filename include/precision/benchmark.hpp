#pragma once

#include <string>
#include <chrono>

#include "clock.hpp"
#include "context.hpp"

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
	auto time(const clock::duration &dur) -> benchmark&;

public:
	const std::string name;
	function run;
	clock::duration run_duration;
};

}