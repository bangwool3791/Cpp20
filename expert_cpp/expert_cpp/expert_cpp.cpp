// expert_cpp.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <format>
#include <iostream>
#include <vector>
#include "Spreadsheet.h"

using namespace std;

Spreadsheet createObject()
{
	return Spreadsheet{ 3,2 };
}

int main()
{
	vector<Spreadsheet> vec;
	for (size_t i{ 0 }; i < 2; i++)
	{
		cout << "Iteration " << i << endl;
		vec.push_back(Spreadsheet{ 100, 100 });
		cout << endl;
	}

	Spreadsheet s{ 2, 3 };
	s = createObject();

	Spreadsheet s2{ 5,6 };
	s2 = s;
}