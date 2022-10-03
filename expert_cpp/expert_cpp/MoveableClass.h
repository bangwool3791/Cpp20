#pragma once
class MoveableClass
{
public:
	MoveableClass()
	{
		cout << "Defualt constructor" << endl;
	}

	MoveableClass(const MoveableClass& src)
	{
		cout << "Copy constructor" << endl;
	}

	MoveableClass(const MoveableClass&& src)noexcept
	{
		cout << "Move constructor" << endl;
	}

	MoveableClass& operator=(const MoveableClass& rhs)noexcept
	{
		cout << "Copy assignment operator" << endl;
		return *this;
	}

	MoveableClass& operator=(const MoveableClass&& rhs)noexcept
	{
		cout << "Move assignment operator" << endl;
		return *this;
	}
};

int main()
{
	vector<MoveableClass> vecSource;
	MoveableClass mc;
	vecSource.push_back(mc);
	vecSource.push_back(mc);
	vector<MoveableClass> vecOne{ cbegin(vecSource), cend(vecSource) };
	vector<MoveableClass> vecTwo{ make_move_iterator(begin(vecSource)), make_move_iterator(end(vecSource)) };
	return 0;
}

int main()
{
	vector data{ 33, 11, 22 };
	sort(begin(data), end(data));
	ranges::sort(data);
	return 0;
}

