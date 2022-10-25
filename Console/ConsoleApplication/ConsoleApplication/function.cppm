module;

export module function;

import <string>;
import grid;
static const size_t NOT_FOUND{ static_cast<size_t>(-1) };

const std::string message{ "Test" };
const std::string& getString() { return message; }

auto					s1{ getString() };
const auto&				s2{ getString() };
decltype(getString())   s3{ getString() };
decltype(auto)			s4{ getString() };
decltype(auto) add(const auto& t1, const auto& t2) { return t1 + t2; }
template<typename T1, typename T2>
auto add(const T1& t1, const T2& t2) ->decltype(t1 + t2)
{
	return t1 + t2;
}
export template<typename T>
size_t Find(const T& value, const T* arr, size_t size)
{
	for (size_t i{ 0 }; i < size; ++i) {
		if (value == arr[i]) {
			return i;
		}
	}

	return NOT_FOUND;
}

export;
size_t Find(const char* value, const char ** arr, size_t size)
{
	for (size_t i{ 0 }; i < size; ++i) {
		if (strcmp(value, arr[i]))
		{
			return i;
		}
	}

	return NOT_FOUND;
}

export template<typename T, size_t N>
size_t Find(const T& value, const T(&arr)[N])
{
	Find(value, arr, N);
}

export template<typename T>
Grid<T> operator+(const Grid<T>& lhs, const Grid<T>& rhs)
{
	size_t minWidht = min(lhs.getWidth(), rhs.getWidth());
	size_t minHeight = min(lhs.getHeight(), rhs.getHeight());

	Grid<T> result{ minWidht, minHeight };

	for (size_t y{ 0 }; y < minHeight; ++y)
	{
		for (size_t x{ 0 }; x < minHeight; ++x)
		{
			const auto& leftElement{ lhs.m_cells[x][y] };
			const auto& rightElement{ rhs.m_cells[x][y] };
			if (leftElement.has_value() && rightElement.has_value())
			{
				result.at(x, y) = leftElement.value() + leftElement.value();
			}
		}
	}
	return result;
}

template <typename RetType, typename T1, typename T2>
RetType add(const T1& t1, const T2& t2) { return t1 + t2; }