#include "precision/state.hpp"

#include <iostream> // remove

namespace precision
{

state::state(const clock::duration &min_runtime)
	: min_runtime(min_runtime)
{
}

auto state::running() -> bool
{
	auto now = clock::now();

	if (first_run)
	{
		start = last = clock::now();
		first_run = false;
		return true;
	}
	else
	{
		samples.push_back(now - last);
		
		auto total_runtime = now - start;
		if (total_runtime < min_runtime)
		{
			last = clock::now();
			return true;
		}
		else
		{
			return false;
		}
	}
}

}