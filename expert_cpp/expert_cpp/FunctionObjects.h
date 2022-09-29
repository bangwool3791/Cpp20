#pragma once
#include "FunctionPointer.h"

template<typename Iter, typename StartValue, typename Operation>
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
#include <algorithm>

double geometricMean(std::span<const int> values)
{
	auto mult{ accumulateData(cbegin(values), cend(values), 1, std::multiplies<int>{}) };
	return pow(mult, 1.0 / values.size());
}

//#include <vector>
//int main()
//{
//	//this will improve the performance
//	std::vector<int> values{ 1,2,3 };
//	double result{ accumulateData(cbegin(values), cend(values), 1.1, std::multiplies<>{}) };
//
//	std::vector<int> values{ 1,2,3 };
//	double result{ accumulateData(cbegin(values), cend(values), 1.1, std::multiplies<int>{}) };
//}

class IsLargerThan
{
public :
	explicit IsLargerThan(int value) : m_value{ value } {}
	bool operator() (int value1, int value2) const {
		return value1 > m_value && value2 > m_value;
	}

	bool IsLager(int value1, int value2)
	{
		[](int a, int b)->bool
		{
			return a == b;
		};
	}
private :
	int m_value;
};

//int main()
//{
//	std::vector values1{ 2,500, 6, 9, 10, 101, 1 };
//	std::vector values2{ 4,4, 2, 9, 0, 300, 1 };
//
//	findMatches(values1, values2, IsLargerThan{ 100 }, printMatch);
//}