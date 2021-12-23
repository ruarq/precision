#include "precision/context.hpp"

namespace precision
{

context::context(const clock::duration &min_runtime)
	: min_runtime(min_runtime)
{
}

auto context::running() -> bool
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

auto context::sample_count() const -> size_t
{
	return samples.size();
}

auto context::min() const -> clock::duration
{
	return *std::min_element(samples.begin(), samples.end());
}

auto context::mean() const -> clock::duration
{
	return average(samples.begin(), samples.end());
}

auto context::max() const -> clock::duration
{
	return *std::max_element(samples.begin(), samples.end());
}

}