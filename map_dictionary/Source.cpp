#include <map>
#include <list>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


/* Collection:
	Key (first): string - Value (second): list<string>
	"Run" - "Bigty", "Stvoryvaty", ....
	"Day" - "Gaerha", "Stvoryvaty", ....
	"Good" - "Hae", "Feragaethr", ....
*/
class Dictionary
{
private:
	string name;
	map<string, list<string>> words;

	friend ostream& operator<<(ostream& os, const Dictionary& d);
	friend istream& operator>>(istream& is, Dictionary& d);
public:
	Dictionary(string name) : name(name) { }

	void PrintDictionary() const
	{
		cout << "\tDictionary: " << name << endl;
		cout << "_____________________________________\n";
		for (auto pair : words)
		{
			cout << pair.first << " - ";
			for (string t : pair.second)
			{
				cout << t << ", ";
			}
			cout << endl;
		}
	}

	void InsertWord(string word, initializer_list<string> translates)
	{
		words.insert(make_pair(word, list<string>(translates)));
	}
	bool IsExists(string word)
	{
		return words.find(word) != words.end();
	}
	void AddTranslation(string word, string translation)
	{
		words[word].push_back(translation);
	}
};
ostream& operator<<(ostream& os, const Dictionary& d)
{
	os << d.name << endl;
	for (auto pair : d.words)
	{
		os << pair.first << endl;
		for (string t : pair.second)
		{
			os << t << endl;
		}
		os << "-" << endl;
	}
	return os;
}
istream& operator>>(istream& is, Dictionary& d)
{
	char buff[255];
	string end = "-";
	getline(is, d.name); // d.name = string(buff);
	while (!is.eof())
	{
		string word;
		getline(is, word); // is >> word;
		if (word.empty()) break;
		list<string> list;
		string translate = end;
		do
		{
			getline(is, translate); // is >> translate;
			if (translate != end) list.push_back(translate);
		} while (translate != end);

		d.words.insert(make_pair(word, list));
	}
	return is;
}

int main()
{
	Dictionary d1("England-Ukrainian");

	d1.InsertWord("Create", { "Stvority", "Rozrobity" });
	d1.InsertWord("Good", { "Dobre" });
	d1.InsertWord("Run", { "Bigty", "Pochaty", "Zapochatkyvaty" });

	d1.PrintDictionary();

	// add translation from keyboard
	string input = "";
	cout << "Enter word to add translatins: "; getline(cin, input);

	if (!d1.IsExists(input))
		cout << "Word not found!\n";
	else
	{
		string translate = "";
		do
		{
			cout << "Enter translate: ";
			getline(cin,	translate);
			if (!translate.empty())
				d1.AddTranslation(input, translate);

		} while (!translate.empty());
	}

	d1.PrintDictionary();

	/////////// write to file
	ofstream fs("dictionary.txt", ios_base::trunc);
	fs << d1;
	fs.close();

	/////////// read from file
	ifstream ifs("dictionary.txt");
	Dictionary d2("");
	ifs >> d2;
	d2.PrintDictionary();

	return 0;
}