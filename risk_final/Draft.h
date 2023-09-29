#pragma once
#include "Stage.h"
#include "Land.h"
#include "Player.h"
#include "Country.h"
class Draft : public Stage {
public:
	Draft(Ui::my_riskClass&, Player& player, Move& moveUi, std::vector<Card>& cards,int _maxCardsPerPlayer);

	void setLands(std::vector<Land*> lands);
	void action();
	void preAction();
	void afterAction();
	void showBonusTroops(std::string);
	Land::landInfo calcTroops();
	void plus(int sel = 0);
	void minus(int sel = 0);
	void convert();
private:
	int newCard;
	std::vector<Card>& cards;
	std::vector<Land*> lands;
	int _maxCardsPerPlayer;

};