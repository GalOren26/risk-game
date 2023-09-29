#include "Player.h"

Player::Player(const std::string name, const std::string color, int order,int id)
{
	this->name = name;
	this->color = color;
	this->order = order;
	this->bonusTroops = -1;
	this->id = id;
}

Player::Player(const Player &src):cards(src.cards)
{
	this->name = src.name;
	this->color = src.color;
	this->order = src.order;
	this->bonusTroops = src.bonusTroops;
	this->id = src.id;
}

Player & Player::operator=(const Player & src)
{
	this->order = src.order;
	this->color = src.color;
	this->name = src.name;
	this->cards = src.cards;	//todo
	this->bonusTroops = src.bonusTroops;
	this->id = src.id;
	return *this;
}

void Player::cleanCards(std::vector<Card> cards)
{
	for (int i = 0; i < cards.size(); i++) {
		auto it = std::find_if(this->cards.begin(), this->cards.end(), [&](Card x) {return cards[i].getType() == x.getType(); });
		if (it != this->cards.end())
			this->cards.erase(it);
	}
}


void Player::addBonusTroops(const int bonus)
{
	this->bonusTroops += bonus;
}

void Player::setBonusTroops(const int bonus)
{
	this->bonusTroops = bonus;
}

int Player::getBonusTroops()
{
	return this->bonusTroops;
}


std::string Player::getName() const
{
	return this->name;
}

void Player::setName(std::string name)
{
	this->name = name;
}

int Player::getId() const
{
	return this->id;
}

std::string & Player::getColor()
{
	// TODO: insert return statement here
	return this->color;
}

void Player::save(std::ofstream& file)
{
	std::regex re("\\s+");
	file << std::regex_replace(this->name, re,"_") << "\n";
	file << this->id << "\n";
	file << this->order << "\n";
	file << this->color << "\n";
	file << this->bonusTroops << "\n";
	file << this->cards.size() << "\n";
	for (Card card : cards)
		card.save(file);
	file << "-------\n";

}

void Player::load(std::ifstream & file)
{
	file >> this->name;
	std::string tmp;
	file >> tmp;
	this->id = std::stoi(tmp);
	file >> tmp;
	this->order = std::stoi(tmp);
	file >> this->color;
	file >> tmp;
	this->bonusTroops = std::stoi(tmp);
	int numberOfCards;
	file >> tmp;
	numberOfCards = std::stoi(tmp);
	this->cards.reserve(numberOfCards);
	for (int i = 0; i < numberOfCards; i++) {
		Card tmp;
		tmp.load(file);
		this->cards.push_back(tmp);
	}
	std::string dummy;
	file >> dummy;
}

Card Player::addCard()
{
	Card tmp;
	tmp.setRand();
	this->cards.push_back(tmp);
	return tmp;
}

std::vector<Card> Player::getCards()
{
	return this->cards;
}


void Player::SetOrder(int order )
{
	this->order = order;
}

int Player::GetOrder()
{
	return this->order;
}

void Player::show()
{
	for (int i = 0; this->cards.size(); ++i)
		this->cards[i].update();
}
