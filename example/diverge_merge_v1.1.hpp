#pragma once

#include <cstdint>
#include <vector>
#include <list>

template<typename Cont>
auto diverge_merge_sort_v1_1_cont(Cont &cont) -> void
{
	using T = typename Cont::value_type;

	auto first = cont.front();
	cont.erase(cont.begin());
	std::list<T> vec(cont.begin(), cont.end());

	cont.clear();
	cont.insert(cont.begin(), first);

	while (!vec.empty())
	{
		std::list<T> sub;
		auto prev = vec.front();
		for (auto itr = vec.begin(); itr != vec.end();)
		{
			if (*itr >= prev)
			{
				prev = *itr;
				sub.push_back(*itr);
				itr = vec.erase(itr);
			}
			else
			{
				++itr;
			}
		}

		auto elem = sub.begin();
		auto itr = cont.begin();
		while (elem != sub.end())
		{
			while (itr != cont.end() && *elem > *itr)
			{
				++itr;
			}

			itr = cont.insert(itr, *elem);
			++elem;
		}
	}
}

template<typename Iter>
auto diverge_merge_sort_v1_1(Iter begin, Iter end) -> void
{
	std::list<typename Iter::value_type> v(begin, end);
	diverge_merge_sort_v1_1_cont(v);
	std::copy(v.begin(), v.end(), begin);
}
