#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class ID
{
	string name;
public:
	ID(string name) : name(name)
	{

	}

	string GetName() const { return name; }
	bool operator < (const ID& other) const
	{
		return this->name < other.name;
	}
};

int main()
{
	////////////////////////// map
	map<string, int> map_c;

	map_c["One"] = 1;
	map_c.insert(make_pair("One", 1));
	map_c.insert(make_pair("Four", 4));
	map_c.insert(make_pair("Zero", 0));
	map_c.insert(make_pair("Three", 3));
	map_c.insert(make_pair("Five", 5));

	cout << "------------Map-------------\n";
	for (auto i : map_c)
	{
		cout << "Item: " << i.first << "\tValue: " << i.second << endl;
	}

	//////////////////////// unordered map
	unordered_map<string, int> un_map_c;

	un_map_c["One"] = 1;
	un_map_c["Four"] = 4;
	un_map_c["Zero"] = 0;
	un_map_c["Three"] = 3;
	un_map_c["Five"] = 5;

	cout << "------------Unordered Map-------------\n";
	for (auto i : un_map_c)
	{
		cout << "Item: " << i.first << "\tValue: " << i.second << endl;
	}

	////////////////////////// multimap
	multimap<string, int> multimap_c;

	multimap_c.insert(make_pair("One", 1));
	multimap_c.insert(make_pair("One", 11));
	multimap_c.insert(make_pair("Four", 4));
	multimap_c.insert(make_pair("Four", 44));
	multimap_c.insert(make_pair("Three", 3));
	multimap_c.insert(make_pair("Three", 33));

	cout << "------------Find-------------\n";
	auto iter = multimap_c.find("One");
	while (iter != multimap_c.end())
	{
		cout << "Item: " << (*iter).first << "\tValue: " << (*iter).second << endl;
		++iter;
	}

	cout << "------------Multimap-------------\n";
	for (auto i : multimap_c)
	{
		cout << "Item: " << i.first << "\tValue: " << i.second << endl;
	}

	////////////////////////// set
	set<int, greater<int>> set_c;

	cout << "------------Set-------------\n";
	set_c.insert({ 1, 3, 2 });
	for_each(set_c.begin(), set_c.end(), [](int v) {cout << v << " "; }); 
	cout << endl;

	set_c.clear();
	set_c.insert({ 1, 1, 2, 2, 3, 3 });
	for_each(set_c.begin(), set_c.end(), [](int v) {cout << v << " "; });
	cout << endl;

	set_c.clear();
	set_c.insert({ 2, 2, 1, 1, 3, 3 });
	for_each(set_c.begin(), set_c.end(), [](int v) {cout << v << " "; });
	cout << endl;

	set<ID> set_id;

	set_id.insert({ ID("zero"), ID("first"), ID("second"), ID("zero"), ID("third")});
	for_each(set_id.begin(), set_id.end(), [](ID v) {cout << v.GetName() << " "; });
	cout << endl;

	////////////////////////// unordered set
	unordered_set<int> un_set_c;

	cout << "------------Unordered Set-------------\n";
	un_set_c.insert({ 1, 3, 2 });
	for_each(un_set_c.begin(), un_set_c.end(), [](int v) {cout << v << " "; });
	cout << endl;

	un_set_c.clear();
	un_set_c.insert({ 1, 1, 2, 2, 3, 3 });
	for_each(un_set_c.begin(), un_set_c.end(), [](int v) {cout << v << " "; });
	cout << endl;

	un_set_c.clear();
	un_set_c.insert({ 2, 2, 1, 1, 3, 3 });
	for_each(un_set_c.begin(), un_set_c.end(), [](int v) {cout << v << " "; });
	cout << endl;

	return 0;
}