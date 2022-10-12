#pragma once

#include <string_view>
#include <string>
#include <charconv>

class SpreadsheetCell
{
public:
	SpreadsheetCell() = default;
	SpreadsheetCell(double initialValue);
	SpreadsheetCell(std::string_view initialValue);
	SpreadsheetCell(const SpreadsheetCell& src);
	SpreadsheetCell& operator=(const SpreadsheetCell& rhs);
	void set(double value);
	void setValue(int) = delete;
	void setValue(double value);
	double getValue() const;
	void set(std::string_view value);
	std::string getString() const;
	static std::string doubleToString(double value) ;
	static double stringToDouble(std::string_view value) ;
private:
	double m_value{ 0 };
	mutable size_t m_numAccesses{ 0 };

};

