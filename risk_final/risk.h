#pragma once
#include "Player.h"
#include  <QObject>
#include "Country.h"
#define num_of_conutries 42
#define TOTAL_TROOPS 100
#define TROOP4COUNTRY 3
#include <QtWidgets/QMainWindow>
#include <QMediaPlayer>
#include "ui_my_risk.h"
#include "Qdebug.h"
#include <Qsignalmapper.h>
#include <utility>
#include <queue>
#include <fstream>
#include <qfiledialog.h>
#include <functional>
#include <iostream>
#include "Cube.h"
#include "Move.h"
#include "Stage.h"
#include "Attack.h"
#include "Draft.h"
#include "Reinforcement.h"
#include "PlaceMap.h"
#include "PlaceTroops.h"
#include "PlayerStats.h"
#include <chrono>
#include <ctime>
#include "Mess.h"
#define _maxCardsPerPlayer_ 5
class risk :public QMainWindow {
	Q_OBJECT
public:
	risk(int numberOfPlayers, QWidget *parent = 0);
	char get_number_of_player();
	void set_number_of_player(char num);
	void incPlayer();
	void initTroops();
	void showTroops();

	bool empty() const;
	void pop();
	void push(const Player&);

	void save(std::ofstream& file);
	void load(std::ifstream& file);
	PlayerStats* loadStats(std::string fileName = "Resources/stats.csv");
	void loadStatsGui();
	void showInfo();
	void updateStage();
	time_t get_startTime() const; 
	void set_startTime(const time_t);
private:
	std::queue<Player> queue;
	Land SouthAmerica, NorthAmerica, Europe, Asia, Australia, Africa;
	std::vector<QPushButton*> SA_buttons;
	std::vector<QPushButton*> NA_buttons;
	std::vector<QPushButton*> EU_buttons;
	std::vector<QPushButton*> AS_buttons;
	std::vector<QPushButton*> AU_buttons;
	std::vector<QPushButton*> AF_buttons;

	char numberOfPlayers;
	int numberOfCountries;	//set in ctor and does not change
	int troopsPerPlayer;
	int counter;	//counter in placeMap and placeTroops()
	bool newCard;
	std::vector<Card> cards;
	void cardClick(int sel = 0);

	std::string stage;
	Stage* currentStage;
	std::map<std::string, std::string> stage2preStage;
	PlayerStats stats;
	time_t startTime;
	void showMess(std::string);
	Mess mess;
	std::map<std::string, Player> playersMap;
	Move moveUi;
	void saveStatsIn(std::string = "Resources/stats.csv",bool all = 0);
public slots:
	bool LOAD();
	void SAVE();
	void ENTER();
	void SAVE_ALL();
	void saveStats();
	void EXIT();
	void nextState();

private:
	Ui::my_riskClass ui;
};