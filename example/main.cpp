#include <vector>
#include <list>
#include <algorithm>

#include <precision/precision.hpp>

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
				for (int i = 0; i < 10000; ++i)
				{
					v.push_back(std::rand() % 1000);
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
				for (int i = 0; i < 10000; ++i)
				{
					l.push_back(std::rand() % 1000);
				}
				ctx.resume();

				l.sort();
			}
		}
	}
};

auto main() -> int
{
	return precision::main(benchmarks);
}