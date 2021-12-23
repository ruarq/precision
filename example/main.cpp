#include <vector>
#include <list>

#include <precision/precision.hpp>

auto random_float(uint32_t max) -> float
{
	return (float)(((float)(std::rand() % max) / (float)(max)) * max);
}

auto round_math(float num) -> float
{
	const int64_t a = num;
	const float decimal = num - (float)(a);
	return (float)(a) + (decimal >= 0.5f ? 1.0f : 0.0f);
}

auto benchmarks = {
	precision::benchmark {
		"list-insert",
		[](auto &s) {
			std::list<int> l;
			while (s.running())
			{
				l.insert(l.end(), 69);
			}
		}
	},

	precision::benchmark {
		"vector-insert",
		[](auto &s)
		{
			std::vector<int> v;
			while (s.running())
			{
				v.insert(v.end(), 420);
			}
		}
	}
};

auto main() -> int
{
	std::srand(std::time(nullptr));
	return precision::main(benchmarks);
}