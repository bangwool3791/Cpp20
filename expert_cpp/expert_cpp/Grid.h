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
private:
	void verifyCoordinate(size_t x, size_t y) const;
	std::optional<T> m_cells[WIDTH][HEIGHT];
};

template<typename T, size_t WIDTH, size_t HEIGHT>
Grid<T, WIDTH, HEIGHT>::Grid()
{
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