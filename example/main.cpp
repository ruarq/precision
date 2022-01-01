#include <vector>
#include <algorithm>

#include <precision/precision.hpp>

auto benchmarks = {
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
	}.time(std::chrono::seconds(10))
};

auto main() -> int
{
	return precision::main(benchmarks);
}