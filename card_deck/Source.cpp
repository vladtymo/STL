#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

//1. Створіть клас використовуючи STL, який буде імітувати колоду карт "CardDeck"
//2. Колода карт містить 36 унікальних карт
//3. Масті(Diamonds(діаманти), Spades(піки), Clubs(клуби), Hearts(серця))
//4. Клас колоди карт має принаймні кілька методів : InitializeDeck, PrintDeck, ShuffleDeck, PickCard, (отримує останню карту з колоди) PopCard(витягує останню карту),
//SortDeck включаючиконструктори, деструктори і тд.
//5. Використовуйте контейнери STL, методи(алгоритми) і ітератори, щоб поміщати, оперувати і друкувати картки на консоль
//6. Використовуйте алгоритми STL для створення та перемішування колоди карт.


enum Mast
{
	Diamonds,
	Spades,
	Clubs,
	Hearts
};

enum Type
{
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	J,
	Q,
	K,
	T
};

class Card
{
private:
	Mast mast;
	Type type;
public:
	Card() {}

	Card(Type type, Mast mast) : type(type), mast(mast) {}

	void SetSuitCard(Type type)
	{
		this->type = type;
	}

	void SetMastCard(Mast mast)
	{
		this->mast = mast;
	}

	void Print() const
	{
		cout << this->type << " - " << this->mast << endl;
	}


	static void PrintCard(Card card)
	{
		cout << setw(2);

		switch (card.type)
		{
		case Six:
			cout << "6";
			break;
		case Seven:
			cout << "7";
			break;
		case Eight:
			cout << "8";
			break;
		case Nine:
			cout << "9";
			break;
		case Ten:
			cout << "10";
			break;
		case J:
			cout << "J";
			break;
		case Q:
			cout << "Q";
			break;
		case K:
			cout << "K";
			break;
		case T:
			cout << "T";
			break;		
		}

		cout << " | ";

		switch (card.mast)
		{
		case Diamonds:
			wcout << L"\u2666";
			break;
		case Spades:
			cout << "S";
			break;
		case Clubs:
			cout << "C";
			break;
		case Hearts:
			cout << (unsigned char)'♥';
			break;		
		}

		cout << endl;
	}

	bool operator<(Card other)
	{
		if (this->type < other.type) 
			return true;
		else 
			return false;
	}
};


class CardGenerator
{
	Type t;
	Mast m;
public:
	CardGenerator(Type t = Six, Mast m = Mast::Diamonds) : t(t), m(m) {}

	Card operator()()
	{
		Card current(t, m);

		if (m != Mast::Hearts)
			m = static_cast<Mast>((int)m + 1);
		else
		{
			if (t == Type::T)
			{
				t = Type::Six;
				m = Mast::Diamonds;
			}
			else
			{
				m = Mast::Diamonds;
				t = static_cast<Type>((int)t + 1);
			}
		}

		return current;
	}
	
};

class CardDeck
{
	vector<Card> cards;
public:
	CardDeck() {}

	void InitializeDeck()
	{
		cards.resize(36);
		generate(cards.begin(), cards.end(), CardGenerator());

		/*for (auto c : cards)
			c.Print();*/

		/*for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 4; ++i)
			{
				cards.push_back(Card(static_cast<Type>(i), static_cast<Mast>(j)));
			}
		}*/
	}

	void ShuffleDeck()
	{
		random_shuffle(cards.begin(), cards.end());
	}

	void PrintDeck() const
	{
		for_each(cards.begin(), cards.end(), Card::PrintCard);
	}

	auto PickCard() // (отримує останню карту з колоди)
	{
		auto iter = cards.end() - 1;
		return iter;
	}

	Card PopCard()//(витягує останню карту)
	{
		Card c = cards.back();
		cards.pop_back();
		return c;
	}

	void Sort()
	{
		sort(cards.begin(), cards.end());
	}

	/*auto Init()
	{
		generate(cards.begin(), cards.end(), );
	}*/
};

int main()
{
	//Card::PrintCard(Card());	

	CardDeck card_deck;
	card_deck.InitializeDeck();
	card_deck.PrintDeck();
	cout << "\n---------------------------------------\n";

	card_deck.ShuffleDeck();
	card_deck.PrintDeck();
	cout << "\n---------------------------------------\n";

	system("pause");
	return 0;
}