#pragma once

#include <string>
#include <chrono>

#include "clock.hpp"
#include "state.hpp"

namespace precision
{

static constexpr auto default_runtime = std::chrono::seconds(1);

struct benchmark_config final
{
	clock::duration runtime = default_runtime;
};

class benchmark final
{
public:
	using function = void(*)(state&);

public:
	benchmark(const std::string &name, function run);
	benchmark(const std::string &name, function run, const benchmark_config &cfg);

public:
	const std::string name;
	function run;
	clock::duration runtime;

};

}