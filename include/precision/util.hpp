#pragma once

#include <iterator>
#include <string>
#include <chrono>

#include "clock.hpp"
#include "unit.hpp"

namespace precision
{

template <class T>
auto dont_optimize(T& value) -> void
{
	#if not defined(__clang__)
		asm volatile("" : "+m,r"(value) : : "memory");
	#else
		asm volatile("" : "+r,m"(value) : : "memory");
	#endif
}

auto format_string(const duration &dur, const unit u) -> std::string;

auto create_status_bar(const float progress, int width) -> std::string;

}