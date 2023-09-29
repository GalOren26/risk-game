#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_my_risk.h"
#include "Player.h"
#include "Country.h"
#include "Cube.h"
#include "Move.h"
class Stage {
public:
	Stage(Ui::my_riskClass&, Player& player, Move& moveUi);
	virtual void preAction()=0;
	virtual void action()=0;
	virtual void afterAction()=0; 
	virtual void plus(int sel = 0);
	virtual void minus(int sel = 0);
	void showTroops();
	bool getNexEn();
	void setNextEn(const bool en);
	bool getEnterEn();
	void setEnterEn(const bool en);
	void setPlayer(Player&);
protected:
	int getBonusTroops(int sel = 0);
	bool isMine(int sel = 0);

protected:
	Ui::my_riskClass& ui;
	Move& moveUi;
	Player& player;
	bool nextEn;
	bool EnterEn; 



};

