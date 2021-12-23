#include <iostream>
#include <cmath>

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
		"std-round",
		[](auto &s) {
			while (s.running())
			{
				std::round(random_float(10000));
			}
		}
	},

	precision::benchmark {
		"round-math",
		[](auto &s)
		{
			while (s.running())
			{
				round_math(random_float(10000));
			}
		}
	}
};

auto main(int argc, char **argv) -> int
{
	std::srand(std::time(nullptr));
	return precision::main(argc, argv, benchmarks);
}