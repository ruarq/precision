#pragma once

#include "clock.hpp"

namespace precision
{

class sample final
{
public:
	duration dur;
};

constexpr auto operator<(const sample &a, const sample &b) -> bool
{
	return a.dur < b.dur;
}

}