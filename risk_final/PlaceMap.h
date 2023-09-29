#pragma once
#include "Stage.h"
#include "Land.h"
#include "Player.h"
#include "Country.h"
#include "qmediaplayer.h"
class PlaceMap : public Stage {
public:
	PlaceMap(Ui::my_riskClass&, Player& player, Move& moveUi, int& counter);
	~PlaceMap();
	void action();
	void preAction();
	void afterAction();
private:
	int& counter;
	QMediaPlayer* placed;
};