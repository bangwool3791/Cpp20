#pragma once
#include <span>
#include <iostream>
#include <format>
#include <vector>

//using Matcher = bool(*)(int, int);
//using MatchHandler = void(*)(size_t, int, int);

bool intEqual(int item1, int item2) { return item1 == item2; }
bool bothOdd(int item1, int item2) { return item1 % 2 == 1 && item2 % 2 == 1; }

void printMatch(size_t position, int value1, int value2)
{
	std::cout << std::format("Match found at position {} ({},{})", position, value1, value2) << std::endl;
}

//template <typename Matcher, typename MatchHandler>
//void findMatches(std::span<const int > values1, std::span<const int> values2,
//	Matcher matcher, MatchHandler handler)
//{
//	if (values1.size() != values2.size())
//		return;
//
//	for (size_t i{ 0 }; i < values1.size(); ++i)
//	{
//		if (matcher(values1[i], values2[i]))
//			handler(i, values1[i], values2[2]);
//	}
//}

void findMatches(std::span<const int > values1, std::span<const int> values2,
	auto matcher, auto handler)
{
	if (values1.size() != values2.size())
		return;

	for (size_t i{ 0 }; i < values1.size(); ++i)
	{
		if (matcher(values1[i], values2[i]))
			handler(i, values1[i], values2[2]);
	}
}

//void findMatches(std::span<const int > values1, std::span<const int> values2,
//	Matcher matcher, MatchHandler handler)
//{
//	if (values1.size() != values2.size())
//		return;
//
//	for (size_t i{ 0 }; i < values1.size(); ++i)
//	{
//		if (matcher(values1[i], values2[i]))
//			handler(i, values1[i], values2[2]);
//	}
//}

//#include "FunctionPointer.h"
//
//int main()
//{
//	std::vector values1{ 2, 5, 6, 9, 10, 1, 1 };
//	std::vector values2{ 4, 4, 2, 9, 0, 3, 1 };
//	std::cout << "Calling findMatches() using intEqual():" << std::endl;
//	findMatches(values1, values2, &intEqual, &printMatch);
//	return -1;
//}

/*Standard Function Lib*/

void func(int num, std::string_view str)
{
	std::cout << std::format("func({}, {})", num, str) << std::endl;
}

//int main()
//{
//	std::function<void(int, std::string_view)> f1{ func };
//	//class template argument deduction
//	std::function f1{ func };
//	f1(1, "test");
//}

template<typename Matcher>
void printMatchingStrings(const vector<string>& strings, Matcher matcher)
{
	for (const auto& string : strings)
	{
		if (matcher(string))
		{
			cout << string << " ";
		}
	}
}