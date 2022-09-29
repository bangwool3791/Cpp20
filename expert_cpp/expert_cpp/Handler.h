#pragma once

#include "pch.h"
#include "FunctionPointer.h"

class Handler
{
public :
	void handleMatch(size_t position, int value1, int value2)
	{
		cout << format("Match found at position {} ({}, {})", position, value1, value2) << endl;
	}
};

//int main()
//{
//	std::vector<int> values1{ 1,2,2,3,4,5 };
//	std::vector<int> values2{ 1,2,2,3,4,5 };
//	Handler handler;
//	findMatches(values1, values2, intEqual, bind(&Handler::handleMatch, &handler, placeholders::_1, placeholders::_2, placeholders::_3));
//	return 0;
//}