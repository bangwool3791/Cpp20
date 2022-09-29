#pragma once

#include "pch.h"

template<typename ITeratorType>
void iteratorTraitsTest(ITeratorType it)
{
	typename iterator_traits<ITeratorType>::value_type temp;
	temp = *it;
	cout << temp << endl;
}

template<typename Iter>
auto myFind(Iter begin, Iter end, const typename std::iterator_traits<Iter>::value_type& value)
{
	for (auto iter{ begin }; iter != end; ++iter)
	{
		if (*iter == value)
			return iter;
	}
	return end;
}

template<typename InputIter, typename OutputIter>
void myCopy(InputIter begin, InputIter end, OutputIter target)
{
	for (auto Iter{ begin }; Iter != end; ++Iter)
	{
		*target = *iter;
	}
}

int main()
{
	vector<int> v{ 1,2,3,4,5,6,7,8,9 };
	vector<int> r(v.size());
	myCopy(begin(v), end(v), begin(r));

	myCopy(cbegin(v), cend(v), ostream_iterator<int>{cout, " "});
	cout << endl;
	myCopy(cbegin(r), cend(r), ostream_iterator<int>{cout, " "});
	cout << endl;
	return 0;
}

template<typename InpuIter>
auto sum(InpuIter begin, InpuIter end)
{
	auto sum{ *begin };
	for (auto iter{ ++begin }; iter != end; ++iter) { sum += *iter; }
	return sum;
}

int main()
{
	istream_iterator<int> iter{ cin };
	istream_iterator<int> enditer;

	int result{ sum(iter, enditer) };
	return 0;
}

int main()
{
	vector vectorOne{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<int> vectorTwo;
	back_insert_iterator<vector<int>> inserter{ vectorTwo };

	myCopy(cbegin(vectorOne), cend(vectorOne), inserter);
	myCopy(cbegin(vectorOne), cend(vectorOne), back_inserter(vectorTwo));
	myCopy(cbegin(vectorOne), cend(vectorOne), back_insert_iterator{ vectorTwo });
	myCopy(cbegin(vectorTwo), cend(vectorTwo), ostream_iterator<int>(cout, " "));
	return 0;
}
