//библиотека для работы алгоритмов
#include <algorithm>
#include <iostream>
//библиотека контейнера списка
#include <list>
using namespace std;
/*
Функциональный объект, содержащий два поля:
1. для хранения значения приращения (delta)
2. для текущего значения генерируемого числа (current) */
class ValueGenerator
{
	int delta;
	int current;
public:
	/*
	Конструктор класса инициализирует значение приращения и текущее значение.
	Последнее может быть опущено, и тогда оно будет считаться равным 0
	*/
	ValueGenerator(int number, int from = 0) :delta(number), current(from) {}
	/*
	Основа функтора — перегруженный оператор вызова функции — прибавляет значение приращения
	к текущему генерируемому числу
	*/
	int operator()()
	{
		return current += delta;
	}
};
void Show(int num)
{
	cout << num << " ";
}

//Вывод заголовка для таблицы умножения.
void main()
{
	cout << "TABLE:" << "\n\n";
	cout << "----------" << "\n\n";
	for (int i = 1; i <= 10; i++)
	{
		//Cоздание контейнера-списка. 
		list<int> l(10);

		generate(l.begin(), l.end(), ValueGenerator(i));

		//Показ числа из контейнера-списка
		for_each(l.begin(), l.end(), Show);
	}
}

/*
1. Арифметические функторы:
	■ plus сложение x + y;
	■ minus вычитание x – y;
	■ multiplies умножение x × y;
	■ divides деление x / y;
	■ modulus взятие остатка x % y;
	■ negate обращение знака –x;
2. Функторы сравнения:
	■ equal_to равно x == y;
	■ not_equal_to не равно x != y;
	■ greater больше x > y;
	■ less меньше x < y;
	■ greater_equal больше или равно x => y;
	■ less_equal меньше или равно x <= y;
3. Логические функторы:
	■ logical_and логическое "и" x && y;
	■ logical_or логическое "или" x || y;
	■ logical_not логическое "не" ! x.
*/