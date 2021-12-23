#pragma once

#include <iterator>

namespace precision
{

template<typename Iter>
auto average(Iter begin, Iter end)
{
	auto sum = *begin;
	auto size = std::distance(begin, end);

	for (; begin != end; ++begin)
	{
		sum += *begin;
	}

	return sum / size;
}

}