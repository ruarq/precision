#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <array>
#include <algorithm>

#include <precision/precision.hpp>

#define ELEMENT_COUNT 10000
#define ELEMENT_MAX_VALUE 1000

auto benchmarks = {
	/**
	 * vector-sort
	 */
	precision::benchmark {
		"vector-sort",
		[](auto &ctx) {
			std::srand(std::time(nullptr));

			while (ctx.running())
			{
				ctx.pause();
				std::vector<int> v;
				for (int i = 0; i < ELEMENT_COUNT; ++i)
				{
					v.push_back(std::rand() % (ELEMENT_MAX_VALUE + 1));
				}
				ctx.resume();

				std::sort(v.begin(), v.end());
			}
		}
	},

	/**
	 * list-sort
	 */
	precision::benchmark {
		"list-sort",
		[](auto &ctx) {
			std::srand(std::time(nullptr));

			while (ctx.running())
			{
				ctx.pause();
				std::list<int> l;
				for (int i = 0; i < ELEMENT_COUNT; ++i)
				{
					l.push_back(std::rand() % (ELEMENT_MAX_VALUE + 1));
				}
				ctx.resume();

				l.sort();
			}
		}
	},

	/**
	 * deque-sort
	 */
	precision::benchmark {
		"deque-sort",
		[](auto &ctx) {
			std::srand(std::time(nullptr));

			while (ctx.running())
			{
				ctx.pause();
				std::deque<int> d;
				for (int i = 0; i < ELEMENT_COUNT; ++i)
				{
					d.push_back(std::rand() % (ELEMENT_MAX_VALUE + 1));
				}
				ctx.resume();

				std::sort(d.begin(), d.end());
			}
		}
	},

	/**
	 * forward-list-sort
	 */
	precision::benchmark {
		"forward-list-sort",
		[](auto &ctx) {
			std::srand(std::time(nullptr));

			while (ctx.running())
			{
				ctx.pause();
				std::forward_list<int> fl;
				for (int i = 0; i < ELEMENT_COUNT; ++i)
				{
					fl.push_front(std::rand() % (ELEMENT_MAX_VALUE + 1));
				}
				ctx.resume();

				fl.sort();
			}
		}
	},

	/**
	 * array-sort
	 */
	precision::benchmark {
		"array-sort",
		[](auto &ctx) {
			std::srand(std::time(nullptr));

			while (ctx.running())
			{
				ctx.pause();
				std::array<int, ELEMENT_COUNT> a;
				for (int &i : a)
				{
					i = std::rand() % (ELEMENT_MAX_VALUE + 1);
				}
				ctx.resume();

				std::sort(a.begin(), a.end());
			}
		}
	}
};

auto main() -> int
{
	return precision::main(benchmarks);
}