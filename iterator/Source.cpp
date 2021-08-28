#include <iostream>
#include <algorithm> // бібліотека для алгоритмів STL
#include <vector>
#include <list>
#include <iterator>
using namespace std;

//template <class T_ptr, class T_value>
//class base_iterator
//{
//protected:
//	T_ptr* ptr;
//public:
//	base_iterator() : ptr(0) {}
//	base_iterator(T_ptr* ptr) : ptr(ptr) {}
//
//	virtual base_iterator& operator ++ ()
//	{
//		++ptr;
//		return *this;
//	}
//	virtual base_iterator& operator ++ (int)
//	{
//		base_iterator tmp = *this;
//		++ptr;
//		return tmp;
//	}
//	virtual bool operator == (const base_iterator& other) const
//	{
//		return this->ptr == other.ptr;
//	}
//	virtual bool operator != (const base_iterator& other) const
//	{
//		return !(*this == other);
//	}
//	virtual T_value operator * () const = 0;
//};
//
//class List
//{
//	struct Node
//	{
//		int data;
//		Node * next;
//		Node(int data, Node* next = 0) : data(data), next(next) {}
//	};
//	Node *head, *tail;
//
//public:
//	class iterator : public base_iterator<Node, int>
//	{
//	public:
//		iterator() {}
//		iterator(Node* data) : base_iterator(data) {}
//
//		iterator& operator ++()
//		{
//			ptr = ptr->next;
//			return *this;
//		}
//		iterator& operator ++ (int)
//		{
//			iterator tmp = *this;
//			ptr = ptr->next;
//			return tmp;
//		}
//		int operator * () const
//		{
//			return ptr->data;
//		}
//	};
//
//	List() : head(0), tail(0)
//	{
//		for (int i = 1; i <= 5; ++i)
//			AddHead(i);
//	}
//
//	void AddHead(int value)
//	{
//		Node* n = new Node(value, head);
//
//		head = n;
//		if (!tail)
//			tail = head;
//	}
//
//	iterator Begin()
//	{
//		//return head;
//		return iterator(head);
//	}
//	iterator End()
//	{
//		//return tail->next;
//		return iterator(tail->next);
//	}
//};
//
////template <class T>
//class Array
//{
//	int* arr;
//	int size;
//public:
//	Array()
//	{
//		arr = new int[5]{ 1, 2, 3, 4, 5 };
//		size = 5;
//	}
//
//	class iterator : public base_iterator<int, int>
//	{
//	public:
//		iterator() {}
//		iterator(int* data) : base_iterator(data) {}
//
//		int operator * () const
//		{
//			return *ptr;
//		}
//	};
//
//	iterator Begin()
//	{
//		//return arr;
//		return iterator(arr);
//	}
//	iterator End()
//	{
//		//return &arr[size];
//		//return (arr + size + 1);
//		return iterator(arr + size);
//	}
//};

class MyClass
{
	int data;
public:
	MyClass() : data(0) {}
	MyClass(int data) : data(data) {}

	void Show() const
	{
		cout << data << endl;
	}

	void operator () () const
	{
		cout << "Show this...\n";
		Show();
	}
	void operator () (const MyClass& other) const
	{
		cout << "Show other...\n";
		other.Show();
		//other.data++;
	}
};

void Show(const int n)
{
	//n.Show();
	cout << n << endl;
}

//template <class T_ptr, typename T_value> 
//void Show(base_iterator<T_ptr, T_value> &iterBegin, base_iterator<T_ptr, T_value> &iterEnd)
//{
//	for (auto i = iterBegin; i != iterEnd; ++i)
//	{
//		cout << "Element: " << *i << endl;
//	}
//}


int main()
{	
	MyClass myClass = 33;
	MyClass myClass2 = 44;

	myClass(myClass2);

	vector<MyClass> v = { MyClass(1), 2, 3 };
	list<string> l2 = { "str1", "str2", "str3" };
	list<int> l = { 10, 20, 30 };

	vector<MyClass>::iterator vIter = v.begin();
	vIter++;
	vIter += (3 * 3);

	auto vIter2 = vIter;

	list<int>::iterator lIter = l.end();

	//myClass(myClass);

	for_each(l.begin(), l.end(), Show);
	//for_each(vIter, v.end(), myClass);


	//for_each(l.begin(), l.end(), Show);

	cout << Show; // адреса функції

	/*Array my_arr;
	List my_list;
	Show(my_arr.Begin(), my_arr.End());
	cout << endl;
	Show(my_list.Begin(), my_list.End());*/

	system("pause");
	return 0;
}