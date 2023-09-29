#include "Card.h"
int Card::bonus1;
int Card::bonus2;
int Card::bonus3;
void Card::nextBonus()
{
	Card::bonus1 = Card::bonus2 + Card::bonus3;
	Card::bonus2 = Card::bonus1;
	Card::bonus3 = Card::bonus2;

}

int Card::getBonus()
{
	if (Card::bonus1 == 0) {
		Card::bonus1 = 3;
		Card::bonus2 = 2;
		Card::bonus3 = 1;
	}
	return Card::bonus1;
}

Card::Card(cardType type) : validType{ "Joker","Solider","Cannon","Horse","Default" }
{
	this->type = type;
	this->clicked = false;
}

Card::Card(const Card & src) : validType{ "Joker","Solider","Cannon","Horse","Default" }
{
	this->type = src.type;
	this->clicked = src.clicked;
}

Card & Card::operator=(const Card & src)
{
	this->type = src.type;
	this->clicked = src.clicked;
	return *this;
}

bool Card::operator==(const Card & rhs) const
{
	if (this->type == Joker || rhs.type == Joker)
		return true;
	
	return ((int)this->type == (int)rhs.type);
}

bool Card::operator!=(const Card & rhs) const
{
	if (this->type == Joker || rhs.type == Joker)
		return true;

	return !((int)this->type == (int)rhs.type);
}

void Card::setRand()
{
	int num = rand() % ((_numberOfValidCards_ - 1)*3 + 2);
	if (num != (_numberOfValidCards_ - 1) * 3 + 1) {	//chance of 1 to (_numberOfValidCards_ - 1)*3 and every other card chance of 1 to (_numberOfValidCards_ - 1)
		num = num % 3;
	}
	else {
		num = 0;
	}
	this->type = Card::cardType(num);	//= { "Joker","Solider","Cannon","Horse" };
}

void Card::setButton(QPushButton * button)
{
	this->button = button;
	
}

void Card::update()
{
	//QPixmap pic("Resources/cards/card"+ QString(this->validType[this->type].c_str()) + ".PNG");
	QString pic = "border-image:url(:/new/Resources/cards/card" + QString(this->validType[this->type].c_str()) + ".PNG);";
	//this->button->setIcon()
	this->button->setStyleSheet(pic);

	this->button->show();

}

void Card::click()
{
	if (this->type == Card::Default)
		return;

	QString pic;
	if (this->clicked) {
		this->clicked = false;
		pic = "border-image:url(:/new/Resources/cards/card" + QString(this->validType[this->type].c_str()) + ".PNG);";
	}
	else {
		this->clicked = true;
		pic = "border-image:url(:/new/Resources/cards/card" + QString(this->validType[this->type].c_str()) + "Shadow.PNG);";
	}

	//this->button->setIcon()
	this->button->setStyleSheet(pic);
}

void Card::save(std::ofstream & file) const
{
	file << this->validType[this->type] << "\n";
}

void Card::load(std::ifstream & file)
{
	std::string tmp;
	file >> tmp;
	if (tmp == "Solider")
		this->type = Solider;
	else if (tmp == "Cannon")
		this->type = Cannon;
	else if (tmp == "Horse")
		this->type = Horse;
	else if (tmp == "Jokerðö")
		this->type = Joker;
	else
		this->type = Default;
}

int Card::maxTypes() const
{
	return _numberOfValidCards_;
}

int Card::getType() const
{
	return int(this->type);
}

void Card::clean()
{
	QString pic = "border-image:url(:/new/Resources/cards/card" + QString(this->validType[Card::Default].c_str()) + ".PNG);";
	this->button->setStyleSheet(pic);
	this->clicked = false;
	this->type = Default;
	this->button->show();
}

bool Card::isClicked() const
{
	return this->clicked;
}
