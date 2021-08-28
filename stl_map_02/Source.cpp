//Пример: данный пример демонстрирует методы //работы со отображениями
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void main()
{
	//создаем отображение
	map<int, int> our_map; // key_type - value_type
	//создаем вектор
	vector <int> our_vector;

	//максимальный размер вектора
	cout << "\n\nmax size of vector -->\t"
		<< our_vector.max_size() / sizeof(int);

	//максимальный размер отображения
	//(в два раза меньше т.к. для каждого элемента //нужно хранить два значения - пару).
	cout << "\n\nmax size of map -->\t" << our_map.max_size() / sizeof(int);
	cout << "\n\n-------------------------------\n";

	int val; int key;
	cout << "\nInput value : "; cin >> val;
	cout << "\nInput key : "; cin >> key;

	//создаем пару на основании двух значений.
	pair<int, int> element(key, val);
	//вставляем пару в отображение
	our_map.insert(element);
	our_map.insert(pair<int, int>(key, val));
	our_map.insert(make_pair(key, val));	

	//кол-во элементов в отображении
	cout << "\nCurrent element of map --> " << our_map.size() << endl;

	cout << "\n\n-------------------------------\n";
	cout << "\nInput value : "; cin >> val;
	cout << "\nInput key : "; cin >> key;

	
	// auto - авто виведення типа на основі типа отриманого значення
	pair<map<int, int>::iterator, bool> err = our_map.insert(make_pair(key, val));

	if (err.second == false)
	{
		//отработает в случае если в отображение 
		//не получилось добавить элемент
		//например если в отображении уже был
		//элемент с данным ключом.
		cout << "\nError !!!\n";
	}
	//кол-во элементов в отображении
	cout << "\nCurrent element of map --> " << our_map.size() << endl;

	auto d = 78u;

	// якщо елемент з таким індексом не існує, тоді він додається, якщо існує - оновлюється значення
	our_map[2000] = 202020;
	our_map[2000] = 200000;
	our_map[505] = 50050;

	//вывод всех элементов на экран
	//map<int, int>::iterator iter = our_map.begin();
	for (auto iter = our_map.begin(); iter != our_map.end(); ++iter)
	{
		cout << "\nKey --> " << iter->first << "\t\tValue --> " << iter->second;
	}
	cout << "\n---------------------------------\n";

	/*cout << our_map[20] << endl;
	our_map[20]++;
	cout << our_map[20] << endl;*/

	cout << "Element at 505 --> " << our_map.at(505);
	//our_map.emplace(20);
	//our_map.insert(3, 3);

	for (auto elem : our_map)
		cout << "\nKey --> " << elem.first << "\t\tValue --> " << elem.second;

	auto res = our_map.find(3000);
	cout << "\nKey --> " << res->first << "\t\tValue --> " << res->second;

	our_map.lower_bound(20);
	our_map.upper_bound(60);

	system("pause");
}