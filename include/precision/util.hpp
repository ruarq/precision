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

template <class T>
auto dont_optimize(T& value) -> void
{
	#if not defined(__clang__)
		asm volatile("" : "+m,r"(value) : : "memory");
	#else
		asm volatile("" : "+r,m"(value) : : "memory");
	#endif
}


}