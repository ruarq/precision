#include <iostream>
#include <thread>

#include "precision/precision.hpp"

auto benchmarks = {
	precision::benchmark {
		"sort-reverse-sorted",
		[]() {
		}
	},

	precision::benchmark {
		"sort-random",
		[]() {
		}
	}
};

int main(int argc, char **argv)
{
	return precision::main(argc, argv, benchmarks);
}