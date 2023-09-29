#include "statsGuiMain.h"

statsGuiMain::statsGuiMain(QWidget * parent) : QWidget(parent)
{
	ui.setupUi(this);
}

statsGuiMain::~statsGuiMain()
{
	
}

void statsGuiMain::setStats(PlayerStats * stats)
{
	this->stats = stats;
	QString text;
	text = (QString)this->stats->getAvgTime().c_str() + "\n";
	this->ui.all_stats->setText(text);
	const Vector<PlayerStatWrap> & players = this->stats->get_players();
	ui.chosenStats_2->insertItem(0, "");
	for (int i = 0; i<players.size(); i++)
	{
		ui.chosenStats_2->insertItem(i+1, players[i].get_name().c_str());
	}
}

void statsGuiMain::clear()
{
	this->stats->clear();
}

void statsGuiMain::player_stats(int index)
{
	index = index--;
	const Vector<PlayerStatWrap> & players = this->stats->get_players();
	const PlayerStatWrap & player = players[index];
	std::string mes="The player: "+ player.get_name()+ "\n wins: " +std::to_string(player.get_wins()) + " times \n loose: " +
		std::to_string(player.get_looses()) + " times \n played: " +std::to_string(player.get_gamesPlayed()) +
		" games \n for time: "+ std::to_string(player.get_timePlayed()/60) +" min";
	this->ui.Info_2->setText(mes.c_str());
	this->ui.Info_2->selectAll();
	this->ui.Info_2->setFontPointSize(12);

}

void statsGuiMain::spin(int maxSel)
{
	PlayerStats::Info<int> info;
	QString text = "name: ";
	QString afer_text = "";
	switch (maxSel) {
	case 0://wins
		info = this->stats->getMaxWins();
		text = QString(info.owner.c_str()) + " got max wins of: ";
		break;
	case 1://losses
		info = this->stats->getMaxLooses();
		text = QString(info.owner.c_str()) + " got max losses of: ";
		break;
	case 2://games
		info = this->stats->getMaxGamesPlayed();
		text = QString(info.owner.c_str()) + " got max games of: ";
		break;
	case 3://time
		info = this->stats->getMaxTimePlayed();
		info.value /= 60;
		text = QString(info.owner.c_str()) + " got max game time of: ";
		afer_text = QString(" min");
		break;
	}
	
	
	text = text + QString(std::to_string(info.value).c_str())+ afer_text;
	this->ui.Info->setText(text);
}
