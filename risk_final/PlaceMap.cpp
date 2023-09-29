#include "PlaceMap.h"

PlaceMap::PlaceMap(Ui::my_riskClass & ui, Player & player,Move& moveUi , int& counter) : Stage(ui, player, moveUi), counter(counter)
{
}

PlaceMap::~PlaceMap()
{
	delete placed;
}

void PlaceMap::action()
{ 
	if (this->isMine() && Country::chosen->getTroops()) {
		this->ui.textEdit->setText(QString("At this stage you need to fill-up the map .."));
		this->EnterEn = false;
		return;
	}

	if (Country::chosen->getTroops()) {
		this->ui.textEdit->setText(QString("I see you got NA education .."));
		this->EnterEn = false;
		return;
	}
	this->EnterEn = true;
	Country::chosen->setOwner(this->player);
	Country::chosen->incTroops(1);
	this->placed = new QMediaPlayer();
	this->placed->setMedia(QUrl("qrc:/new/Resources/placed.wav"));
	this->placed->play();
	this->counter++;
	this->ui.textEdit->setText(QString("initial Country: ") + QString(Country::chosen->getName().c_str()) + QString(" by player: ") + QString(this->player.getName().c_str()));
	this->player.addBonusTroops(-1);

}

void PlaceMap::preAction()
{
	this->showTroops();
}

void PlaceMap::afterAction()
{
	this->showTroops();
}
