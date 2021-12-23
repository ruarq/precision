#include "precision/main.hpp"

namespace precision
{

auto main(const std::vector<benchmark> &benchmarks) -> int
{
	std::cout << std::setw(15) << "Benchmark";
	std::cout << std::setw(15) << "Min";
	std::cout << std::setw(15) << "Mean";
	std::cout << std::setw(15) << "Max";
	std::cout << std::setw(15) << "Samples";
	std::cout << "\n";

	for (auto &[name, run, runtime] : benchmarks)
	{
		context ctx(runtime);
		run(ctx);

		auto min = /* std::chrono::duration<float> */(ctx.min());
		auto mean = /* std::chrono::duration<float> */(ctx.mean());
		auto max = /* std::chrono::duration<float> */(ctx.max());

		std::cout << std::setw(15) << name;
		std::cout << std::setw(15) << min.count();
		std::cout << std::setw(15) << mean.count();
		std::cout << std::setw(15) << max.count();
		std::cout << std::setw(15) << ctx.sample_count();
		std::cout << "\n";
	}

	return 0;
}

}