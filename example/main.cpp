#include <iostream>
#include <algorithm>

#include <precision/precision.hpp>

int main(int argc, char **argv)
{
	precision::benchmark b{
		"hello",
		[](auto &s) {
			std::vector<int> v;
			for (int i = 0; i < 1000000; ++i)
			{
				v.push_back(rand() % 1000);
			}

			while (s.running())
			{
				std::sort(v.begin(), v.end());
			}
		}
	};

	precision::state s(std::chrono::seconds(10));
	b.run(s);

	std::cout << s.samples.size() << " iterations\n";
	std::cout << std::chrono::duration<float>(precision::average(s.samples.begin(), s.samples.end())).count() << "s\n";
}