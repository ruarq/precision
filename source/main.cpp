#include "precision/main.hpp"

#include "help.hpp"

namespace precision
{

auto main(std::vector<benchmark> benchmarks, const int argc, char **argv) -> int
{
	if (argc != 0 && argv != nullptr)
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
								bench.time(std::chrono::duration_cast<precision::duration>(
									std::chrono::duration<float, std::nano>(time)));
								break;

							case unit::us:
								bench.time(std::chrono::duration_cast<precision::duration>(
									std::chrono::duration<float, std::micro>(time)));
								break;

							case unit::ms:
								bench.time(std::chrono::duration_cast<precision::duration>(
									std::chrono::duration<float, std::milli>(time)));
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
					return opt != 'h';
			}
		}
	}

	std::vector<benchmark_result> results;

	// warm up the processor
	run_empty_bench();

	// run the benchmarks
	size_t progress = 0;
	// print the progress
	std::cout << "\rRunning... " << create_status_bar((float)(progress) / (float)(benchmarks.size()), 80 - 12);
	std::flush(std::cout);
	for (auto &bench : benchmarks)
	{
		auto bench_result = run_benchmark(bench);
		results.push_back(bench_result);

		// print the progress
		std::cout << "\rRunning... " << create_status_bar((float)(++progress) / (float)(benchmarks.size()), 80 - 12);
		std::flush(std::cout);
	}
	std::cout << "\r";

	write_results(std::cout, results);

	return 0;
}

}