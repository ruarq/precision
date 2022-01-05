#include "precision/benchmark_result.hpp"

namespace precision
{

auto write_results(std::ostream &out, const std::vector<benchmark_result> &results) -> void
{
	// find the benchmark with the longest name
	auto maxw = std::max_element(results.begin(), results.end(), [](const auto &a, const auto &b)
	{
		return a.name.size() < b.name.size();
	})->name.size();

	maxw = std::max(maxw, (size_t)(15));

	out << std::setw(maxw) << "Benchmark";
	out << std::setw(20) << "Min";
	out << std::setw(20) << "Mean";
	out << std::setw(20) << "Max";
	out << std::setw(15) << "Samples";
	out << "\n";

	for (auto &result : results)
	{
		if (result.samples.size() != 0)
		{
			// calculate average
			auto avg = std::chrono::nanoseconds(0);
			for (auto &sample : result.samples)
			{
				avg += sample.dur;
			}
			avg /= result.samples.size();

			out << std::setw(maxw) << result.name;
			out << std::setw(20) << format_string(std::min_element(result.samples.begin(), result.samples.end())->dur, result.target_unit);
			out << std::setw(20) << format_string(avg, result.target_unit);
			out << std::setw(20) << format_string(std::max_element(result.samples.begin(), result.samples.end())->dur, result.target_unit);
			out << std::setw(15) << result.samples.size();
			out << "\n";
		}
	}
}

}