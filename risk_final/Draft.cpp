#include "Draft.h"

Draft::Draft(Ui::my_riskClass & ui, Player& player, Move& moveUi, std::vector<Card>& cards, int _maxCardsPerPlayer_) : Stage(ui, player, moveUi), cards(cards)
{
	this->cards = cards;
	this->_maxCardsPerPlayer = _maxCardsPerPlayer_;
	this->ui.textEdit->setText(QString("welcome to stage draft you need to place all your troops in this stage:"));
}

void Draft::setLands(std::vector<Land*> lands)
{
	this->lands = lands;
}
void Draft::action()
{
	if (!this->isMine() || this->EnterEn == false)
		
		return;
	
	this->ui.textEdit->setText(
		"add" + QString(std::to_string(this->getBonusTroops()).c_str()) + " number of troops at: "
		+ Country::chosen->getName().c_str() + " to: " + this->player.getName().c_str());
	Country::chosen->incTroops(this->getBonusTroops());
	this->player.addBonusTroops((-1)*this->getBonusTroops());
	this->showTroops();
	if (this->player.getBonusTroops() == 0) {
		this->nextEn = true;
		this->EnterEn = false;
	}
}

void Draft::preAction()
{
	Land::landInfo info = this->calcTroops();
	if (info.bonus == 0)
	{
		this->nextEn = true;
	}
	this->player.setBonusTroops(info.bonus);
	this->showBonusTroops(info.reason);
	std::vector<Card> cards = this->player.getCards();
	for (int i = 0; i < 5; i++)	//todo const
		if (i < cards.size())
			this->cards[i] = cards[i];
		else
			this->cards[i] = Card();

	for (int i = 0; i < _maxCardsPerPlayer; i++)
		this->cards[i].update();
}

void Draft::afterAction()
{
	if (this->player.getCards().size() == _maxCardsPerPlayer) {
		this->ui.textEdit->setText("You must convert cards to troops!");
		this->nextEn = false;
	}
}

void Draft::showBonusTroops(std::string reason)
{
	this->ui.troopsP->setText(std::to_string(this->player.getBonusTroops()).c_str());
	if (reason == "")
		this->ui.textEdit->append("no land is yours!");
	else
		this->ui.textEdit->append(reason.c_str());
}

Land::landInfo Draft::calcTroops()
{
	Land::landInfo info = { 0,"" };
	for (std::vector<Land*>::iterator it = lands.begin(); it != lands.end(); ++it)
		info += (*it)->calcTroops(this->player);

	if (info.bonus == 0) {
		info.bonus = -1;
		return info;
	}
	info.bonus /= 3;
	if (info.bonus < 3)
		info.bonus = 3;
	return info;
}

void Draft::plus(int sel)
{
	if (sel == 0) {
		int number = this->getBonusTroops() + 1;
		if (number <= this->player.getBonusTroops())
			this->ui.troopsP->setText(std::to_string(number).c_str());
		else
			this->ui.textEdit->setText("too many troops! sorry ..");
	}
	else if (sel == 1) {
		int number = this->getBonusTroops(1) + 1;
		if (number <= this->player.getBonusTroops())
			this->ui.troopsP_2->setText(std::to_string(number).c_str());
		else
			this->ui.textEdit->setText("too many troops! sorry ..");
	}
}

void Draft::minus(int sel)
{
	bool force = false;
	if (sel >= 10) {
		force = 1;
		sel %= 10;
	}
	if (sel == 0) {
		int number = this->getBonusTroops() - 1;
		if (number > 0 || force)
			this->ui.troopsP->setText(std::to_string(number).c_str());
		else
			this->ui.textEdit->setText("I see you got NA education ...");
	}
	else if (sel == 1) {
		int number = this->getBonusTroops(1) - 1;
		if (number > 0 || force)
			this->ui.troopsP_2->setText(std::to_string(number).c_str());
		else
			this->ui.textEdit->setText("I see you got NA education ...");
	}
}

void Draft::convert()
{
	std::vector<Card> cards;
	for (int i = 0; i < this->cards.size(); i++) {	//3 same type
		if (this->cards[i].getType() != Card::Default && this->cards[i].isClicked()) {
			cards.push_back(this->cards[i]);
		}
	}
	if (cards.size() != 3) {
		this->ui.textEdit->setText("no matching cards for convert! choose 3 valid cards! ");
		return;
	}

	if (cards[0] == cards[1] && cards[0] == cards[2]) {
		//check tripple of the same type / joker type.
		for (int i = 0; i < cards.size(); i++) {
			auto it = std::find_if(this->cards.begin(), this->cards.end(), [&](Card x) {return cards[i].getType() == x.getType(); });
			if (it != this->cards.end())
				it->clean();
		}
		this->player.cleanCards(cards);
		int bonus = Card::getBonus();
		this->player.addBonusTroops(bonus);
		Card::nextBonus();
		this->ui.troopsP->setText(std::to_string(this->player.getBonusTroops()).c_str());
		this->ui.textEdit->setText("N1! get bonus of " +
			QString(std::to_string(bonus).c_str())+
			" troops!");
		this->EnterEn = true;
	}
	else if(cards[0] != cards[1] && cards[0] != cards[2] && cards[1] != cards[2]){
		//check tripple of diffrent types.
		for (int i = 0; i < cards.size(); i++) {
			auto it = std::find_if(this->cards.begin(), this->cards.end(), [&](Card x) {return cards[i].getType() == x.getType(); });
			if (it != this->cards.end())
				it->clean();
		}
		this->player.cleanCards(cards);
		int bonus = Card::getBonus();
		this->player.addBonusTroops(bonus);
		Card::nextBonus();
		this->ui.troopsP->setText(std::to_string(bonus).c_str());
		this->EnterEn = true;
	}
	else {
		this->ui.textEdit->setText("no matching cards for convert! choose 3 valid cards! ");
		return;
	}
	this->ui.value_cards->setText(std::to_string(Card::getBonus()).c_str());
}
