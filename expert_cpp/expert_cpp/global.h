#pragma once
template<typename ITeratorType>
void iteratorTraitsTest(ITeratorType it)
{
	typename iterator_traits<ITeratorType>::value_type temp;
	temp = *it;
	cout << temp << endl;
}

template<typename Iter>
auto myFind(Iter begin, Iter end, const typename iterator_traits<Iter>::value_type& value)
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

template<typename InpuIter>
auto sum(InpuIter begin, InpuIter end)
{
	auto sum{ *begin };
	for (auto iter{ ++begin }; iter != end; ++iter) { sum += *iter; }
	return sum;
}