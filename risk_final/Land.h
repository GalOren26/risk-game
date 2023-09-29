#pragma once
#include "Player.h"
#include "Country.h"
class Land {
public:
	Land();
	Land& operator=(Land&);
	struct landInfo {
		int bonus;
		std::string reason;
	};
	

	Land(std::vector<std::string>, Land::landInfo);
	Land::landInfo calcTroops(Player&);
	Land::landInfo bonus;

	void save(std::ofstream& file) const;
	void load(std::ifstream& file, std::map<std::string, Player>& playersMap);
public:
	std::vector <Country> countries;
};


Land::landInfo& operator+=(Land::landInfo&, const Land::landInfo&);