#pragma once

#include "pch.h"


class CompilerGeneratedName

{
public:
	/*
	* Note that the function call operator is a const method and has an auto return type to let the compiler automatically deduce the
	return type based on the body of the method.
	*/
	auto operator()()const { cout << "hello from Labda" << endl; };
	auto operator()(int value) const { cout << "The value is " << value << endl; }
	auto operator()(int a, int b)const { return a + b; }

public:
	CompilerGeneratedName(const double& d) : data{ d } {}
	auto operator()()const { cout << "Data = " << data << endl; }
	template<typename T1, typename T2>
	auto operator()(const T1& value1, const T2& value2)const { return value1 == value2; }
private:
	double data;
};

class Person
{
public:
	Person(std::string name) : m_name{ std::move(name) } {}
	const std::string& getName() const { return m_name; }
private:
	std::string m_name;
};

int main()
{
	auto basicLamba{ [] {cout << "Hello from Lambda" << endl; } };
	return 0;
}

/*Parameter Lambda*/

int main()
{
	auto parametersLambda{ [](int value) { cout << "The value is " << value << endl; } };
	parametersLambda(42);

	auto returningLabda{ [](int a, int b) {return a + b; } };
	int sum{ returningLabda(11, 22) };
	return 0;
}

/*return type deduce*/

int main()
{
	/*
	* This Lambda Expression return type string not string reference
	*/
	[](const Person& person) { return person.getName(); };

	/*
	* You can use a trailing return type in combination with decltype(auto) to make it so that the
	deduced type will match the return type of getName(), that is a const string&:
	*/

	[](const Person& person)->decltype(auto) {return person.getName(); };

	/*
	* Capture value
	*/
	double data{ 1.23 };
	auto capturingLambda{ [data] { cout << "Data = " << data << endl; } };
}

int main()
{
	/*
	* Capture const data
	*/
	const double data{ 1.23 };
	auto captureingLambda{ [data]() {cout << "Data = " << data << endl; } };
	return 1;
}

int main()
{
	/*
* That means that even if you capture a non-const variable by value in a lambda
	expression, the lambda expression is not able to modify this copy. You can mark the function call
	operator as non-const by specifying the lambda expression as mutable, as follows:
	double data
*/

	double data{ 1.23 };
	auto captureingLambda{
		[data]() mutable { data *= 2; cout << "Data = " << data << endl; } };

	return 1;
}

/*
* Reference Capturing Parameter
*/
int main()
{
	double data{ 1.23 };
	auto captureingLabda{
		[&data]() {data *= 2; }
	};

	return 1;
}

#include "FunctionPointer.h"

int main()
{
	vector values1{ 2,5,6,9,10,1,1 };
	vector values2{ 4,4,2,9,0,3,1 };

	findMatches(values1, values2, [](int value1, int value2) {return value1 == value2; }, printMatch);

	//Generic Lambda Expressions 
	auto areEqual{ [](const auto& value1, const auto& value2) {
		return value1 == value2; } };

	vector values1{ 2,5,6,9,10,1,1 };
	vector values2{ 4,4,2,9,0,3,1 };

	findMatches(values1, values2, areEqual, printMatch);

	return 1;
}

int main()
{
	auto myPtr{ make_unique<double>(3.1415) };
	auto myLambda{ [p = move(myPtr)] {cout << *p; }};
	
	
	return 1;
}

/*
* Templated Lambda Expressions
*/

//decay_t  : 참조를 푼다.
//decltype : 타입을 추론한다.
int main()
{
	auto lambda{ [](const auto& values)
	{
		using V = decay_t<decltype(values)>;
		using T = typename V::value_type;
		T somValue{};
		T::some_static_function();
	} };

	[] <typename T> (const vector<T>&valus) {
		T somValue{};
		T::some_static_function();};

	/*
	* 	You can also put constraints on the template types by adding a requires clause, discussed in
		Chapter 12. Here’s an example :
	*/
	[] <typename T> (const T& value1, const T& value2) requires integral<T> {/* ... */};
	return 1;
}

/*
* Lambda Expressions as Return Type
*/

function<int(void)> multiplyBy2Lambda(int x)
{
	return [x] {return 2 * x; };
}

int main()
{
	function<int(void)> fn{ multiplyBy2Lambda(5) };
	cout << fn() << endl;

	//auto fn{ multiplyBy2Lambda(5) };
	//cout << fn() << endl;

	/*
	* auto multiplyBy2Lambda(int x)
	{
	return [x]{ return 2 * x; };
	}
	*/

	/*
	* auto multiplyBy2Lambda(int x)
	{
	return [&x]{ return 2 * x; }; // BUG!
	}
	*/
	return 1;
}

int main()
{
	/*
	* C++20 allows lambda expressions to be used in so-called unevaluated contexts. For example, the
	argument passed to decltype() is used only at compile time and never evaluated. Hence, the following
	is not valid in C++17 or older, but is valid since C++20:
	*/
	using Lambdatype = decltype([](int a, int b) {return a + b; });
	return 1;
}

int main()
{
	auto lambda{ [](int a, int b) {return a + b; } };
	//default constructure
	decltype(lambda) lambda2;
	//copy constructure
	auto copy{ lambda };
	//copy assignment
	copy = lambda2;

	using LambdaType = decltype([](int a, int b) {return a + b; });

	//LambdaType getLambda()
	//{
	//	return LambdaType{};
	//}
}