#pragma once

#include <ostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>

#include "time.hpp"

namespace precision
{

/**
 * @brief formats time in ns to be printed by write_formatted in @a unit
 */
inline std::string format_time(const int64_t ns, std::string unit)
{
	std::ostringstream out;

	if (unit == "auto")
	{
		if (ns / h_to_ns > 0)
		{
			unit = "h";
		}
		else if (ns / min_to_ns > 0)
		{
			unit = "min";
		}
		else if (ns / s_to_ns > 0)
		{
			unit = "s";
		}
		else if (ns / ms_to_ns > 0)
		{
			unit = "ms";
		}
		else if (ns / us_to_ns > 0)
		{
			unit = "us";
		}
		else
		{
			unit = "ns";
		}
	}

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

/**
 * @brief write a table of the results to out
 */
inline std::ostream& write_formatted(std::ostream &out, const std::vector<result> &results, const benchmark_config &config = benchmark_config())
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