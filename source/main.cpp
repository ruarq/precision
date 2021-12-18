#include "precision/main.hpp"

namespace precision
{

auto main(int argc, char **argv, const std::vector<benchmark> &benchmarks) -> int
{
	benchmark_config config;

	const option long_options[] = {
		{ "min-runtime",	required_argument,	nullptr, 't'	},
		{ "unit",			required_argument,	nullptr, 'u'	},
		{ nullptr,			0,					nullptr, 0		}
	};

	int opt;
	int option_index;
	while ((opt = getopt_long(argc, argv, "u:t:", long_options, &option_index)) != -1)
	{
		switch (opt)
		{
			case 't':
				config.min_runtime = parse_runtime(optarg);
				if (config.min_runtime == std::numeric_limits<int64_t>::infinity())
				{
					std::cout << argv[0] << ": invalid argument for option '" << optopt << "'\n";
					return 1;
				}
				break;

			case 'u':
				config.unit = optarg;
				if (!validate_unit(config.unit))
				{
					std::cout << argv[0] << ": invalid argument for option '" << optopt << "'\n";
					return 1;
				}
				break;

			case '?':
			default:
				return 1;
		}
	}

	auto results = run(benchmarks, config);
	write_formatted(std::cout, results, config);

	return 0;
}

}