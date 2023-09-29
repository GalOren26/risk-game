#include "Stage.h"

Stage::Stage(Ui::my_riskClass& ui,Player& player, Move& moveUi): ui(ui),player(player),moveUi(moveUi)
{
	this->nextEn = false;
	this->EnterEn = true;
}

bool Stage::getNexEn()
{
	return this->nextEn;
}

void Stage::setNextEn(const bool en)
{
	this->nextEn = en;
}

bool Stage::getEnterEn()
{
	return this->EnterEn;
}

void Stage::setEnterEn(const bool en)
{
	this->EnterEn = en;
}

void Stage::setPlayer(Player & player)
{
	this->player = player;
}

void Stage::showTroops()
{
	int bonus = this->player.getBonusTroops();
	QString text = std::to_string(bonus).c_str();
	this->ui.troopsP->setText(text);
}
int Stage::getBonusTroops(int sel)
{
	if (sel == 0) {
		std::string text = this->ui.troopsP->toPlainText().toStdString();
		return std::stoi(text);
	}
	else if (sel == 1) {
		std::string text = this->ui.troopsP_2->toPlainText().toStdString();
		return std::stoi(text);
	}
	return -1;
}

bool Stage::isMine(int sel)
{

	if (sel == 0) {
		if (Country::chosen->getOwner().getName() != this->player.getName()) {
			this->ui.textEdit->setText("not your country");
			return false;
		}
		return true;
	}
	else {
		if (Country::chosen2->getOwner().getName() != this->player.getName()) {
			this->ui.textEdit->setText("not your country");
			return false;
		}
		return true;
	}
}

void Stage::plus(int sel)
{
	
}

void Stage::minus(int sel)
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

