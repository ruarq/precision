#pragma once

#include <string>
#include <chrono>

#include "clock.hpp"
#include "state.hpp"

namespace precision
{

class benchmark final
{
public:
	using function = void(*)(state&);

public:
	benchmark(const std::string &name, function run, const clock::duration &runtime = std::chrono::milliseconds(100));

public:
	const std::string name;
	function run;
	clock::duration runtime;

};

}