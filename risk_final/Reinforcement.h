#pragma once
#include "Stage.h"
#include "Land.h"
#include "Player.h"
#include "Country.h"

class Reinforcement : public Stage {
public:
	Reinforcement(Ui::my_riskClass& ui, Player& player, Move& moveUi);

	void action();
	void preAction();
	void afterAction();



};