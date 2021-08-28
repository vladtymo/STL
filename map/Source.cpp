#include <iostream>
#include <map>
#include <string>
#include <list>
using namespace std;

struct ID
{
	int id;
	string name;

	ID() {}
	ID(int id, string name) : id(id), name(name)
	{

	}

	void Show() const
	{
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
	}

	bool operator < (const ID& other) const
	{
		return this->name < other.name;
	}
};

map<string, int>::iterator findByValue(map<string, int>& m, int value)
{	
	for (map<string, int>::iterator i = m.begin(); i != m.end(); ++i)
	{
		if (i->second == value)
		{
			return i;
		}
	}
	return m.end();
}

void main()
{
	//////////////////////////// map base
	map<string, int> m2;

	m2.insert(pair<string, int>("Valia", 3));
	auto result = m2.insert(make_pair("Olga", 4));

	// ["Valia", 3], ["Olga", 4] , ["Olga", 34] 

	if (result.second)
	{
		cout << "Added\n";		
	}
	else
	{
		cout << "Ignore\n";
	}
	cout << "Value: " << m2["Valia"] << endl;
	cout << "Value: " << m2["Olga"] << endl;

	// Search element
	map<string, int>::iterator it = m2.find("Olga");
	if (it == m2.end())
	{
		cout << "Not found.\n";
	}
	else
	{
		cout << "Found\n";

		cout << "Key: " << it->first << " Value: " << it->second << endl;
		it->second = 444;
		cout << "Value after edit with iterator: " << m2["Vasia"] << endl;
	}

	it = findByValue(m2, 3);
	if (it != m2.end())
		cout << "Key: " << it->first << " Value: " << it->second << endl;

	if (it != m2.end())
		m2.erase(it);

	for (auto i : m2)
	{		
		cout << "Key: " << i.first << " Value: " << i.second << endl;
		cout << "------------------\n";
	}

	m2["Kolya"] = 100500;

	for (auto i : m2)
	{
		cout << "Key: " << i.first << " Value: " << i.second << endl;
		cout << "------------------\n";
	}

	////////////////////////// map with struct
	map<ID, int> m;

	ID id1(1, "Taras");
	pair<ID, int> pair(id1, 100);
	m.insert(pair);

	m.insert(make_pair(ID(3, "Anna"), 200));
	m.insert(make_pair(ID(2, "Blabla"), 6335));

	m[ID(7, "Anna")] = 40;
	cout << "Anna: " << m[ID(7, "Anna")] << endl;

	for (auto i : m)
	{
		i.first.Show();
		cout << "Value: " << i.second << endl;
		cout << "------------------\n";
	}

	//////////////////////// dictionary
	setlocale(LC_CTYPE, "ukr");

	map<string, list<string>> dic;

	string word = "run";
	list<string> meanings = list<string>({"бігти", "започаткувати", "почати"});
	dic.insert(make_pair(word, meanings));

	dic.insert(make_pair("mind", list<string>({ "думка", "душа", "свідомість", "сенс" })));
	dic.insert(make_pair("bad", list<string>({ "лихо", "поганий", "борг", "дефіцит" })));
	dic.insert(make_pair("test", list<string>({ "mean1", "mean2", "mean3" })));

	for (string s : dic["mind"])
	{
		cout << s << " ";
	}	

	//////////////////// add translate
	string input = "";
	cout << "Enter word to add translatins: "; getline(cin, input);	

	if (dic.find(input) == dic.end())
		cout << "Word not found!\n";
	else
	{
		string translate = "";
		do
		{
			cout << "Enter translate: "; 
			getline(cin, translate);
			dic[input].push_back(translate);

		} while (!translate.empty());
	}

	////////////////////// check translate
	cout << "Enter word to translate: "; getline(cin, input);

	if (dic.find(input) == dic.end())
		cout << "Translate not found!\n";
	else
	{
		cout << "\tMeans:\n";
		for (string elem : dic[input])
			cout << elem << " ";
	}

	system("pause");
}