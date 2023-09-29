#include "Mess.h"

Mess::Mess(QWidget *parent) :QWidget(parent)
{
	ui.setupUi(this);
}
Mess::~Mess()
{

}

void Mess::setMess(std::string str)
{
	this->ui.textEdit->setText(str.c_str());
	this->ui.textEdit->show();
}
