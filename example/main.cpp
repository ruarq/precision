#include <string>

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
		"string-create",
		[](auto &ctx) {
			while (ctx.running())
			{
				std::string s;
			}
		}
	},

	precision::benchmark {
		"string-copy",
		[](auto &ctx) {
			std::string s = "Hello precision!";
			
			while (ctx.running())
			{
				auto copy = s;
			}
		}
	}
};

auto main() -> int
{
	std::srand(std::time(nullptr));
	return precision::main(benchmarks);
}