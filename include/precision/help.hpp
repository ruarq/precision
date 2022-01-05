#pragma once

namespace precision
{

auto help = R"(
IMPORTANT!
	Supported units: ns, us, ms, s, min, h

	-p, --precision
	-u, --unit
			Change the unit in which the results are printed.
			Examples: s, ns, min

	-t, --time
			Change the runtime of all the individual benchmarks.
			The argument has to be in the format {number}{unit}.
			Examples: 10s, 500us, 1h, 5min
)";

}