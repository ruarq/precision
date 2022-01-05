#include "precision/context.hpp"

namespace precision
{

context::context(const duration &min_runtime)
	: current_runtime(std::chrono::nanoseconds(0))
	, min_runtime(min_runtime)
{
}

auto context::running() -> bool
{
	auto now = clock::now();

	if (first_run)
	{
		first_run = false;
		start = last = clock::now();
		return true;
	}
	else
	{
		current_runtime += now - last;
		samples.push_back(sample{current_runtime});
		
		auto total_runtime = now - start;
		if (total_runtime < min_runtime)
		{
			current_runtime = std::chrono::nanoseconds(0);
			last = clock::now();
			return true;
		}
		else
		{
			return false;
		}
	}
}

auto context::get_samples() -> std::vector<sample>
{
	return samples;
}

auto context::pause() -> void
{
	auto now = clock::now();
	if (!paused)
	{
		current_runtime += now - last;
		paused = true;
	}
}

auto context::resume() -> void
{
	if (paused)
	{
		paused = false;
		last = clock::now();
	}
}

}