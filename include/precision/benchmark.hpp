#pragma once

#include <string>

#include "state.hpp"

namespace precision
{

class benchmark final
{
public:
	using function = void(*)(state&);

public:
	benchmark(const std::string &name, function run);

public:
	const std::string name;
	function run;
};

}