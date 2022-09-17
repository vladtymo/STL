#include <iostream>
#include <string>		// library for string
using namespace std;

int main()
{
	// Using string Constructors
	// —————————————————————————	

	//string one = string("Lottery Winner!");		// ctor #1
	//
	//cout << one << endl;						// overloaded <<
	//string two(20, '$');						// ctor #2
	//cout << two << endl;
	//string three(one);							// ctor #3
	//cout << three << endl;
	//one += " Oops!";							// overloaded +=
	//cout << one << endl;
	//two = "Sorry! That was ";
	//three[0] = 'P';								// overloaded []
	//string four;								// ctor #4
	//four = two + three;							// overloaded +, =
	//cout << four << endl;
	//char alls[] = "All's well that ends well";
	//string five(alls, 20);						// ctor #5
	//cout << five << "!\n";
	//string six(alls + 6, alls + 10);			// ctor #6
	//cout << six << ", ";
	//string seven(&five[6], &five[10]);			// ctor #6 again
	//cout << seven << "...\n";
	//string eight(four, 7, 16);					// ctor #7
	//cout << eight << " in motion!" << endl;

	//for (char i : one) // for (auto i = one.begin(); i != one.end(); i++)
	//{
	//	cout << i;
	//}

	// Using string Functions
	// —————————————————————————

	// Create strings
	const char c_str[] = "Hello";
	string str = "hello, world!";
	string str2 = "world";

	//// ----- Capacity -----	

	//// Size of allocated storage
	//cout << "Capacity: " << str.capacity() << endl;
	//// Length of string
	//cout << "Size/length: " << str.size() << " = " << str.length() << endl;

	//// Clear string
	//str.clear();

	//// Test if string is empty
	//if (str.empty())
	//	cout << "String is empty!" << endl;

	// ----- Element access -----	

	// Get character of string
	//str[0] = 'H';
	//cout << str[0] << endl;

	//// ----- Modifiers -----	

	//// Append to string
	//str.append(str.begin() + 3, str.end() - 2);
	//str.append(" end.");
	//str.append(c_str, 3);
	//str.append({ 'g', '5' });
	//
	//str += "ferg";
	//cout << str << endl;
	//
	//// Insert into string
	//str.insert(str.begin(), 4, 'H');
	//cout << str << endl;
	//cin.get();
	//
	//str.insert(0, 4, 'O');
	//cout << str << endl;
	//cin.get();
	//
	//str.insert(1, "ello");
	//cout << str << endl;
	//cin.get();
	//
	//str.insert(str.size() - 1, str2);
	//cout << str << endl;
	//cin.get();
	//
	//str.insert(0, c_str);
	//cout << str << endl;
	//cin.get();
	//
	//str.insert(str.end(), { '?', '!' });
	//cout << str << endl;
	//cin.get();

	// Erase characters from string
	/*str.erase(str.begin() + 1, str.end());
	str.erase(1, 3);
	str.erase(3);
	str.erase();*/

	// Replace portion of string
	// "yesae ighaeri bla aerhgiuae"
	/*str.replace(0, 5, "yes");
	cout << str << endl;*/

	// ----- String operations -----

	// Get C string equivalent
	const char* c_str2 = str.c_str();

	cout << "Str: " << str << endl;
	// Find content in string
	cout << "Index of first 'o' = " << str.find('o') << endl;

	if (str.find("Hello") == string::npos)
		cout << "Not found!" << endl;

	// Find last occurrence of content in string
	cout << "Index of last 'o' = " << str.rfind('o') << endl;	

	// Find character in string
	cout << "Found index: " << str.find_first_of("abcd") << endl;
	// Find character in string from the end
	cout << "Found index: " << str.find_last_of("abl") << endl;

	// Find absence of character in string
	cout << "Found index: " << str.find_first_not_of("Hello, world") << endl;
	// Find non - matching character in string from the end
	cout << "Found index: " << str.find_last_not_of("Hello, world") << endl;

	// Generate substring
	// "Hello, blabla world!"
	cout << "Substring: " << str.substr(7, 5) << endl;

	std::cin.get();
	return 0;
}