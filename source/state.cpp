#include "precision/state.hpp"

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

auto state::sample_count() const -> size_t
{
	return samples.size();
}

auto state::min() const -> clock::duration
{
	return *std::min_element(samples.begin(), samples.end());
}

auto state::mean() const -> clock::duration
{
	return average(samples.begin(), samples.end());
}

auto state::max() const -> clock::duration
{
	return *std::max_element(samples.begin(), samples.end());
}

}