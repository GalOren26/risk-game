#include "Land.h"

Land::Land()
{
	this->bonus = { 0,"no reason" };
}

Land::Land(std::vector<std::string> countries,Land::landInfo bonus)
{
	this->bonus = bonus;
	int size = countries.size();
	this->countries.reserve(size);

	for (auto iter : countries) {
		this->countries.push_back(Country(iter));
	}
}

Land & Land::operator=(Land &src)
{
	// TODO: insert return statement here
	this->countries = src.countries;
	this->bonus = src.bonus;
	return *this;
}


Land::landInfo Land::calcTroops(Player & player)
{
	landInfo res = { 0,"" };
	for (auto country : this->countries) {
		if (country.getOwner().getName() == player.getName())
			res.bonus++;
	}
	if (res.bonus == this->countries.size()) {
		res.bonus += this->bonus.bonus*3;
		res.reason += this->bonus.reason;
	}
	return res;
}

void Land::save(std::ofstream& file) const {
	for (auto country : this->countries) {
		country.save(file);
	}
}

void Land::load(std::ifstream & file, std::map<std::string, Player>& playersMap)
{

	for (int i = 0; i < this->countries.size();i++) {
		this->countries[i].load(file);
		if (countries[i].getOwner().getName() == "None")
			return;
		Player tmp = playersMap[countries[i].getOwner().getName()];
		countries[i].setOwner(tmp);
		countries[i].incTroops(0);
	}

}

Land::landInfo & operator+=(Land::landInfo & lhs, const Land::landInfo & rhs)
{
	lhs.reason += "\n" + rhs.reason;
	lhs.bonus += rhs.bonus;
	return lhs;
}
