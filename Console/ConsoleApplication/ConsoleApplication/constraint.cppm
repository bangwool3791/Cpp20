module;

export module constraint;

import <concepts>;

using std::convertible_to;
using namespace std;

template <typename T>
concept C = sizeof(T) == 4;

template <typename T>
concept Incrementable = requires(T x) { x++; ++x; };

template <typename T>
concept C = requires { typename T::value_type; };

/*
* 주어진 타입으로 객체화 될 수 있는가?
*/
template<typename T>
class SomeTemplate
{

};
template <typename T>
concept C = requires 
{ 
	typename SomeTemplate<T>; 
};

template <typename T>
concept C = requires (T x, T y) 
{
	{ x.swap(y) } noexcept;
};

template <typename T>
concept C = requires (const T x) 
{
	{ x.size() } -> convertible_to<size_t>;
};

template <typename T>
concept Comparable = requires(const T a, const T b) {
	{ a == b } -> convertible_to<bool>;
	{ a < b } -> convertible_to<bool>;
	// ... similar for the other comparison operators ...
};

template <typename T>
concept C = requires (T t) {
	requires sizeof(t) == 4;
++t; --t; t++; t--;
};

class Foo
{

};
/*
* T is derived from class Foo
*/
template <typename T>
concept IsDerivedFromFoo = derived_from<T, Foo>;
/*
* T is convert to bool
*/
template <typename T>
concept IsConvertibleToBool = convertible_to<T, bool>;

template<typename T>
concept DefaultAndCopyConstructible = default_initializable<T> && copy_constructible<T>;
//template <typename T>
//concept IncrementableAndDecrementable = Incrementable<T> && Decrementable<T>;

Incrementable auto value1{ 1 };

/*
* The type is deduced as std::string (note the use of the s standard user-defined literal)
* string dose not model Incrementable
*/
//Incrementable auto value{ "abc"s };

/*
* Type Constraints and Function Templates
* First simply use the familliar template<> syntax, but instead of using typename
*/

template<convertible_to<bool>T>
void handle(const T& t);
/*
* This concept specifies requirements on types that can be incremented with the pre- and post-increment operators,
*/
template<Incrementable T>
void process(const T& t);

template<typename T> requires constant_expression
void process(const T& t);