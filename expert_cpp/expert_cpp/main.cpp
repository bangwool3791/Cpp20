// expert_cpp.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include "pch.h"
//#include "Spreadsheet.h"
//#include "PointersToMethods.h"
#include "FunctionPointer.h"
//#include "standard_function.h"
//#include "FunctionObjects.h"
//#include "Handler.h"

using namespace std;

int main()
{
	//// Bind second argument to a fixed value.
	//string myString{ "abc" };
	//auto f1{ bind(func, placeholders::_1, myString) };
	//f1(16);

	//// Rearrange arguments
	//auto f2{ bind(func, placeholders::_2, placeholders::_1) };
	//f2("Test", 32);

	[&](auto func, auto string)
	{
		bind(func, placeholders::_1, string);
	};
	return 0;
}
