#include "SpreadsheetCell.h"
#include "pch.h"

SpreadsheetCell::SpreadsheetCell(double initialValue)
	: m_value{ initialValue }
{

}

SpreadsheetCell::SpreadsheetCell(std::string_view initialValue)
	: m_value{ stringToDouble(initialValue) }
{
}

SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& src)
	: m_value{ src.m_value }
{
}

SpreadsheetCell& SpreadsheetCell::operator=(const SpreadsheetCell& rhs)
{
	if (this == &rhs) {
		return *this;
	}
	m_value = rhs.m_value;
	return *this;
}

void SpreadsheetCell::set(double value)
{
	m_value = value;
}

void SpreadsheetCell::setValue(double value)
{
	m_value = value;
}
double SpreadsheetCell::getValue() const
{
	m_numAccesses++;
	return m_value;
}

void SpreadsheetCell::set(std::string_view value)
{
	m_value = stringToDouble(value);
}

std::string SpreadsheetCell::getString() const
{
	m_numAccesses++;
	return doubleToString(m_value);
}

std::string SpreadsheetCell::doubleToString(double value) 
{
	return std::to_string(value);
}

double SpreadsheetCell::stringToDouble(std::string_view value) 
{
	double number{ 0 };
	std::from_chars(value.data(), value.data() + value.size(), number);
	return number;
}
