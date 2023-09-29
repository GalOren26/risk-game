#include "PlayerStats.h"


PlayerStats::PlayerStats()
{

}

PlayerStats::Info<int> PlayerStats::getMaxWins()
{
	Info<int> res = { "" ,0 };
	for (int i = 0; i < this->players.size(); ++i) {
		if (this->players[i].get_wins() >= res.value) {
			res.value = this->players[i].get_wins();
			res.owner = this->players[i].get_name();
		}
	}
	return res;
}

void PlayerStats::loadStats(std::ifstream & file)
{
	while (file.eof() == false) {
		PlayerStatWrap res;
		res.loadStats(file);
		this->addToStats(res);
	}

}

void PlayerStats::saveStats(std::ofstream & file)
{
	for (int i = 0; i < this->players.size(); i++) {
		this->players[i].saveStats(file);
		if (i + 1 != this->players.size())
			file << "\n";
	}
}


void PlayerStats::addToStats(const PlayerStatWrap& playerWrap)
{
	for (int i = 0; i < this->players.size(); i++) {
		if (this->players[i].get_name() == playerWrap.get_name()) {
			this->players[i] = this->players[i] + playerWrap;
			return;
		}
	}
	this->players.push_back(playerWrap);
}

void PlayerStats::clear()
{
	this->players.clear();
}


int PlayerStats::size()
{
	return this->players.size();
}

PlayerStats::Info<int> PlayerStats::getMaxInt(int(*)(const PlayerStatWrap))
{
	return PlayerStats::Info<int>();
}

PlayerStats::Info<int> PlayerStats::getMaxLooses()
{
	Info<int> res = { "" ,0 };
	for (int i = 0; i < this->players.size(); ++i) {
		if (this->players[i].get_looses() >= res.value) {
			res.value = this->players[i].get_looses();
			res.owner = this->players[i].get_name();
		}
	}
	return res;
}

PlayerStats::Info<int> PlayerStats::getMaxTimePlayed()
{
	Info<int> res = { "" ,0 };
	for (int i = 0; i < this->players.size(); ++i) {
		if (this->players[i].get_timePlayed() >= res.value) {
			res.value = this->players[i].get_timePlayed();
			res.owner = this->players[i].get_name();
		}
	}
	return res;
}

PlayerStats::Info<int> PlayerStats::getMaxGamesPlayed()
{
	Info<int> res = { "" ,0 };
	for (int i = 0; i < this->players.size(); ++i) {
		if (this->players[i].get_gamesPlayed() >= res.value) {
			res.value = this->players[i].get_gamesPlayed();
			res.owner = this->players[i].get_name();
		}
	}
	return res;
}

const Vector<PlayerStatWrap>& PlayerStats::get_players()
{
	return this->players;
}


std::string PlayerStats::getAvgTime()
{
	int time = 0;
	for (int i = 0; i < this->players.size(); ++i) {	
			time += this->players[i].get_timePlayed();
	}
	return "the avg of time played in min is: " + std::to_string(time/ (60*this->players.size()));
}


