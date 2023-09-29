#include "Move.h"

Move::Move(QWidget * parent) : QWidget(parent){
	ui.setupUi(this);
	this->min = 1;
	this->max = 1;
	this->to = nullptr;
	this->from = nullptr;
	this->ui.troopsP->setText("1");
	this->ui.ENTER->show();
	this->ui.MINUS->show();
}
Move::~Move()
{

}

void Move::setMax(int max)
{
	this->max = max;
}

void Move::setMin(int min)
{
	this->min = min;
	this->ui.troopsP->setText(std::to_string(min).c_str());
}

int Move::getBonusTroops(int sel)
{
	std::string text = this->ui.troopsP->toPlainText().toStdString();
	return std::stoi(text);
}

void Move::setFrom(Country * from)
{
	this->from = from;
}

void Move::setTo(Country * to)
{
	this->to = to;
}


void Move::end() {
	this->to->incTroops(this->getBonusTroops());
	this->from->incTroops((-1)*(this->getBonusTroops()));
	this->close();
	//this->father->setFocus();
	
}

void Move::plus(int sel)
{
	int number = this->getBonusTroops() + 1;
	if(number <= this->max)
		this->ui.troopsP->setText(std::to_string(number).c_str());
}

void Move::minus(int sel)
{
	int number = this->getBonusTroops() - 1;
	if (number >= this->min)
		this->ui.troopsP->setText(std::to_string(number).c_str());
}
