#include <iostream>
#include <thread>

#include "precision/precision.hpp"

std::vector<int> nums;
constexpr static auto nums_size = 1'000'000;

auto benchmarks = {
	precision::benchmark{
		"create-random-array",
		[]() {
			std::vector<int> v;
			for (int i = 0; i < 10'000'000; ++i)
			{
				v.push_back(std::rand() % 100'000);
			}
		}
	},

	precision::benchmark{
		"create-sorted-array",
		[]() {
			std::vector<int> v;
			for (int i = 0; i < 10'000'000; ++i)
			{
				v.push_back(i);
			}
		}
	},

	precision::benchmark{
		"sort-sorted",
		[]() {
			std::vector<int> v;
			for (int i = 0; i < 10'000'000; ++i)
			{
				v.push_back(i);
			}

			std::sort(v.begin(), v.end());
		}
	},

	precision::benchmark{
		"sort-random",
		[]() {
			std::vector<int> v;
			for (int i = 0; i < 10'000'000; ++i)
			{
				v.push_back(std::rand() % 100'000);
			}

			std::sort(v.begin(), v.end());
		}
	}
};

int main(int argc, char **argv)
{
	for (int i = 0; i < nums_size; ++i)
	{
		nums.push_back(std::rand() % 1'000);
	}

	return precision::main(argc, argv, benchmarks);
}