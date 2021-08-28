#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <random>
#include <stack>
using namespace std;

class A
{
protected:
	int data;
public:
	A() : data(0) {}
	A(int data) : data(data) {}
	virtual void operator()() const
	{
		cout << "A - " << data << endl;
	}
};

class B : public A
{
public:
	B(int data) : A(data) {}
	void operator()() const
	{
		cout << "B - " << data << endl;
	}
};

void Func(A& obj)
{
	obj();
}

class MyClass
{
	int data;
public:
	MyClass() {}
	MyClass(int d) : data(d) {}

	void Show() const { cout << data << " "; }
	bool operator < (const MyClass& obj) const
	{
		return this->data < obj.data;
	}
};

int main()
{

	vector<MyClass> v = { 1, 2, 3, 4, 5 };
	stack<int> s;

	for (auto i : v)
		i.Show();
	cout << endl;

	srand(time(0));
	random_shuffle(v.begin(), v.end());

	random_device seed;
	mt19937 rnd(seed());
	shuffle(v.begin(), v.end(), rnd);

	for (auto i : v)
		i.Show();	
	cout << endl;



	sort(v.begin(), v.end());

	for (auto i : v)
		i.Show();	
	cout << endl;

	system("pause");
	return 0;
}