#include "calculations.hpp"
#include <optional>
std::optional<double> divide(double a, double b){ //Note: div_t div(int, int); is already a standard cstdlib function. Must use "divide" NOT "div".
	if (b == double(0)){
		return std::nullopt;
	}
	return a / b;
}
