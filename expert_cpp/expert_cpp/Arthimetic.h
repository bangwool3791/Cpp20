#pragma once

template <typename Iter, typename StartValue, typename Operation>
auto accumulateData(Iter begin, Iter end, StartValue startValue, Operation op)
{
	auto accumulated{ startValue };
	for (Iter iter{ begin }; iter != end; ++iter)
	{
		accumulated = op(accumulated, *iter);
	}
	return accumulated;
}

#include <span>
double geometricMean(std::span<const int> values)
{
	auto mult{ accumulateData(std::cbegin(values), std::cend(values), 1, std::multiplies<int>{}) };
	return pow(mult, 1.0 / values.size());
}

#include <math.h>

double geometricMeanTransparent(std::span<const int> values)
{
	auto mult{ accumulateData(std::cbegin(values), std::cend(values), 1, std::multiplies<>{}) };
	return pow(mult, 1.0 / values.size());
}