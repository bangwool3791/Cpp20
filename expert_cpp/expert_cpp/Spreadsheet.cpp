#include "Spreadsheet.h"
#include "pch.h"
#include <stdexcept>
#include <format>
#include <iostream>
#include <algorithm> 

using namespace std;

void swap(Spreadsheet& first, Spreadsheet& second);

Spreadsheet::Cell operator+(const Spreadsheet::Cell& lhs, const Spreadsheet::Cell& rhs)
{
	return Spreadsheet::Cell{ lhs.getValue() + rhs.getValue() };
}

Spreadsheet::Spreadsheet(const SpreadsheetApplication& theApp, size_t width, size_t height)
	:m_id{ms_counter++}
	,m_width{ std::min(width, MaxWidth)}
	,m_height{ std::min(height, m_height) }
	,m_theApp(theApp)
{

	cout << "Normal constructor" << endl;

	m_cells = new Cell * [m_width];
	for (size_t i{ 0 }; i < m_width; i++)
	{
		m_cells[i] = new Cell[m_height];
	}
}

Spreadsheet::Spreadsheet(const Spreadsheet& src)
	:Spreadsheet{src.m_theApp, src.m_width, src.m_height}
{
	cout << "Copy constructor" << endl;

	for (size_t i{ 0 }; i < m_width; i++)
	{
		for (size_t j{ 0 }; j < m_height; j++)
		{
			m_cells[i][j] = src.m_cells[i][j];
		}
	}
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
	cout << "Copy assignment operator" << endl;

	Spreadsheet result{ rhs };
	swap(result);
	return *this;
}


Spreadsheet::Spreadsheet(Spreadsheet&& src) noexcept
	:Spreadsheet{ src.m_theApp, src.m_width, src.m_height }
{
	cout << "Move constructor" << endl;

	swap(*this, src);
}

Spreadsheet& Spreadsheet::operator=(Spreadsheet&& src) noexcept
{
	cout << "Move assignment operator" << endl;

	swap(*this, src);

	return *this;
}

Spreadsheet::~Spreadsheet()
{
	cleanup();
}

void Spreadsheet::setCellAt(size_t x, size_t y, const Cell& cell)
{
	verifyCoordinate(x, y);
	m_cells[x][y] = cell;
}

Spreadsheet::Cell& Spreadsheet::getCellAt(size_t x, size_t y)
{
	return const_cast<Spreadsheet::Cell&>(as_const(*this).getCellAt(x, y));
}

const Spreadsheet::Cell& Spreadsheet::getCellAt(size_t x, size_t y) const
{
	verifyCoordinate(x, y);
	return m_cells[x][y];
}

void Spreadsheet::verifyCoordinate(size_t x, size_t y) const
{
	if (x >= m_width)
	{
		throw std::out_of_range{ format("{} must be less than {}", x, m_width) };
	}
	if (y >= m_width)
	{
		throw std::out_of_range{ format("{} must be less than {}", y, m_height) };
	}
}

void Spreadsheet::swap(Spreadsheet& other) noexcept
{
	std::swap(m_width, other.m_width);
	std::swap(m_height, other.m_height);
	std::swap(m_cells, other.m_cells);
}

void Spreadsheet::swap(Spreadsheet& first, Spreadsheet& second) noexcept
{
	first.swap(second);
}

void Spreadsheet::cleanup() noexcept 
{
	for (size_t i{ 0 }; i < m_width; i++)
	{
		delete[] m_cells[i];
	}

	delete[] m_cells;
	m_cells = nullptr;
	m_width = m_height = 0;
}

void Spreadsheet::moveFrom(Spreadsheet& src)noexcept
{
	m_name = move(src.m_name);

	m_width = std::exchange(src.m_width, 0);
	m_height = std::exchange(src.m_height, 0);
	m_cells = std::exchange(src.m_cells, nullptr);
}

Spreadsheet::Cell::Cell(double initialValue)
	:m_value{ initialValue }
{

}

Spreadsheet::Cell::Cell(std::string_view initialValue)
	: m_value{ stringToDouble(initialValue) }
{
}

Spreadsheet::Cell::Cell(const Spreadsheet::Cell& src)
	: m_value{ src.m_value }
{
}

Spreadsheet::Cell& Spreadsheet::Cell::operator=(const Spreadsheet::Cell& rhs)
{
	if (this == &rhs) {
		return *this;
	}
	m_value = rhs.m_value;
	return *this;
}

void Spreadsheet::Cell::set(double value)
{
	m_value = value;
}

void Spreadsheet::Cell::setValue(double value)
{
	m_value = value;
}
double Spreadsheet::Cell::getValue() const
{
	m_numAccesses++;
	return m_value;
}

void Spreadsheet::Cell::set(std::string_view value)
{
	m_value = stringToDouble(value);
}

std::string Spreadsheet::Cell::getString() const
{
	m_numAccesses++;
	return doubleToString(m_value);
}

std::string Spreadsheet::Cell::doubleToString(double value)
{
	return std::to_string(value);
}

double Spreadsheet::Cell::stringToDouble(std::string_view value)
{
	double number{ 0 };
	std::from_chars(value.data(), value.data() + value.size(), number);
	return number;
}

void Spreadsheet::Cell::setColor(Color color)
{
	m_color = color;
}

Spreadsheet::Cell::Color Spreadsheet::Cell::getColor() const
{
	return m_color;
}

Spreadsheet::Cell Spreadsheet::Cell::add(const Spreadsheet::Cell& cell) const
{
	return Spreadsheet::Cell{ getValue() + cell.getValue() };
}

Spreadsheet::Cell Spreadsheet::Cell::operator + (const Spreadsheet::Cell& rhs)
{
	return Spreadsheet::Cell{ getValue() + rhs.getValue() };
}

Spreadsheet::Cell& Spreadsheet::Cell::operator +=(const Spreadsheet::Cell& rhs)
{
	m_value += rhs.m_value;
	return  *this;
}

Spreadsheet::Cell Spreadsheet::Cell::operator+(double rhs) const
{
	return Spreadsheet::Cell{ getValue() + rhs };
}

Spreadsheet::Cell Spreadsheet::Cell::operator+(std::string_view rhs) const
{
	return Spreadsheet::Cell{ getValue() + stringToDouble(rhs) };
}