#pragma once
#include <exception>
#include <string>
#include <string_view>

class SpreadsheetApplication {};

class Spreadsheet
{
public :
	class Cell;
private:
	static const size_t MaxHeight{ 100 };
	static const size_t MaxWidth{ 100 };
public:

	Spreadsheet(const SpreadsheetApplication& theApp, size_t width = MaxHeight, size_t height = MaxWidth);
	Spreadsheet(const Spreadsheet& src);
	Spreadsheet( Spreadsheet&& src)  noexcept;
	Spreadsheet& operator = (const Spreadsheet & rhs);
	Spreadsheet& operator = (Spreadsheet&& rhs) noexcept;
	~Spreadsheet();
public :
	void swap( Spreadsheet& other) noexcept;
	void swap(Spreadsheet& first, Spreadsheet& second) noexcept;
	void setCellAt(size_t x, size_t y, const Cell& cell);
	Cell& getCellAt(size_t x, size_t y);
	const Cell& getCellAt(size_t x, size_t y) const;
	size_t get_Id() const;
private:
	bool inRange(size_t value, size_t upper) const;
	void verifyCoordinate(size_t x, size_t y) const;
	void cleanup() noexcept;
	void moveFrom(Spreadsheet& src) noexcept;
private:
	size_t m_width{ 0 };
	size_t m_height{ 0 };
	std::string m_name;
	Cell** m_cells;
	const SpreadsheetApplication& m_theApp;
	static inline size_t ms_counter{0};
	const size_t m_id{ 0 };
	
};

class Spreadsheet::Cell
{
public:
	enum class Color { Red = 1, Green, Blue, Yellow };
	void setColor(Color color);
	Color getColor() const;
private:
	Color m_color{ Color::Red };
public:
	Cell() = default;
	Cell(double initialValue);
	Cell(std::string_view initialValue);
	Cell(const Cell& src);
	Cell& operator=(const Cell& rhs);
	void set(double value);
	void setValue(int) = delete;
	void setValue(double value);
	double getValue() const;
	void set(std::string_view value);
	std::string getString() const;
	static std::string doubleToString(double value);
	static double stringToDouble(std::string_view value);
	Spreadsheet::Cell add(const Spreadsheet::Cell& cell) const;
	//operator
public :
	Spreadsheet::Cell operator + (const Spreadsheet::Cell& rhs);
	Spreadsheet::Cell& operator +=(const Spreadsheet::Cell& rhs);
	Spreadsheet::Cell operator+(double rhs) const;
	Spreadsheet::Cell operator+(std::string_view rhs) const;
private:
	double m_value{ 0 };
	mutable size_t m_numAccesses{ 0 };
};

Spreadsheet::Cell operator+(const Spreadsheet::Cell& lhs, const Spreadsheet::Cell& rhs);

//int main()
//{
//	Spreadsheet::Cell myCell{ 4 };
//	Spreadsheet::Cell anotherCell{ 5 };
//	Spreadsheet::Cell otherCell{ 6 };
//	myCell += anotherCell;
//	myCell = myCell + otherCell;
//	std::cout << myCell.getValue() << std::endl;
//}