#include <iostream>
#include <thread>

#include "precision/precision.hpp"

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
	}
};

precision_main(benchmarks);
