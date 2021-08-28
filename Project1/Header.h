#pragma once
#include <vector>

enum CardType { SIX, SEVEN, EIGHT, NINE, TEN, J, Q, K, T };
enum CardSuit { SPADE, DIAMOND, HEART, CLUB };

class Card
{
	CardType type;
	CardSuit suit;

public:
	Card() {}
	Card(CardType type, CardSuit suit) : type(type), suit(suit) {}

	bool operator < (const Card& other) const;
	void Print() const;
};

class CardDeck
{
	std::vector<Card> deck;	// оберіть контейнет для збереження карт

public:
	CardDeck() {}

	void InitDeck();
	void SortDeck();
	void ShuffleDeck();
	Card PickCard() const;
	Card PopCard();
	void PrintDeck() const;
};