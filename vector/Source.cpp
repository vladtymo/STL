#include <iostream>
#include <vector>		// for vector
using namespace std;

#pragma region Train Station Template
struct Time
{
	short h, m, s;
};

class Train
{
	int number;
	Time departureTime;
	string destination;

	// oeprator <
};

class Railway
{
	vector<Train> trains;

public:
	// public methods
};
#pragma endregion

void PrintVector(vector<int> v)
{
	for (int item : v)
	{
		cout << item << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> v2 = { 10, 11, 12, 13 };

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " - ";
	}
	cout << endl;

	// видалення елементів
	v.erase(v.begin());		// видалити перший
	v.erase(v.end() - 1);	// видалити останній

	v.erase(v.begin() + 2, v.end() - 2);

	// вставка елементів
	v.insert(v.end(), 77);
	v.insert(v.begin(), 5, 10);
	v.insert(v.begin(), v2.begin(), v2.begin() + 2);

	// доступ до елемента по індексу
	v[0] = 999;

	// додавання елемента вкінець
	v.push_back(444);
	// видалення елемента з кінця
	v.pop_back();

	// обмін значеннями двох колекцій
	v.swap(v2);

	// зміна розміру колекції
	v.resize(12, 1);
	// видалення невикористаної пам'яті
	v.shrink_to_fit();

	// розмір колекції
	cout << "Size: " << v.size() << endl;
	// об'єм колекції (кількість виділеної пам'яті)
	cout << "Capacity: " << v.capacity() << endl;
	
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == 7)
		{
			v.insert(v.begin() + i + 1, 77);
		}
	}
	cout << endl;

	PrintVector(v);

	std::cin.get();
	return 0;
}