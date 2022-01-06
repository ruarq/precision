#pragma once

#include <iterator>
#include <string>
#include <chrono>

#include "clock.hpp"
#include "unit.hpp"

namespace precision
{


/**
 * @brief do not optimize the value passed
 * @param value the value to not optimize
 */
template <class T>
auto dont_optimize(T& value) -> void
{
	#if defined(__clang__)
		asm volatile("" : "+r,m"(value) : : "memory");
	#else
		asm volatile("" : "+m,r"(value) : : "memory");
	#endif
}

/**
 * @brief format a duration to a string in the unit u
 * @param dur the duration
 * @param u the unit to format to
 * @return dur formatted with u
 */
auto format_string(const duration &dur, const unit u) -> std::string;

/**
 * @brief puts together a loading/status bar and returns it
 * @param progress how much in the bar should be filled in percent (0.0-1.0)
 * @param width the width of the bar in characters
 * @return string containing the bar
 */
auto create_status_bar(const float progress, int width) -> std::string;

}