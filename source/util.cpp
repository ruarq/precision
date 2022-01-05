#include "precision/util.hpp"

namespace precision
{

auto format_string(const duration &dur, const unit u) -> std::string
{
	using namespace std::string_literals;

	std::string result;

	switch (u)
	{
		// precision::duration is already in nanoseconds, so no cast needed
		case unit::ns:
			result += std::to_string(dur.count());
			break;

		case unit::us:
			result += std::to_string(std::chrono::duration_cast<std::chrono::microseconds>(dur).count());
			break;

		case unit::ms:
			result += std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(dur).count());
			break;

		case unit::s:
			result += std::to_string(std::chrono::duration<float>(dur).count());
			break;

		case unit::min:
			result += std::to_string(std::chrono::duration<float, std::ratio<60>>(dur).count());
			break;

		case unit::h:
			result += std::to_string(std::chrono::duration<float, std::ratio<3600>>(dur).count());
			break;

		case unit::none:
		default:
			throw std::invalid_argument("precision::format_string() : invalid unit");
	}

	return result + " "s + to_string(u);
}

auto create_status_bar(const float progress, const int width) -> std::string
{
	std::string bar = "[";

	const int filled = width * progress;

	for (int i = 0; i < filled; ++i)
	{
		bar += "=";
	}
	bar += ">";

	for (int i = 0; i < width - filled; ++i)
	{
		bar += " ";
	}

	return bar + "]";
}

}