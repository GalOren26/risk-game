#include "PlayerStatWrap.h"
//getline(fileHandle, org, ' ');
PlayerStatWrap::PlayerStatWrap()
{
	this->timePlayed = 0;
	this->gamesPlayed = 1;
	this->wins = 0;
	this->looses = 0;
	this->id = 0;
}

PlayerStatWrap::PlayerStatWrap(const PlayerStatWrap & src)
{
	this->name = src.name;
	this->wins = src.wins;
	this->looses = src.looses;
	this->timePlayed = src.timePlayed;
	this->gamesPlayed = src.gamesPlayed;
	this->id = src.id;
}

PlayerStatWrap::PlayerStatWrap(const Player& player, int win, int elapsed_seconds)
{
	this->name = player.getName();
	if (win == 0) {
		this->wins = 0;
		this->looses = 0;
	}
	else if (win == 1) {
		this->wins = 1;
		this->looses = 0;
	}
	else if (win == -1) {
		this->wins = 0;
		this->looses = 1;
	}
	this->timePlayed = elapsed_seconds;
	this->gamesPlayed = 1;
	this->id = player.getId();
}

void PlayerStatWrap::loadStats(std::ifstream & file)
{
	std::string line;
	std::getline(file, line, ',');
	this->name = line;

	std::getline(file, line, ',');
	this->id = std::stoi(line);

	std::getline(file, line, ',');
	this->wins = std::stoi(line);

	std::getline(file, line, ',');
	this->looses = std::stoi(line);

	std::getline(file, line, ',');
	this->timePlayed = std::stoi(line);

	std::getline(file, line);
	this->gamesPlayed = std::stoi(line);

}

void PlayerStatWrap::saveStats(std::ofstream & file)
{
	file << this->name << ","
		<< this->id << ","
		<< this->wins << ","
		<< this->looses << ","
		<< this->timePlayed << ","
		<< this->gamesPlayed;
}
int PlayerStatWrap::get_timePlayed() const
{
	return this->timePlayed;
}

int PlayerStatWrap::get_gamesPlayed() const
{
	return this->gamesPlayed;
}

int PlayerStatWrap::get_wins() const
{
	return this->wins;
}

int PlayerStatWrap::get_looses() const
{
	return this->looses;
}

int PlayerStatWrap::get_id() const
{
	return this->id;
}

std::string PlayerStatWrap::get_name() const
{
	return this->name;
}

PlayerStatWrap & PlayerStatWrap::operator+(const PlayerStatWrap & src)
{
	this->wins += src.wins;
	this->looses += src.looses;
	this->timePlayed += src.timePlayed;
	this->gamesPlayed += src.gamesPlayed;
	return *this;
}

PlayerStatWrap & PlayerStatWrap::operator=(const PlayerStatWrap & src)
{
	this->name = src.name;
	this->wins = src.wins;
	this->looses = src.looses;
	this->timePlayed = src.timePlayed;
	this->gamesPlayed = src.gamesPlayed;
	this->id = src.id;
	return *this;
}
