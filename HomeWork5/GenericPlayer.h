#pragma once
#include <vector>
enum class cardSuits {
	heart,
	spade,
	cross,
	diamond
};
enum class cardValues {
	_A = 1,
	_2 = 2,
	_3 = 3,
	_4 = 4,
	_5 = 5,
	_6 = 6,
	_7 = 7,
	_8 = 8,
	_9 = 9,
	_10 = 10,
	_J = 10,
	_Q = 10,
	_K = 10
};

class Card
{
private:
	cardSuits _suit;
	cardValues _value;
	bool _position;
public:
	Card(cardSuits suit, cardValues value, bool position = false) : _suit(suit), _value(value), _position(position) {};

	void Flip() {
		_position = !_position;
	};

	int GetValue() const {
		if (!_position)
			return 0;
		return static_cast<int>(_value);
	};
};

class Hand
{
private:
	int const MAX_CARDS = 7;
	int const BJ = 21;
	int const ACE_ADDITION = 10;
protected:
	std::vector<Card*> _cards;
public:
	Hand() {
		_cards.reserve(MAX_CARDS);
	};

	void Add(Card& card) {
		_cards.push_back(&card);
	};

	void Clear() {
		for (auto card : _cards)
			delete card;
		_cards.clear();
	};

	int GetTotal() const {
		bool hasAce = false;
		int result = 0;
		for (auto card : _cards) {
			int cardValue = card->GetValue();
			if (cardValue == 1)
				hasAce = true;
			result += card->GetValue();
		};
		if (((result + ACE_ADDITION) <= BJ) && hasAce)
			result += ACE_ADDITION;
		return result;
	};

	virtual ~Hand() { Clear(); };
};

class GenericPlayer : Hand
{
private:
	std::string _name;
public:
	virtual bool IsHitting() = 0;
	bool IsBoosted() const { return GetTotal() > 21; };
	void Bust() { std::cout << _name << " has too much!" << std::endl; };
	virtual ~GenericPlayer() {};
};

