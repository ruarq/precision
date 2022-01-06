#pragma once

#include "clock.hpp"

namespace precision
{

/**
 * @brief contains all the data that's harvested during benchmarking
 */
class sample final
{
public:
	duration dur;
};

/**
 * @brief compare to samples by duration
 */
constexpr auto operator<(const sample &a, const sample &b) -> bool
{
	return a.dur < b.dur;
}

}