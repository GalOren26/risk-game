#pragma once
#include "Stage.h"
#include <qmediaplayer.h>
class Attack : public Stage {
public:
	Attack(Ui::my_riskClass&, Player& player, Move& moveUi, Card *);
	~Attack();
	void action();
	void preAction();
	void afterAction();
	void plus(int sel = 0);
	void minus(int sel = 0);
private:
	int newCard;
	Card* card;
	QMediaPlayer* boom;
};