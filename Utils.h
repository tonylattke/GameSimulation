#pragma once

// It helps to restric a value n between a min and max value
template <typename T>
T clamp(const T& n, const T& lower, const T& upper) {
	return std::max(lower, std::min(n, upper));
}