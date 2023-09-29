#pragma once
#include "Player.h"
#include "PlayerStatWrap.h"
#include <fstream>
#include "Vector.h"
class PlayerStats {
public:
	PlayerStats();

	template <typename T>
	struct Info {
		std::string owner;
		T value;
	};

	PlayerStats::Info<int> getMaxWins();
	PlayerStats::Info<int> getMaxLooses();
	PlayerStats::Info<int> getMaxTimePlayed();
	PlayerStats::Info<int> getMaxGamesPlayed();
	const Vector<PlayerStatWrap>& get_players();
	std::string getAvgTime();
	void loadStats(std::ifstream& file);
	void saveStats(std::ofstream& file);
	void addToStats(const PlayerStatWrap&);
	void clear();
	int size();
private:
	Vector<PlayerStatWrap> players;
	//std::vector<PlayerStatWrap> players;
	PlayerStats::Info<int> getMaxInt(int(*)(const PlayerStatWrap));

};

