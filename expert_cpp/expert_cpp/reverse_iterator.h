#pragma once

#include "pch.h"


int main()
{
	vector vectorOne{ 1,2,3,4,5,6,7,8,9,10 };
	set<int> setOne;

	insert_iterator<set<int>> inserter{ setOne, begin(setOne) };
	myCopy(cbegin(vectorOne), cend(vectorOne), inserter);
	myCopy(cbegin(vectorOne), cend(vectorOne), insert_iterator{ setOne, begin(setOne) });
	myCopy(cbegin(setOne), cend(setOne), ostream_iterator<int>(cout, " "));
	return 0;
}

int main()
{
	vector myVector{ 11,22,33,22,11 };
	auto it1{ myFind(begin(myVector), end(myVector), 22) };
	auto it2{ myFind(rbegin(myVector), rend(myVector), 22) };

	if (it1 != end(myVector) && it2 != rend(myVector))
	{
		cout << format("Found at position {} going forward.", distance(begin(myVector), it1)) << endl;
		cout << format("Found at position {} going backward.", distance(begin(myVector), --it2.base())) << endl;
	}
	return 0;
}