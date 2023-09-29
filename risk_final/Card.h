#pragma once
#include <QtWidgets/QMainWindow>
#include <QWidget>
#include <fstream>
#include "Qdebug.h"
#include "ui_my_risk.h"
#define _numberOfValidCards_ 5
class Card {
public:
	static void nextBonus();
	static int  getBonus();
	enum cardType { Joker, Solider, Cannon, Horse, Default };
	Card(cardType cardType = cardType::Default);
	Card(const Card&);
	Card& operator=(const Card&);
	bool operator==(const Card&) const;
	bool operator!=(const Card&) const;
	void setRand();
	void setButton(QPushButton*);
	void update();
	void save(std::ofstream& file) const;
	void load(std::ifstream& file);
	int maxTypes() const;
	int getType() const;
	void clean();
	bool isClicked() const;
private:
	std::string validType[_numberOfValidCards_];
	cardType type;
	QPushButton* button;
	bool clicked;
	static int bonus1;
	static int bonus2;
	static int bonus3;
public slots:
	void click();
};
