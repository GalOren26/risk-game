#pragma once
#include "Card.h"
#include <QtWidgets/QMainWindow>
#include <fstream>
#include <regex>
class Player {
public:
	Player(const std::string name = "default", const std::string color = "None", int order = 0, int id = -1);
	Player(const Player&);
	Player& operator=(const Player&);
	
	void cleanCards(std::vector<Card> cards);

	void addBonusTroops(const int);
	void setBonusTroops(const int);
	int getBonusTroops();

	std::string getName() const;
	void setName(std::string);
	int getId() const;
	void SetOrder(int);
	int GetOrder();
	void show();
	std::string& getColor();
	void save(std::ofstream& file);
	void load(std::ifstream& file);
	Card addCard();
	std::vector<Card> getCards();
private:
	int bonusTroops;
	int order;
	std::vector<Card> cards;
	std::string name;
	std::string color;
	int id;
};
