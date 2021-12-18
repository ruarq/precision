#include "precision/write_formatted.hpp"

namespace precision
{

auto format_time(const int64_t ns, std::string unit) -> std::string
{
	std::ostringstream out;

	if (unit == "h")
	{
		out << std::setprecision(1) << ((float)(ns * ns_to_h));
	}
	else if (unit == "min")
	{
		out << std::setprecision(1) << ((float)(ns * ns_to_min));
	}
	else if (unit == "s")
	{
		out << std::setprecision(2) << ((float)(ns * ns_to_s));
	}
	else if (unit == "ms")
	{
		out << (int64_t)(ns * ns_to_ms);
	}
	else if (unit == "us")
	{
		out << (int64_t)(ns * ns_to_us);
	}
	else if (unit == "ns")
	{
		out << ns;
	}

	return out.str() + unit;
}

auto write_formatted(std::ostream &out, const std::vector<result> &results, const benchmark_config &config) -> std::ostream&
{
	uint32_t benchmark_width = 15;

	for (auto result : results)
	{
		auto len = strlen(result.name);
		if (len > benchmark_width)
		{
			benchmark_width = len;
		}
	}

	out << std::setw(benchmark_width) << "Benchmark";
	out << std::setw(15) << "Min";
	out << std::setw(15) << "Mean";
	out << std::setw(15) << "Max";
	out << std::setw(15) << "Iterations";
	out << "\n";

	for (auto result : results)
	{
		out << std::setw(benchmark_width) << result.name;
		out << std::setw(15) << format_time(result.min, config.unit);
		out << std::setw(15) << format_time(result.mean, config.unit);
		out << std::setw(15) << format_time(result.max, config.unit);
		out << std::setw(15) << result.iterations;
		out << "\n";
	}

	return out;
}

}