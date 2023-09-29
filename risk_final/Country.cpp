#include "Country.h"
#include <iostream>
#include <qpushbutton.h>
Country* Country::chosen;
Country* Country::chosen2;
void Country::init()
{
	if (!this->troops) {
		this->ui->textEdit->setText(QString(this->name.c_str()) + QString(" is a FREE country!"));
	}
	else
		this->ui->textEdit->setText(QString("ocupied") + QString(" by player: ") + QString(this->owner.getName().c_str()) + QString(" with: ") + QString(std::to_string(this->troops).c_str()));
	Country::chosen2 = Country::chosen;
	Country::chosen = this;
}


Country::Country(const std::string name, Player player)
{
	this->name = name;
	this->troops = 0;
	this->owner = player;

}

Country::Country(const Country & src)
{
	this->troops = src.troops;
	this->name = src.name;
	this->owner = src.owner;
	this->button = src.button;
}

Country & Country::operator=(Country &src)
{
	// TODO: insert return statement here
	this->troops = src.troops;
	this->name = src.name;
	this->owner = src.owner;
	this->button = src.button;
	return *this;
}

void Country::setButton(QPushButton* button) {
	this->button = button;
}

void Country::setOwner(const Player& owner)
{
	this->owner = owner;
	QString style = QString("background-color:") + this->owner.getColor().c_str();
	this->button->setStyleSheet(style);
}


void Country::save(std::ofstream& file) const {
	std::regex re("\\s+");
	std::string name = std::regex_replace(this->name, re, "_") ;
	file << name << "\n";
	file << this->troops << "\n";
	file << this->owner.getName() << "\n";
	file << "-----\n";
}

void Country::load(std::ifstream & file)
{
	file >> this->name;
	std::string tmp;
	file >> tmp;
	this->incTroops(std::stoi(tmp));
	std::string ownerName;
	file >> ownerName;
	this->owner.setName(ownerName);
	Country::chosen = this;
	std::string dummy;
	file >> dummy;
}

void Country::incTroops(int add)
{
	this->troops += add;
	if(add !=0)
		this->button->setText(QString(std::to_string(this->troops).c_str()));
}

bool Country::validPath(const std::string dest, std::map<std::string,bool>& seen)
{
	for (int i = 0; i < this->nehibors.size(); i++)
		if (this->nehibors[i]->name == dest) 
			return true;

	for (int i = 0; i < this->nehibors.size(); i++)
		if (seen.find(this->nehibors[i]->name) == seen.end()) {
			if (this->nehibors[i]->owner.getName() == this->owner.getName()) {
				seen[this->nehibors[i]->name] = true;
				if (this->nehibors[i]->validPath(dest, seen))
					return true;
			}
		}
	return false;
}

Player Country::getOwner() const
{
	return this->owner;
}

std::string Country::getName() const
{
	return std::string(this->name);
}

int Country::getTroops()
{
	return this->troops;
}

bool Country::isNear(std::string name) const
{
	for (int i = 0; i < this->nehibors.size(); i++)
		if (this->nehibors[i]->name == name)
			return true;
	
	return false;
}

void Country::setNehibors(std::vector<Country*> vec)
{
	this->nehibors.reserve(vec.size());
	for (int i = 0; i < vec.size(); i++) {
		this->nehibors.push_back(vec[i]);
	}
}


Ui::my_riskClass* Country::ui;
void Country::setUI(Ui::my_riskClass* ui) {
	Country::ui = ui;
}
