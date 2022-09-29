#include "pch.h"

/*
* Exercise 19-2
*/

//void func(int num, string_view str)
//{
//	cout << format("func({}, {})", num, str) << endl;
//}
//
//int main()
//{
//
//	auto lambda{ [](auto string)
//	{
//		return bind(func, placeholders::_1, string);
//	} };
//
//	auto func{ lambda("MyName") };
//
//	func(1);
//}

/*
* Exercise 19-3
*/

class Handler
{
public:
	void handleMatch(size_t position, int value1, int value2)
	{
		cout << format("Match found at position {} ({}, {})",
			position, value1, value2) << endl;
	}
};

bool Func(int a, int b)
{
	return a == b;
}
//19-3
int main()
{

	Handler handler;

	vector values1{ 2, 5, 6, 9, 10, 1, 1 };
	vector values2{ 4, 4, 2, 9, 0, 3, 1 };

	auto elem{ [&](auto v1, auto v2, auto intEqual)
		{
			if (v1.size() != v2.size())
			{
				return;
			}

			auto f1{ bind(&Handler::handleMatch, &handler,

				placeholders::_1, placeholders::_2, placeholders::_3)};

			for (size_t i{ 0 }; i < v1.size(); ++i)
			{
				if (intEqual(v1[i], v2[i]))
				{
					f1(i, v1[i], v2[i]);
				}
			}
	} };

	elem(values1, values2, Func);
}

//19-4
int main()
{
	vector<int> v{ 1,2,3,4,5,6,7,8,9,10,11,12 };

	erase_if(v, [](int a)->bool
		{
			if (a % 2 == 0)
				return false;
			else
				return true;
		});

	return 0;
}

//19-5
class Processor
{
public:
	Processor(function<int(int)> ptr)
	{
		m_func = ptr;
	}
private:
	function<void(int)> m_func;
	int operator()(int i)
	{
		return i;
	}
};
int main()
{
	vector<int> v{ 1,2,3,4,5,6,7,8,9,10,11,12 };

	erase_if(v, [](int a)->bool
		{
			if (a % 2 == 0)
				return false;
			else
				return true;
		});

	return 0;
}

