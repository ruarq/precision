#include "precision/main.hpp"

#include "help.hpp"

namespace precision
{

auto main(std::vector<benchmark> benchmarks, const int argc, char **argv) -> int
{
	const option long_options[] = {
		{ "time",		required_argument,	nullptr, 't' },
		{ "precision",	required_argument,	nullptr, 'p' },
		{ "unit",		required_argument,	nullptr, 'u' },
		{ "help",		no_argument,		nullptr, 'h' },
		{ nullptr,		0,					nullptr,  0  }
	};

	int opt;
	int long_opt_index;
	while ((opt = getopt_long(argc, argv, "t:p:u:h", long_options, &long_opt_index)) != -1)
	{
		switch (opt)
		{
			case 't':
			{	size_t sz;
				auto time = std::stof(optarg, &sz);
				auto unit = from_string(std::string(optarg).substr(sz));

				for (auto &bench : benchmarks)
				{
					switch (unit)
					{
						case unit::ns:
							bench.time(std::chrono::nanoseconds(int64_t(time)));
							break;

						case unit::us:
							bench.time(std::chrono::microseconds(int64_t(time)));
							break;

						case unit::ms:
							bench.time(std::chrono::milliseconds(int64_t(time)));
							break;

						case unit::s:
							bench.time(std::chrono::duration_cast<precision::duration>(
								std::chrono::duration<float>(time)));
							break;
						
						case unit::min:
							bench.time(std::chrono::duration_cast<precision::duration>(
								std::chrono::duration<float, std::ratio<60>>(time)));
							break;

						case unit::h:
							bench.time(std::chrono::duration_cast<precision::duration>(
								std::chrono::duration<float, std::ratio<3600>>(time)));
							break;

						case unit::none:
						default:
							throw std::runtime_error("invalid argument for option -t/--time");
					}
				}
			}
			break;

			case 'u':
			case 'p':
			{
				auto unit = from_string(optarg);
				for (auto &bench : benchmarks)
				{
					bench.precision(unit);
				}
			}
			break;

			case 'h':
			default:
				std::cout << "usage: " << argv[0] << " [options]\n" << help;
				return 1;
		}
	}

	// find the benchmark with the longest name
	auto maxw = std::max_element(benchmarks.begin(), benchmarks.end(), [](const benchmark &a, const benchmark &b)
	{
		return a.name.size() < b.name.size();
	})->name.size();

	// maxw only >= 15
	maxw = std::max(maxw, (size_t)(15));

	std::cout << std::setw(maxw) << "Benchmark";
	std::cout << std::setw(20) << "Min";
	std::cout << std::setw(20) << "Mean";
	std::cout << std::setw(20) << "Max";
	std::cout << std::setw(15) << "Samples";
	std::cout << "\n";

	for (auto &bench : benchmarks)
	{
		context ctx(bench.run_duration);
		bench.run(ctx);

		std::cout << std::setw(maxw) << bench.name;
		std::cout << std::setw(20) << format_string(ctx.min(), bench.target_unit);
		std::cout << std::setw(20) << format_string(ctx.mean(), bench.target_unit);
		std::cout << std::setw(20) << format_string(ctx.max(), bench.target_unit);
		std::cout << std::setw(15) << ctx.sample_count();
		std::cout << "\n";
	}

	return 0;
}

}