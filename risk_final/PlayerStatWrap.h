#pragma once
#include "Player.h"
#include <chrono>
#include <fstream>
class PlayerStatWrap {
public:
	PlayerStatWrap();
	PlayerStatWrap(const PlayerStatWrap& src);
	PlayerStatWrap(const Player& player,int win, int elapsed_seconds);
	void loadStats(std::ifstream& file);
	void saveStats(std::ofstream& file);
	std::string get_name() const;
	int get_timePlayed() const;
	int get_gamesPlayed() const;
	int get_wins() const;
	int get_looses() const;
	int get_id() const;
	PlayerStatWrap& operator+(const PlayerStatWrap& src);
	PlayerStatWrap& operator=(const PlayerStatWrap& src);
private:
	int timePlayed;
	int gamesPlayed;
	int wins;
	int looses;
	int id;	//todo
	std::string name;
	//int maxTroops;
	//int maxCountries;

};