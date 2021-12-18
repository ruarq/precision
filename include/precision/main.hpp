#pragma once

#include <iostream>
#include <getopt.h>

#include "benchmark.hpp"
#include "write_formatted.hpp"
#include "util.hpp"

namespace precision
{

inline int main(int argc, char **argv, const std::vector<benchmark> &benchmarks)
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
				config.min_runtime = std::stoull(optarg);
				break;

			case 'u':
				config.unit = optarg;
				if (!validate_unit(config.unit))
				{
					std::cout << argv[0] << "u" << " invalid value for option '--" << long_options[option_index].name << "'\n";
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

#define precision_main(benchmarks) \
	int main(int argc, char** argv) \
	{ \
		return precision::main(argc, argv, benchmarks); \
	}