#pragma once
template<typename T = int, size_t WIDTH = 10, size_t HEIGHT = 10>
class Grid
{
public:
	Grid() = default;
	virtual ~Grid() = default;
	Grid(const Grid & src) = default;
	Grid& operator=(const Grid & rhs) = default;
	Grid(Grid && src) = default;
	Grid& operator=(Grid && rhs) = default;
	std::optional<T>& at(size_t x, size_t y);
	const std::optional<T>& at(size_t x, size_t y) const;
	size_t getHeight() const { return m_height; }
	size_t getWidth() const { return m_width; }
	static const size_t DefaultWidth{ 10 };
	static const size_t DefaultHeight{ 10 };

	template<typename E>
	Grid(const Grid<E>& src);

	template<typename E>
	Grid& operator=(const Grid<E>& rhs);
	void swap(Grid& other)noexcept;

	template<typename T, size_t WIDTH, size_t HEIGHT>
	template<typename E, size_t WIDTH2, size_t HEIGHT2>
	Grid<T, WIDTH, HEIGHT>::Grid(const Grid<E, WIDTH2, HEIGHT2>& src);

	template <typename T, size_t WIDTH, size_t HEIGHT>
	template <typename E, size_t WIDTH2, size_t HEIGHT2>
	Grid<T, WIDTH, HEIGHT>& Grid<T, WIDTH, HEIGHT>::operator=(
		const Grid<E, WIDTH2, HEIGHT2>& rhs);

private:
	void verifyCoordinate(size_t x, size_t y) const;
	std::optional<T> m_cells[WIDTH][HEIGHT];
};

template<typename T, size_t WIDTH, size_t HEIGHT>
Grid<T, WIDTH, HEIGHT>::Grid()
{
}

template<typename T, size_t WIDTH, size_t HEIGHT>
template<typename E>
/*
* template <typename T, typename E> // Wrong for nested template constructor!
Grid<T>::Grid(const Grid<E>& src)
*/
Grid<T, WIDTH, HEIGHT>::Grid(const Grid<E>& src)
{
	for (size_t i{ 0 }; i < WIDTH; i++)
	{
		for (size_t j{ 0 }; j < HEIGHT; j++)
		{
			m_cells[i][j] = src.at(i, j);
		}
	}
}

template<typename T, size_t WIDTH, size_t HEIGHT>
template<typename E, size_t WIDTH2, size_t HEIGHT2>
Grid<T, WIDTH, HEIGHT>::Grid(const Grid<E, WIDTH2, HEIGHT2>& src)
{
	for (size_t i{ 0 }; i < WIDTH; i++)
	{
		for (size_t j{ 0 }; j < HEIGHT; j++)
		{
			if (i < WIDTH2 && j < HEIGHT2)
			{
				m_cells[i][j] = src.at(i, j);
			}
			else
			{
				m_cells[i][j].reset();
			}
		}
	}
}

template <typename T, size_t WIDTH, size_t HEIGHT>
template <typename E, size_t WIDTH2, size_t HEIGHT2>
Grid<T, WIDTH, HEIGHT>& Grid<T, WIDTH, HEIGHT>::operator=(
	const Grid<E, WIDTH2, HEIGHT2>& rhs)
{
	// Copy-and-swap idiom
	Grid<T, WIDTH, HEIGHT> temp{ rhs }; // Do all the work in a temp instance.
	swap(temp); // Commit the work with only non-throwing operations.
	return *this;
}

template<typename T, size_t WIDTH, size_t HEIGHT>
template<typename E>
Grid<T, WIDTH, HEIGHT>& Grid<T, WIDTH, HEIGHT>::operator=(const Grid<E>& rhs)
{
	/*
	* The swap() method can only swap Grids of the same type, but that’s OK because this
	templatized assignment operator first converts a given Grid<E> to a Grid<T> called temp using the
	templatized copy constructor. Afterward, it uses the swap() method to swap this temporary Grid<T>
	with this, which is also of type Grid<T>.
	*/
	Grid<T, WIDTH, HEIGHT> temp{ rhs };
	swap(temp);
	return *this;
}

template<typename T, size_t WIDTH, size_t HEIGHT>
void Grid<T, WIDTH, HEIGHT>::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= WIDTH) {
		throw std::out_of_range{
		std::format("{} must be less than {}.", x, WIDTH) };
	}
	if (y >= HEIGHT) {
		throw std::out_of_range{
		std::format("{} must be less than {}.", y, HEIGHT) };
	}
}
template<typename T, size_t WIDTH, size_t HEIGHT>
const std::optional<T>& Grid<T, WIDTH, HEIGHT>::at(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return m_cells[x][y];
}

template<typename T, size_t WIDTH, size_t HEIGHT>
std::optional<T>& Grid<T, WIDTH, HEIGHT>::at(size_t x, size_t y)
{
	/*
	* const 타입으로 사용하고 싶지만 케스팅을 하지 않을 때 as_const를 사용한다.
	*/
	return const_cast<std::optional<T>&>(std::as_const(*this).at(x, y));
}

//int main()
//{
//	Grid<int> myIntGrid; // Declares a grid that stores ints,
//// using default arguments for the constructor.
//	Grid<double> myDoubleGrid{ 11, 11 }; // Declares an 11x11 Grid of doubles.
//	myIntGrid.at(0, 0) = 10;
//	int x{ myIntGrid.at(0, 0).value_or(0) };
//	Grid<int> grid2{ myIntGrid }; // Copy constructor
//	Grid<int> anotherIntGrid;
//	anotherIntGrid = grid2; // Assignment operator
//
//	return 0;
//}

int main()
{
	//Grid<vector<int>> gridOfVectors;
	//vector<int> myvector{ 1,2,3,4 };
	//gridOfVectors.at(5, 6) = myvector;
	//
	//auto myGridOnFreeStore{ make_unique<Grid<int>>(2,2) };
	//myGridOnFreeStore->at(0, 0) = 10;
	//int x{ myGridOnFreeStore->at(0, 0).value_or(0) };
	return 0;
}

int main()
{
	Grid<int, 10, 10> myGrid;
	Grid<int, 10, 10> anotherGrid;
	myGrid.at(2, 3) = 42;
	anotherGrid = myGrid;
	cout << anotherGrid.at(2, 3).value_or(0);
	return 0;
}

int main()
{
	auto pair2{ make_pair(1, 2.3) };

	pair pair3{ 1, 2.3 }; // pair3 has type pair<int, double>
	//Of course, this works only when all template parameters of a class template either have default values
	//	or are used as parameters in the constructor so that they can be deduced.
	return 0;
}

template<typename T>
class SpreadsheetCell
{
public:
	SpreadsheetCell(T t) : m_content{ move(t) };
	const T& getContent() const { return getContent; }

private:
	T m_content;
};