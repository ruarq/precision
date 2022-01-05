#pragma once

#include <precision/precision.hpp>

#include "diverge_merge_v1.1.hpp"
#include "config.hpp"

static auto diverge_merge_benchmarks = {
	/**
	 * vector-dm
	 */
	precision::benchmark {
		"vector-dm",
		[](auto &ctx) {
			std::srand(std::time(nullptr));

			while (ctx.running())
			{
				ctx.pause();
				std::vector<int> v;
				for (int i = 0; i < ELEMENT_COUNT; ++i)
				{
					v.push_back(std::rand() % (ELEMENT_MAX_VALUE + 1));
				}
				ctx.resume();

				diverge_merge_sort_v1_1(v.begin(), v.end());
			}
		}
	},

	/**
	 * list-dm
	 */
	precision::benchmark {
		"list-dm",
		[](auto &ctx) {
			std::srand(std::time(nullptr));

			while (ctx.running())
			{
				ctx.pause();
				std::list<int> l;
				for (int i = 0; i < ELEMENT_COUNT; ++i)
				{
					l.push_back(std::rand() % (ELEMENT_MAX_VALUE + 1));
				}
				ctx.resume();

				diverge_merge_sort_v1_1(l.begin(), l.end());
			}
		}
	},

	/**
	 * deque-dm
	 */
	precision::benchmark {
		"deque-dm",
		[](auto &ctx) {
			std::srand(std::time(nullptr));

			while (ctx.running())
			{
				ctx.pause();
				std::deque<int> d;
				for (int i = 0; i < ELEMENT_COUNT; ++i)
				{
					d.push_back(std::rand() % (ELEMENT_MAX_VALUE + 1));
				}
				ctx.resume();

				diverge_merge_sort_v1_1(d.begin(), d.end());
			}
		}
	},

	/**
	 * forward-list-dm
	 */
	precision::benchmark {
		"forward-list-dm",
		[](auto &ctx) {
			std::srand(std::time(nullptr));

			while (ctx.running())
			{
				ctx.pause();
				std::forward_list<int> fl;
				for (int i = 0; i < ELEMENT_COUNT; ++i)
				{
					fl.push_front(std::rand() % (ELEMENT_MAX_VALUE + 1));
				}
				ctx.resume();

				diverge_merge_sort_v1_1(fl.begin(), fl.end());
			}
		}
	}
};