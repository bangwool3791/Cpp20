#pragma once
class Person
{
public :
	Person(string first, string last)
		:m_firstName{ move(first) }
		, m_lastName{ move(last) }
	{
	}

	const string& getFirstName() const { return m_firstName; }
	const string& getLastName() const { return m_lastName; }
private:
	string m_firstName;
	string m_lastName;
};

int main()
{
	vector persons{ Person {"John", "White"}, Person {"Chris", "Blue"} };
	//sort(begin(persons), end(persons));
	//ranges::sort(persons);

	//ranges::sort(persons, {}, [](const Person& person) {
	//	return person.getFirstName();
	//	});

	ranges::sort(persons, {}, &Person::getFirstName);
}