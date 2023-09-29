#pragma once
#include <QWidget>
#include "statsGuiMain.h"
#include "risk.h"
#include "Cube.h"
#include <iostream>
#include  <QObject>
class menu : public QWidget {
	Q_OBJECT

public:
	menu(QWidget * parent = Q_NULLPTR);
	~menu();
private:
	Ui::menu ui;
	risk w;
	statsGuiMain s;
	Cube cubes[4];
	Player players[4];
	Player* hist[6][4];
	int numberOfPlayers;
	bool toss;
	bool defaultStats_;
private slots:
	void end();
	void spin(int);
	void cube();
	void LOAD();
	void loadStats();
	void defalutStats();

};
