#pragma once
#include <vector>

class DataHolder
{
public :
	void setData(const std::vector<int>& data) 
	{
		m_data = data;
	}

	void setData(const std::vector<int>&& data)
	{
		m_data = std::move(data);
	}

private :
	std::vector<int> m_data;
};