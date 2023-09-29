#pragma once
#include "ui_stats.h"
#include "PlayerStats.h"
#include  <QObject>
class statsGuiMain :public QWidget {
	Q_OBJECT

public:
	statsGuiMain(QWidget * parent = Q_NULLPTR);
	~statsGuiMain();

	void setStats(PlayerStats* stats);
	void clear();
private:
	Ui::statsGui ui;
	PlayerStats* stats;
private slots:
	void spin(int);
	void player_stats(int);
};