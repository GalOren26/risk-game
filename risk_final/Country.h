#pragma once
#include "Player.h"
#include <QtWidgets/QMainWindow>
#include "ui_my_risk.h"
#include <string.h>
#include <functional>
#include <fstream>
#include  <QObject>
class Country :public QMainWindow {
	Q_OBJECT
public:
	void setButton(QPushButton*);
	static Country* chosen;
	static Country* chosen2;

	static void setUI(Ui::my_riskClass*);
	Country(const std::string, Player player = Player());
	Country(const Country &);
	Country();
	Country& operator=(Country&);

	void setOwner(const Player&);
	void incTroops(int);

	bool validPath(const std::string, std::map<std::string, bool>& seen = std::map<std::string, bool>());
	Player getOwner() const;
	std::string getName() const;
	int getTroops();

	bool isNear(std::string) const;
	void setNehibors(std::vector<Country*>);

	void save(std::ofstream& file) const;
	void load(std::ifstream& file);
public slots:
	void init();
private:
	static Ui::my_riskClass* ui;	//class member
	int troops;
	std::string name;
	Player owner;
	QPushButton* button;
	std::vector<Country*> nehibors;
};