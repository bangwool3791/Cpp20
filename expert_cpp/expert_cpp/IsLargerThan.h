#pragma once

class IsLargerThan
{
public :
	explicit IsLargerThan(int value) : m_value{ value } {}
	bool operator() (int value1, int value2) const
	{
		return value1 > m_value && value2 > m_value;
	}
private:
	int m_value;
};
