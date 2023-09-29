#include "risk.h"

risk::risk(int numberOfPlayers, QWidget *parent) :troopsPerPlayer(TOTAL_TROOPS / numberOfPlayers), QMainWindow(parent), cards{ Card::cardType::Default, Card::cardType::Default, Card::cardType::Default, Card::cardType::Default,Card::cardType::Default }
{
	ui.setupUi(this);

	//SouthAmerica, NorthAmerica, Europe, Asia, Australia, Africa;
	Country::setUI(&this->ui);
	newCard = false;
	this->numberOfPlayers = numberOfPlayers;
	this->counter = 0;
	this->stage = "placeMap";
	QObject::connect(this->ui.ENTER, &QPushButton::clicked, [=] {ENTER(); });
	QObject::connect(this->ui.STATS, &QPushButton::clicked, [=] {saveStats();});
	
	//this->currentStage->setNextEn(true);
	stage2preStage["placeMap"] = "initial";
	stage2preStage["placeTroops"] = "placeMap";
	stage2preStage["draft"] = "placeTroops";
	stage2preStage["attack"] = "draft";
	stage2preStage["reinforcement"] = "attack";
	stage2preStage["default"] = "reinforcement";


	this->cards[0].setButton(this->ui.card1);
	this->cards[1].setButton(this->ui.card2);
	this->cards[2].setButton(this->ui.card3);
	this->cards[3].setButton(this->ui.card4);
	this->cards[4].setButton(this->ui.card5);
	this->ui.cubeP_1->hide();
	this->ui.cubeP_2->hide();
	this->ui.cubeP_3->hide();
	this->ui.cubeP2_1->hide();
	this->ui.cubeP2_2->hide();
	this->ui.cubeP2_3->hide();
	this->ui.TROOPS_2->setVisible(false);

	///////////////////////////////    SA    ///////////////////////////////
	std::vector< std::string> SA{ "Venezuela","Brazil","Peru","Argentina" };
	this->SouthAmerica = Land(SA, { 2,"WellDone you conquered SouthAmerica(+2)" });

	this->SA_buttons.reserve(SA.size());
	this->SA_buttons = {
		this->ui.south_america_1 ,this->ui.south_america_2 ,this->ui.south_america_3,
		this->ui.south_america_4
	};

	for (int i = 0; i < this->SA_buttons.size(); ++i) {
		SouthAmerica.countries[i].setButton(this->SA_buttons[i]);
		QObject::connect(this->SA_buttons[i], &QPushButton::clicked, [=] {SouthAmerica.countries[i].init(); });
	}

	///////////////////////////////    NA    ///////////////////////////////
	std::vector< std::string> NA{ "Alaska","Northwest Territory","Greenland","Alberta","ontario","Quebec","Western United States","Eastern United States","Central America" };
	this->NorthAmerica = Land(NA, { 5 ,"WellDone you conquered NorthAmerica (+5) - about 7.5% of the world's population\n"});

	this->NA_buttons.reserve(NA.size());
	this->NA_buttons = {
		this->ui.north_america_1 ,this->ui.north_america_2 ,this->ui.north_america_3,
		this->ui.north_america_4 ,this->ui.north_america_5 ,this->ui.north_america_6,
		this->ui.north_america_7 ,this->ui.north_america_8 ,this->ui.north_america_9
	};

	for (int i = 0; i < this->NA_buttons.size(); ++i) {
		NorthAmerica.countries[i].setButton(this->NA_buttons[i]);
		QObject::connect(this->NA_buttons[i], &QPushButton::clicked, [=] {NorthAmerica.countries[i].init(); });
	}

	///////////////////////////////    AF    ///////////////////////////////
	std::vector< std::string> AF{ "North Africa" ,"Egypt" ,"Cango" ,"East Africa","South Africa","Madagascar" };
	this->Africa = Land(AF,{3, "WellDone you conquered Africa(+3)"});

	this->AF_buttons.reserve(AF.size());
	this->AF_buttons = {
		this->ui.africa ,this->ui.africa_2 ,this->ui.africa_3,
		this->ui.africa_4 ,this->ui.africa_5 ,this->ui.africa_6
	};

	for (int i = 0; i < this->AF_buttons.size(); ++i) {
		Africa.countries[i].setButton(this->AF_buttons[i]);
		QObject::connect(this->AF_buttons[i], &QPushButton::clicked, [=] {Africa.countries[i].init(); });
	}

	///////////////////////////////    EU    ///////////////////////////////
	std::vector< std::string> EU{ "Iceland","Great Berlin","Scandinavia","Western Europe" ,"Soutern Europe" ,"Northern Europe" ,"Ukraine" };
	this->Europe = Land(EU, { 5,"WellDone you conquered Europe (+5), did you know 28 of the European states belong to the European Union?" });

	this->EU_buttons.reserve(EU.size());
	this->EU_buttons = {
		this->ui.europe_1 ,this->ui.europe_2 ,this->ui.europe_3,
		this->ui.europe_4 ,this->ui.europe_5 ,this->ui.europe_6,this->ui.europe_7
	};

	for (int i = 0; i < this->EU_buttons.size(); ++i) {
		Europe.countries[i].setButton(this->EU_buttons[i]);
		QObject::connect(this->EU_buttons[i], &QPushButton::clicked, [=] {Europe.countries[i].init(); });
	}

	///////////////////////////////    AS    ///////////////////////////////
	std::vector< std::string> AS{ "Kamchatka","Yakutsk","Siberia","Irkutsk" ,"Mongolia" ,"China" ,"India","Siam","Ural","Afghanistan","Middle East","Japan" };
	this->Asia = Land(AS,{7, "WellDone you conquered Asia (+5)(+7)"});

	this->AS_buttons.reserve(AS.size());
	this->AS_buttons = {
		this->ui.asia ,this->ui.asia_2,this->ui.asia_3,this->ui.asia_4,this->ui.asia_5,
		this->ui.asia_6 ,this->ui.asia_7 ,this->ui.asia_8,this->ui.asia_9,this->ui.asia_10,this->ui.asia_11, this->ui.asia_12
	};

	for (int i = 0; i < this->AS_buttons.size(); ++i) {
		Asia.countries[i].setButton(this->AS_buttons[i]);
		QObject::connect(this->AS_buttons[i], &QPushButton::clicked, [=] {Asia.countries[i].init(); });
	}
	///////////////////////////////    AU    ///////////////////////////////
	std::vector< std::string> AU{ "Western Australia" ,"Eastern Australia" ,"New Gulinea" ,"Indonesia" };
	this->Australia = Land(AU, { 2,"WellDone you conquered Australia (+2)" });

	this->AU_buttons.reserve(AU.size());
	this->AU_buttons = {
		this->ui.australia ,this->ui.australia_2,
		this->ui.australia_3,this->ui.australia_4
	};
	for (int i = 0; i < this->AU_buttons.size(); ++i) {
		Australia.countries[i].setButton(this->AU_buttons[i]);
		QObject::connect(this->AU_buttons[i], &QPushButton::clicked, [=] {Australia.countries[i].init(); });
	}
	this->numberOfCountries = AU.size() + AS.size() + NA.size() + SA.size() + AF.size() + EU.size();
	//set neihbors
	/*
	*/
	// in order to orginaze the connection easily we map the country names temprarly to pointer to their objects.

	std::map<std::string, Country*> m;
	m["Alaska"] = &(this->NorthAmerica.countries[0]);
	m["Alberta"] = &(this->NorthAmerica.countries[3]);
	m["Central America"] = &(this->NorthAmerica.countries[8]);
	m["Eastern United States"] = &(this->NorthAmerica.countries[7]);
	m["Greenland"] = &(this->NorthAmerica.countries[2]);
	m["Northwest Territory"] = &(this->NorthAmerica.countries[1]);
	m["Ontario"] = &(this->NorthAmerica.countries[4]);
	m["Quebec"] = &(this->NorthAmerica.countries[5]);
	m["Western United States"] = &(this->NorthAmerica.countries[6]);

	/////////////////
	m["Argentina"] = &(this->SouthAmerica.countries[3]);
	m["Brazil"] = &(this->SouthAmerica.countries[1]);
	m["Peru"] = &(this->SouthAmerica.countries[2]);
	m["Venezuela"] = &(this->SouthAmerica.countries[0]);
	///////////////////
	m["Great Britain"] = &(this->Europe.countries[1]);
	m["Iceland"] = &(this->Europe.countries[0]);
	m["Northern Europe"] = &(this->Europe.countries[5]);
	m["Scandinavia"] = &(this->Europe.countries[2]);
	m["Southern Europe"] = &(this->Europe.countries[4]);
	m["Ukraine"] = &(this->Europe.countries[6]);
	m["Western Europe"] = &(this->Europe.countries[3]);
	//////////////
	m["Cango"] = &(this->Africa.countries[2]);
	m["East Africa"] = &(this->Africa.countries[3]);
	m["Egypt"] = &(this->Africa.countries[1]);
	m["Madagascar"] = &(this->Africa.countries[5]);
	m["North Africa"] = &(this->Africa.countries[0]);
	m["South Africa"] = &(this->Africa.countries[4]);
	//std::vector< std::string> AS{ "Kamchatka0", "Yakutsk1", "Siberia2", "Irkutsk3", "Mongolia4", "China5", "India6", "Siam7", "Ural8", "Afghanistan9", "Middle East10",japen[11] }; Africa
	m["Afghanistan"] = &(this->Asia.countries[9]);
	m["China"] = &(this->Asia.countries[5]);
	m["India"] = &(this->Asia.countries[6]);
	m["Irkutsk"] = &(this->Asia.countries[3]);
	m["Japan"] = &(this->Asia.countries[11]);
	m["Kamchatka"] = &(this->Asia.countries[0]);
	m["Middle East"] = &(this->Asia.countries[10]);
	m["Mongolia"] = &(this->Asia.countries[4]);
	m["Siam"] = &(this->Asia.countries[7]);
	m["Siberia"] = &(this->Asia.countries[2]);
	m["Ural"] = &(this->Asia.countries[8]);
	m["Yakutsk"] = &(this->Asia.countries[1]);

	//std::vector< std::string> AU{ "Western Australia", "Eastern Australia", "New Gulinea", "Indonesia" }; Australia
	m["Eastern Australia"] = &(this->Australia.countries[0]);
	m["Indonesia"] = &(this->Australia.countries[3]);
	m["New Guinea"] = &(this->Australia.countries[2]);
	m["Western Australia"] = &(this->Australia.countries[1]);


	//SA
	m["Argentina"]->setNehibors({ m["Brazil"], m["Peru"] });
	m["Brazil"]->setNehibors({ m["Peru"], m["Venezuela"], m["Argentina"], m["North Africa"] });
	m["Peru"]->setNehibors({ m["Venezuela"], m["Brazil"] ,m["Argentina"] });
	m["Venezuela"]->setNehibors({ m["Central America"], m["Peru"], m["Brazil"] });
	//eu 
	m["Great Britain"]->setNehibors({ m["Iceland"], m["Scandinavia"], m["Western Europe"], m["Northern Europe"] });
	m["Iceland"]->setNehibors({ m["Greenland"], m["Great Britain"] });
	m["Northern Europe"]->setNehibors({ m["Ukraine"], m["Soutern Europe"],m["Western Europe"],m["Great Britain"] });
	m["Scandinavia"]->setNehibors({ m["Ukraine"], m["Great Britain"] });
	m["Southern Europe"]->setNehibors({ m["North Africa"], m["Egypt"] ,m["Ukraine"] ,m["Western Europe"],m["Northern Europe"] });
	m["Ukraine"]->setNehibors({ m["Scandinavia"], m["Northern Europe"] ,m["Southern Europe"] ,m["Middle East"], m["Ural"],m["Afghanistan"] });
	m["Western Europe"]->setNehibors({ m["North Africa"], m["Southern Europe"] , m["Northern Europe"] , m["Great Britain"] });
	//af
	m["North Africa"]->setNehibors({ m["Brazil"], m["Cango"],m["Egypt"], m["Southern Europe"],  m["Western Europe"] });
	m["Egypt"]->setNehibors({ m["Middle East"], m["Southern Europe"], m["North Africa"], m["Cango"],m["East Africa"] });
	m["Cango"]->setNehibors({ m["South Africa"], m["East Africa"] ,m["Egypt"] ,m["North Africa"] });
	m["East Africa"]->setNehibors({ m["Cango"], m["Egypt"], m["South Africa"],m["Madagascar"] });
	m["South Africa"]->setNehibors({ m["Madagascar"], m["East Africa"] ,m["Cango"] });
	m["Madagascar"]->setNehibors({ m["East Africa"], m["South Africa"] });
	//as 
	m["Afghanistan"]->setNehibors({ m["Ukraine"], m["Middle East"] , m["India"] , m["China"] , m["Ural"] , m["Siberia"] });
	m["China"]->setNehibors({ m["India"], m["Siam"], m["Afghanistan"] , m["Mongolia"]  , m["Siberia"] , m["Ural"] });
	m["India"]->setNehibors({ m["Middle East"], m["Afghanistan"], m["China"], m["Siam"] });
	m["Irkutsk"]->setNehibors({ m["Mongolia"], m["Siberia"] , m["Yakutsk"] , m["Kamchatka"] });
	m["Japan"]->setNehibors({ m["Mongolia"], m["Kamchatka"] });
	m["Kamchatka"]->setNehibors({ m["Irkutsk"], m["Yakutsk"] , m["Mongolia"], m["Japan"],m["Alaska"] });
	m["Middle East"]->setNehibors({ m["India"], m["Afghanistan"] , m["Ukraine"], m["Egypt"] });
	m["Mongolia"]->setNehibors({ m["Japan"], m["China"] , m["Irkutsk"] , m["Siberia"] });
	m["Siam"]->setNehibors({ m["China"], m["India"] , m["Indonesia"] });
	m["Siberia"]->setNehibors({ m["Yakutsk"], m["Irkutsk"], m["Mongolia"], m["China"] , m["Afghanistan"] , m["Ural"] });
	m["Ural"]->setNehibors({ m["Siberia"], m["Ukraine"] , m["Afghanistan"] });
	m["Yakutsk"]->setNehibors({ m["Kamchatka"], m["Irkutsk"], m["Siberia"] });
	//au
	m["Eastern Australia"]->setNehibors({ m["Western Australia"], m["New Guinea"] });
	m["Indonesia"]->setNehibors({ m["Siam"], m["New Guinea"], m["Western Australia"] });
	m["New Guinea"]->setNehibors({ m["Indonesia"], m["Eastern Australia"], m["Western Australia"] });
	m["Western Australia"]->setNehibors({ m["New Guinea"], m["Indonesia"], m["Eastern Australia"] });

	//na 
	m["Alaska"]->setNehibors({ m["Northwest Territory"], m["Kamchatka"] });
	m["Alberta"]->setNehibors({ m["Northwest Territory"], m["Ontario"], m["Western United States"], m["Alaska"] });
	m["Central America"]->setNehibors({ m["Venezuela"], m["Eastern United States"], m["Western United States"] });
	m["Eastern United States"]->setNehibors({ m["Quebec"], m["Ontario"], m["Western United States"], m["Central America"] });
	m["Greenland"]->setNehibors({ m["Northwest Territory"], m["Ontario"], m["Quebec"], m["Iceland"] });
	m["Northwest Territory"]->setNehibors({ m["Alaska"], m["Alberta"], m["Ontario"] });
	m["Ontario"]->setNehibors({ m["Northwest Territory"], m["Alberta"], m["Western United State"], m["Eastern United States"] , m["Quebec"] });
	m["Quebec"]->setNehibors({ m["Ontario"], m["Greenland"], m["Eastern United States"] });
	m["Western United States"]->setNehibors({ m["Alberta"], m["Eastern United States"], m["Ontario"], m["Central America"] });



	this->queue.push(Player());
	this->currentStage = new PlaceMap(this->ui, this->queue.front(), this->moveUi, this->counter);
	ui.textEdit->setText("welocme to the game");
}


void risk::incPlayer()
{
	this->queue.push(this->queue.front());
	this->queue.pop();
	QString picPath = QString("Resources/players/") + QString(this->queue.front().getColor().c_str()) + ".png";
	QPixmap pic(picPath);//("Resources/cubes/1.png");
	this->ui.colorP->setPixmap(pic);
	this->ui.colorP->show();
}

void risk::cardClick(int sel)
{
	this->cards[sel].click();
}

void risk::showMess(std::string txt)
{
	this->mess.setMess(txt);
	this->mess.setFocus();
	this->mess.show();
}

void risk::showTroops()
{
	int bonus = this->queue.front().getBonusTroops();
	QString text = std::to_string(bonus).c_str();
	this->ui.troopsP->setText(text);
}

bool risk::empty() const
{
	return this->queue.empty();
}

void risk::pop()
{
	this->queue.pop();
}

void risk::push(const Player & player)
{
	this->queue.push(player);
}

void risk::initTroops()
{
	//y=-5x+50;		-> this is the real but it is TOO MUCH!
	int troops = -5 * this->numberOfPlayers + 35;
	for (int i = 0; i < this->numberOfPlayers; i++) {
		this->queue.front().setBonusTroops(troops);
		incPlayer();
	}
}

void risk::nextState()
{
	if (this->currentStage->getNexEn() == false)
		return;
	this->currentStage->afterAction();
	if (this->currentStage->getNexEn() == false)//case  draft that you have cards to convert
		return;
	delete this->currentStage;
	if (this->stage == "initial") {
		this->stage = "placeMap";
		this->currentStage = new PlaceMap(this->ui, this->queue.front(), this->moveUi, this->counter);
	}
	else if (this->stage == "placeMap") {
		this->stage = "placeTroops";
		this->currentStage = new PlaceTroops(this->ui, this->queue.front(), this->moveUi, this->counter);
	}
	else if (this->stage == "placeTroops") {
		this->stage = "draft";
		this->currentStage = new Draft(this->ui, this->queue.front(), this->moveUi, this->cards,_maxCardsPerPlayer_);
		std::vector<Land*> lands = { &this->SouthAmerica,
									&this->NorthAmerica,
									&this->Asia,
									&this->Australia,
									&this->Africa,
									&this->Europe,				
		};
		dynamic_cast<Draft*>(this->currentStage)->setLands(lands);

		this->ui.PLUS->disconnect();
		this->ui.MINUS->disconnect();
		QObject::connect(this->ui.PLUS, &QPushButton::clicked, [=] {currentStage->plus(); });
		QObject::connect(this->ui.MINUS, &QPushButton::clicked, [=] {currentStage->minus(); });

		this->ui.card1->disconnect();
		this->ui.card2->disconnect();
		this->ui.card3->disconnect();
		this->ui.card4->disconnect();
		this->ui.card5->disconnect();

		QObject::connect(this->ui.card1, &QPushButton::clicked, [=] {cards[0].click(); });
		QObject::connect(this->ui.card2, &QPushButton::clicked, [=] {cards[1].click(); });
		QObject::connect(this->ui.card3, &QPushButton::clicked, [=] {cards[2].click(); });
		QObject::connect(this->ui.card4, &QPushButton::clicked, [=] {cards[3].click(); });
		QObject::connect(this->ui.card5, &QPushButton::clicked, [=] {cards[4].click(); });

		this->ui.CONVERT->disconnect();
		QObject::connect(this->ui.CONVERT, &QPushButton::clicked, [=] {dynamic_cast<Draft*>(currentStage)->convert(); });
	}
	else if (this->stage == "draft") {
		this->stage = "attack";
		this->ui.CONVERT->disconnect();
		int idx = 0;
		while (this->cards[idx++] != Card(Card::Default));
		idx--;
		this->currentStage = new Attack(this->ui, this->queue.front(), this->moveUi, &(this->cards[idx]));
		this->ui.PLUS->disconnect();
		this->ui.PLUS_2->disconnect();
		this->ui.MINUS->disconnect();
		this->ui.MINUS_2->disconnect();

		QObject::connect(this->ui.PLUS, &QPushButton::clicked, [=] {currentStage->plus(); });
		QObject::connect(this->ui.MINUS, &QPushButton::clicked, [=] {currentStage->minus(); });
		QObject::connect(this->ui.PLUS_2, &QPushButton::clicked, [=] {currentStage->plus(1); });
		QObject::connect(this->ui.MINUS_2, &QPushButton::clicked, [=] {currentStage->minus(1); });

	}
	else if (this->stage == "attack") {
		this->currentStage = new Reinforcement(this->ui, this->queue.front(), this->moveUi);
		this->ui.PLUS->disconnect();
		this->ui.PLUS_2->disconnect();
		this->ui.MINUS->disconnect();
		this->ui.MINUS_2->disconnect();

		QObject::connect(this->ui.PLUS, &QPushButton::clicked, [=] {currentStage->plus(); });
		QObject::connect(this->ui.MINUS, &QPushButton::clicked, [=] {currentStage->minus(); });
		QObject::connect(this->ui.PLUS_2, &QPushButton::clicked, [=] {currentStage->plus(1); });
		QObject::connect(this->ui.MINUS_2, &QPushButton::clicked, [=] {currentStage->minus(1); });

		this->stage = "reinforcement";
	}
	else if (this->stage == "reinforcement") {
		this->stage = "draft";
		this->incPlayer();
		this->currentStage = new Draft(this->ui, this->queue.front(), this->moveUi, this->cards, _maxCardsPerPlayer_);
		std::vector<Land*> lands = { &this->SouthAmerica,
									&this->NorthAmerica,
									&this->Asia,
									&this->Australia,
									&this->Africa,
									&this->Europe,
		};
		dynamic_cast<Draft*>(this->currentStage)->setLands(lands);

		Land::landInfo res = dynamic_cast<Draft*>(this->currentStage)->calcTroops();
		if (res.bonus == -1) {	//player need to be delete.
			this->numberOfPlayers--;
			if (this->numberOfPlayers == 1) {	//won!
				this->queue.pop();
				this->showMess(this->queue.front().getName() + " won!");
				this->saveStatsIn();
			}
			else {
				this->showMess(this->queue.front().getName() + " kicked out! losser..");
				this->saveStatsIn();
				//this->saveStats();
				this->queue.pop();
				return this->updateStage();
			}
		}
		this->ui.PLUS->disconnect();
		this->ui.PLUS_2->disconnect();
		this->ui.MINUS->disconnect();
		this->ui.MINUS_2->disconnect();

		QObject::connect(this->ui.PLUS, &QPushButton::clicked, [=] {currentStage->plus(); });
		QObject::connect(this->ui.MINUS, &QPushButton::clicked, [=] {currentStage->minus(); });
		QObject::connect(this->ui.PLUS_2, &QPushButton::clicked, [=] {currentStage->plus(1); });
		QObject::connect(this->ui.MINUS_2, &QPushButton::clicked, [=] {currentStage->minus(1); });


		this->ui.card1->disconnect();
		this->ui.card2->disconnect();
		this->ui.card3->disconnect();
		this->ui.card4->disconnect();
		this->ui.card5->disconnect();

		QObject::connect(this->ui.card1, &QPushButton::clicked, [=] {cards[0].click(); });
		QObject::connect(this->ui.card2, &QPushButton::clicked, [=] {cards[1].click(); });
		QObject::connect(this->ui.card3, &QPushButton::clicked, [=] {cards[2].click(); });
		QObject::connect(this->ui.card4, &QPushButton::clicked, [=] {cards[3].click(); });
		QObject::connect(this->ui.card5, &QPushButton::clicked, [=] {cards[4].click(); });

		this->ui.CONVERT->disconnect();
		QObject::connect(this->ui.CONVERT, &QPushButton::clicked, [=] {dynamic_cast<Draft*>(currentStage)->convert(); });
	}
	this->currentStage->preAction();
	this->showInfo();
	this->ui.playerText->setText(this->queue.front().getName().c_str());
	this->ui.stageText->setText(this->stage.c_str());
}

void risk::save(std::ofstream& file) {
	file << this->stage << "\n";
	file << this->counter << "\n";
	file << "-----\n";
	file << std::to_string(this->numberOfPlayers) << "\n";
	std::queue<Player> queue = this->queue;
	for (int i = 0; i < this->numberOfPlayers; i++) {
		queue.front().save(file);
		queue.push(this->queue.front());
		queue.pop();
	}
	this->SouthAmerica.save(file);
	this->NorthAmerica.save(file);
	this->Europe.save(file);
	this->Asia.save(file);
	this->Australia.save(file);
	this->Africa.save(file);
}

void risk::load(std::ifstream & file)
{
	std::string tmp;
	//load stage
	file >> this->stage;
	file >> tmp;
	this->counter = std::stoi(tmp);
	file >> tmp;	//dummy

	this->ui.textEdit->setText(QString("welcome to stage:  ") + this->stage.c_str()+ QString("you need to place all your troops in this stage "));
	//load players
	file >> tmp;
	this->numberOfPlayers = std::stoi(tmp);

	while (!this->queue.empty())
		this->queue.pop();

	for (int i = 0; i < this->numberOfPlayers; i++) {
		Player tmp;
		tmp.load(file);
		this->playersMap[tmp.getName()] = tmp;
		this->queue.push(tmp);
	}
	//load Lands
	this->SouthAmerica.load(file, this->playersMap);
	this->NorthAmerica.load(file, this->playersMap);
	this->Europe.load(file, this->playersMap);
	this->Asia.load(file, this->playersMap);
	this->Australia.load(file, this->playersMap);
	this->Africa.load(file, this->playersMap);

	this->updateStage();
}

void risk::saveStats()
{
	QString fileName = QFileDialog::getSaveFileName(this,
		tr("Save Stats"),
		"",
		tr("file (*.csv);;All Files (*)"));

	this->saveStatsIn(fileName.toStdString(),1);
}

void risk::EXIT()
{
	if (this->numberOfPlayers == 1)
	{
		this->saveStatsIn("Resources/stats.csv", 0);
		exit(0);
	}
	this->saveStatsIn("Resources/stats.csv", 1);
	exit(0);
}

PlayerStats* risk::loadStats(std::string fileName)
{
	std::ifstream file;
	file.open(fileName);
	this->stats.loadStats(file);
	file.close();
	return &this->stats;
}

void risk::loadStatsGui()
{
	QString fileName = QFileDialog::getOpenFileName(this,
	tr("Load Game"),
		"",
		tr("file (*.csv);;All Files (*)"));
	this->loadStats(fileName.toStdString());
}

void risk::showInfo()
{
	QString picPath = QString("Resources/players/") + QString(this->queue.front().getColor().c_str()) + ".png";
	QPixmap pic(picPath);//("Resources/cubes/1.png");
	this->ui.colorP->setPixmap(pic);
	this->ui.colorP->show();
}

void risk::updateStage()
{
	this->stage = this->stage2preStage[this->stage];
	this->currentStage->setNextEn(true);
	this->nextState();
}

time_t risk::get_startTime() const
{
	return this->startTime;
}

void risk::set_startTime(const time_t time )
{
	this->startTime = time; 
}

void risk::SAVE_ALL()
{
	this->SAVE();
	this->saveStats();
}
///this function is called in some situation -first it called each time player lose or win.
// second it called when player clicked exit butten.
// it also called whether the path for save it the default and when it isn't-mean the player chose other path
// all variable is flag that send in order to know if the function is called with exit
// then no one lose or win or when player is kicked out or win during the game.
//all is 0 by default and its called with 1 only when clicked exit and its only 1 player-means win.
void risk::saveStatsIn(std::string fileName, bool all)
{
	std::ofstream file;
	file.open(fileName);
	std::queue<Player> queue = this->queue;
	time_t end = std::time(0);
	int elapsed_seconds = end - this->startTime;
	this->startTime = end;
	int len = all ? this->numberOfPlayers : 1;
	int win = 0;	//nutral
	if (this->numberOfPlayers == 1)
		win = 1;	//win
	else if (all == false)
		win = -1; //loose
	for (int i = 0; i < len; ++i) {
		PlayerStatWrap tmp(queue.front(), win, elapsed_seconds);//player,win,time
		
		this->stats.addToStats(tmp);
		queue.pop();
	}
	this->stats.saveStats(file);
	file.close();
}

void risk::SAVE()
{

	QString fileName = QFileDialog::getSaveFileName(this,
		tr("Save Game"),
		"",
		tr("file (*.dudu);;All Files (*)"));
	std::ofstream file;
	file.open(fileName.toStdString());
	this->save(file);
	file.close();

}

void risk::ENTER()
{
	if (Country::chosen == nullptr)
	{
		this->ui.textEdit->setText(QString("please start the game .."));
		return;
	}
	this->currentStage->action();
	if (this->currentStage->getEnterEn() == true && (this->stage == "placeMap" || this->stage == "placeTroops")) {
		this->incPlayer();
		this->updateStage();
		if (this->stage == "placeMap") {
			if (this->counter == this->numberOfCountries) {
				this->currentStage->setNextEn(true);
				this->nextState();	//to placeTroops
			}
		}
		else {
			if (this->counter == (-5 * this->numberOfPlayers + 35)*this->numberOfPlayers) {
				this->currentStage->setNextEn(true);
				this->nextState();	//to draft
			}
		}
	}
}


bool risk::LOAD()
{
	QString fileName = QFileDialog::getOpenFileName(this,
		tr("Load Game"),
		"",
		tr("file (*.dudu);;All Files (*)"));
	if (fileName == "")
		return 0;
	std::ifstream file;
	file.open(fileName.toStdString());
	this->load(file);
	file.close();
	return 1; 
}

char risk::get_number_of_player()
{
	return this->numberOfPlayers;
}

void risk::set_number_of_player(char num )
{
	this->numberOfPlayers = num;
}

