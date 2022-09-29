#pragma once
#include "pch.h"

class CEmployee
{
private:
	std::string m_LastName;
	std::string m_FirstName;
	float m_fSalary = 0.f;

public :
	CEmployee() = default;
	CEmployee(const std::string& _last, const std::string& _first)
		:m_LastName(_last)
		,m_FirstName(_first)
		,m_fSalary(100.f)
	{
		
	}
	~CEmployee() = default;

	float getSalary() const {
		return m_fSalary;
	}
};

//int main()
//{
	//int (CEmployee:: * methodPtr)() const { &CEmployee::getSalary };
	//CEmployee employee{ "John", "Doe" };
	//std::cout << (employee.*methodPtr)() << std::endl;

	//int (CEmployee::* methodPtr)() const { &CEmployee::getSalary };
	//CEmployee* employee = new CEmployee{ "John", "Doe" };
	//std::cout << (employee->*methodPtr)() << std::endl;

//	using PtrToGet = int (CEmployee::*)() const;
//	PtrToGet methodPtr{ &CEmployee::getSalary };
//	CEmployee employee{ "John", "Doe" };
//	std::cout << (employee.*methodPtr)() << std::endl;
//	return 1;
//}