#pragma once
#include "Stage.h"
#include "Land.h"
#include "Player.h"
#include "Country.h"

class PlaceTroops : public Stage {
public:
	PlaceTroops(Ui::my_riskClass&, Player& player, Move& moveUi,int& counter);

	void action();
	void preAction();
	void afterAction();

	void showInfo();
private:
	int& counter;

};