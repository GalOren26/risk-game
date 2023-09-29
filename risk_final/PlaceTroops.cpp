#include "PlaceTroops.h"

PlaceTroops::PlaceTroops(Ui::my_riskClass & ui, Player & player, Move & moveUi,int& counter) : Stage(ui, player, moveUi), counter(counter)
{
}

void PlaceTroops::action()
{
	if (!this->isMine())
	{
		this->ui.textEdit->setText(QString(Country::chosen->getName().c_str()) + QString(" isn't yours"));
		this->EnterEn = false;
		return;
	}
	this->EnterEn = true;
	this->counter++;
	this->ui.textEdit->setText(QString("add one troop at") + QString(Country::chosen->getName().c_str()) + QString(" to ") + QString(this->player.getName().c_str()));
	Country::chosen->incTroops(1);
	this->player.addBonusTroops(-1);
}


void PlaceTroops::preAction()
{
	this->showInfo();
	this->showTroops();
}

void PlaceTroops::afterAction()
{

}

void PlaceTroops::showInfo()
{
	QString picPath = QString("Resources/players/") + QString(this->player.getColor().c_str()) + ".png";
	QPixmap pic(picPath);//("Resources/cubes/1.png");
	this->ui.colorP->setPixmap(pic);
	this->ui.colorP->show();
}
