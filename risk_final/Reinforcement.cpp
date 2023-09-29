#include "Reinforcement.h"

Reinforcement::Reinforcement(Ui::my_riskClass & ui, Player & player, Move & moveUi) : Stage(ui, player, moveUi)
{
	this->setNextEn(true);
	this->ui.TROOPS->setVisible(false);
}

void Reinforcement::action()
{
	if (Country::chosen->getOwner().getName() != Country::chosen2->getOwner().getName() || !this->isMine()) {
		this->ui.textEdit->setText("Please choose 2 owned countries which are connected!");
		return;
	}
	if (!Country::chosen2->validPath(Country::chosen->getName())) {
		this->ui.textEdit->setText("Those countries are not connected!");
		return;
	}
	if (Country::chosen2->getTroops() == 1)
	{
		this->ui.textEdit->setText("you cant move troops from country that have inly 1 soilder!");
		return;
	}
	//pop up

	this->moveUi.setTo(Country::chosen);	//send to 
	this->moveUi.setFrom(Country::chosen2);	//send From 
	this->moveUi.setMax(Country::chosen2->getTroops() - 1);
	this->moveUi.setMin(1);
	this->moveUi.setFocus();
	this->moveUi.show();
}

void Reinforcement::preAction()
{

}

void Reinforcement::afterAction()
{
	this->ui.TROOPS->setVisible(true);
}
