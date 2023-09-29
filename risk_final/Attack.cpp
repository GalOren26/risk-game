#include "Attack.h"

Attack::Attack(Ui::my_riskClass & ui, Player& player, Move& moveUi, Card* card) : Stage(ui,player,moveUi)
{
	this->newCard = false;
	this->card = card;
	this->setNextEn(true);
	this->ui.TROOPS_2->setVisible(true);
	this->boom = nullptr;
}

Attack::~Attack()
{
	delete this->boom;
}

void Attack::action()
{


	if (this->getBonusTroops() == 0 || this->getBonusTroops(1) == 0) {
		this->ui.textEdit->setText("I see you got NA education .. choose number of troops!");
		return;
	}


	//chosen2 attaker
	//chosen defender
	if (!this->isMine(1))//attacker is not me.
		return;
	if (this->isMine()) {	//country to attack is mine.
		this->ui.textEdit->setText("I see you got NA education .. you cannot attack yourself!");
		return;
	}
	if (!Country::chosen2->isNear(Country::chosen->getName())) {	//cannot attack un-near countries.
		this->ui.textEdit->setText("they are not near!");
		return;
	}


	//troops and countries are valid
	//attack logic --
	//make cubes according to troops.
	//random values.
	std::vector<Cube> attacker;
	std::vector<Cube> defender;

	attacker.reserve(this->getBonusTroops());
	for (int i = 0; i < this->getBonusTroops(); i++)
		attacker.push_back(Cube());
	attacker[0].setLabel(this->ui.cubeP_1);
	if (attacker.size() > 1)
		attacker[1].setLabel(this->ui.cubeP_2);
	if (attacker.size() > 2)
		attacker[2].setLabel(this->ui.cubeP_3);

	defender.reserve(this->getBonusTroops(1));
	for (int i = 0; i < this->getBonusTroops(1); i++)
		defender.push_back(Cube());
	defender[0].setLabel(this->ui.cubeP2_1);
	if (defender.size() > 1)
		defender[1].setLabel(this->ui.cubeP2_2);


	for (int i = 0; i < attacker.size(); i++)
		attacker[i].random();
	for (int i = 0; i < defender.size(); i++)
		defender[i].random();

	//std::sort(attacker.begin(), attacker.end(), [](const Cube& x, const Cube& y) {return x.get_rand_value() > y.get_rand_value(); });
	//std::sort(defender.begin(), defender.end(), [](const Cube& x, const Cube& y) {return x.get_rand_value() > y.get_rand_value(); });
	std::sort(attacker.begin(), attacker.end());//from small to big
	std::sort(defender.begin(), defender.end());
	int cnt = 0;
	if (std::min(attacker.size(), defender.size()) == 1)	//is 1 troop do the loop only once.
		cnt = 1;
	do {
		cnt++;
		if (attacker.back() > defender.back()) {	//attaker have to biggest cube.
			auto it = std::find_if(attacker.begin(), attacker.end(), [&](const Cube& x) {return x > defender.back(); });	//go from small to big.
			//del both cubes.
			attacker.erase(it);
			defender.pop_back();

			Country::chosen->incTroops(-1);		//erase from defender!
			this->minus(11);
		}
		else {									//else
			auto it = std::find_if(defender.begin(), defender.end(), [&](const Cube& x) {return (!(attacker.back() > x)); });	//go from small to big.
			//del both cubes.
			defender.erase(it);
			attacker.pop_back();

			Country::chosen2->incTroops(-1);		//erase from attaker!
			this->minus(10);
		}
	} while (this->getBonusTroops() && this->getBonusTroops(1) && cnt != 2);	//end if 2 loops or troops is empty.


	if (Country::chosen->getTroops())
		return;
	this->boom= new QMediaPlayer();
	 this->boom->setMedia(QUrl("qrc:/new/Resources/Explosion.wav"));
	this->boom->play();
	this->newCard = true;
	Country::chosen->setOwner(this->player);
	this->moveUi.setTo(Country::chosen);	//send to defender
	this->moveUi.setFrom(Country::chosen2);	//send From attaker
	this->moveUi.setMax(Country::chosen2->getTroops() - 1);
	this->moveUi.setMin(this->getBonusTroops());
	this->moveUi.setFocus();
	this->moveUi.show();
}

void Attack::preAction()
{
	this->ui.textEdit->setText("Please choose a country to attack and the number of troops to send");
	this->ui.troopsP->setText("1");
	this->ui.troopsP_2->setText("1");
}

void Attack::afterAction()
{
	if (this->newCard) {	//if new card update gui and player.
		this->newCard = false;
		Card tmp = this->player.addCard();
		*this->card = tmp;
		this->card->update();
	}
	this->ui.cubeP_1->hide();
	this->ui.cubeP_2->hide();
	this->ui.cubeP_3->hide();
	this->ui.cubeP2_1->hide();
	this->ui.cubeP2_2->hide();
	this->ui.cubeP2_3->hide();
	if (this->boom)
	{
		delete boom;
	}
	this->ui.TROOPS_2->setVisible(false);
}

void Attack::plus(int sel)
{
	if (sel == 0) {
		int number = this->getBonusTroops() + 1;
			if (number > 3 || number >= Country::chosen2->getTroops())
				this->ui.textEdit->setText("too many troops! sorry ..");
			else
				this->ui.troopsP->setText(std::to_string(number).c_str());
	}
	else if (sel == 1) {
		int number = this->getBonusTroops(1) + 1;

			if (number > 2 || number > Country::chosen->getTroops())
				this->ui.textEdit->setText("too many troops! sorry ..");
			else
				this->ui.troopsP_2->setText(std::to_string(number).c_str());
	}
}

void Attack::minus(int sel)
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
