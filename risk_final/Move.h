#pragma once
#include <QWidget>
#include "ui_move.h"
#include <iostream>
#include "Country.h"
#include  <QObject>
class Move : public QWidget {
	Q_OBJECT

public:
	Move(QWidget * parent = Q_NULLPTR);
	~Move();

	void setMax(int);
	void setMin(int);
	int getBonusTroops(int sel = 0);
	void setFrom(Country*);
	void setTo(Country*);
private:
	QWidget* father;
	Ui::Move ui;
	int min, max;
	Country* to;
	Country* from;
private slots:
	void plus(int sel = 0);
	void minus(int sel = 0);

	void end();
};