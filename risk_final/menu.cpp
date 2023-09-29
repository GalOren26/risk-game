#include "menu.h"
#include <time.h>
#include "Cube.h"
#include "windows.h."

#include "qmediaplaylist.h"
menu::menu(QWidget * parent) : QWidget(parent), w(4) {
	srand(time(NULL));
	ui.setupUi(this);
	QMediaPlaylist *playlist = new 	QMediaPlaylist();
	playlist->addMedia(QUrl("qrc:/new/Resources/Risk.mp3"));
	playlist->setPlaybackMode(QMediaPlaylist::Loop);
	QMediaPlayer* music = new QMediaPlayer();
	music->setPlaylist(playlist);
	music->play();
	this->defaultStats_ = false;
	QPixmap image("Resources/risk_menu.jpg");
	QLabel imageLabel;
	imageLabel.setPixmap(image);
	imageLabel.show();
	this->toss = false;
	this->numberOfPlayers = 4;
	QObject::connect(this->ui.FINISH, &QPushButton::clicked, [=] {end(); });
	QObject::connect(this->ui.cube, &QPushButton::clicked, [=] {cube(); });
	QObject::connect(this->ui.LOAD, &QPushButton::clicked, [=] {LOAD(); });
	QObject::connect(this->ui.loadStats, &QPushButton::clicked, [=] {loadStats(); });
	cubes[0].setLabel(this->ui.cubeP1);
	cubes[1].setLabel(this->ui.cubeP2);
	cubes[2].setLabel(this->ui.cubeP3);
	cubes[3].setLabel(this->ui.cubeP4);
	for (int i = 0; i < 4; i++)
		cubes[i].hide();
	Cube::setPath("Resources/cubes/");
//	this->ui.cubeP4->setScaledContents(true);
	//QObject::connect(this->ui.spinBox, SIGNAL(QSpinBox::valueChanged()), this,SLOT(spin()));	-> set in the gui.
	this->ui.colorP1->setCurrentIndex(3);
	this->ui.colorP2->setCurrentIndex(2);
	this->ui.colorP3->setCurrentIndex(1);
	this->ui.colorP4->setCurrentIndex(0);
	this->s.setStats(this->w.loadStats()); 

	//this->defaultStats_ = true;
	//this->loadStats();
	//this->s.setStats(this->w.loadStats());
	//this->s == nullptr;
}

menu::~menu() {
	
}
void menu::defalutStats()
{
	this->s.setFocus();
	this->s.show();

	//this->defaultStats_ = true;
	//this->loadStats();
}
void menu::spin(int numberOfPlayers)
{
	this->numberOfPlayers = numberOfPlayers;

	//HIDE
	if (numberOfPlayers < 4) {
		this->ui.groupBox4->hide();
	}
	if (numberOfPlayers < 3) {
		this->ui.groupBox3->hide();
	}

	//SHOW
	if (numberOfPlayers > 3) {
		this->ui.groupBox4->show();
	}
	if (numberOfPlayers > 2) {
		this->ui.groupBox3->show();
	}

}

void menu::cube()
{
	this->toss = true;
	std::string num2str[] = { "first", "second", "third", "fourth" };
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
			hist[i][j] = nullptr;
	}
	int iD = std::stoi(this->ui.idP1->toPlainText().toStdString());
	players[0] = Player(this->ui.nameP1->toPlainText().toStdString(), this->ui.colorP1->currentText().toStdString(), 0,iD);
	players[1] = Player(this->ui.nameP2->toPlainText().toStdString(), this->ui.colorP2->currentText().toStdString(), 0,std::stoi(this->ui.idP2->toPlainText().toStdString()));
	players[2] = Player(this->ui.nameP3->toPlainText().toStdString(), this->ui.colorP3->currentText().toStdString(), 0, std::stoi(this->ui.idP3->toPlainText().toStdString()));
	players[3] = Player(this->ui.nameP4->toPlainText().toStdString(), this->ui.colorP4->currentText().toStdString(), 0, std::stoi(this->ui.idP4->toPlainText().toStdString()));
	while (!this->w.empty())
		this->w.pop();
	
	for (int i = 0; i < this->numberOfPlayers; i++) {
		this->cubes[i].random();
	}
	for (int i = 0; i < this->numberOfPlayers; i++)
	{
		int j = 0;
		while (hist[this->cubes[i].getValue() - 1][j]) j++;
		hist[this->cubes[i].getValue() - 1][j] = &this->players[i];
	}
	int id = 1; 
	for (int i = 5; i >= 0; i--)
	{
		int len = 0;
		while (hist[i][len]) len++;
		if (len == 0) continue;
		while (len)
		{
			hist[i][len-1]->SetOrder(id);
			this->w.push(*hist[i][len-1]);
			id++;
			len--;
		}
	}

	this->ui.pic1_ord->setText(num2str[this->players[0].GetOrder()-1].c_str());
	this->ui.pic2_ord->setText(num2str[this->players[1].GetOrder() - 1].c_str());
	if (this->numberOfPlayers > 2) {
		this->ui.pic3_ord->setText(num2str[this->players[2].GetOrder() - 1].c_str());
	}
	if (this->numberOfPlayers > 3) {
		this->ui.pic4_ord->setText(num2str[this->players[3].GetOrder() - 1].c_str());
	}
}

void menu::LOAD()
{
	if (!this->w.LOAD())
		return;
	this->close();
	this->w.setFocus();
	this->w.show();
}

void menu::loadStats()
{
	//if(this->s != nullptr)
	//	this->s.clear();
	if (this->defaultStats_ == true) {
		this->s.setStats(this->w.loadStats());
		this->s.setFocus();
		this->s.show();
		return;
	}
	QString fileName = QFileDialog::getOpenFileName(this,
		tr("Load Game"),
		"",
		tr("file (*.csv);;All Files (*)"));
	if (fileName == "")
		return;
	this->s.setStats(this->w.loadStats(fileName.toStdString()));
	this->s.setFocus();
	this->s.show();
}


void menu::end() {
	if (this->toss == false) {
		this->ui.info->setText("I see you got NA education .. \nplease toss the cubes!");
		return;
	}
	this->w.set_number_of_player(this->numberOfPlayers);
	this->close();
	this->w.showInfo();
	this->w.initTroops();
	this->w.showTroops();
	this->w.set_startTime(std::time(0));
	this->w.updateStage();
	this->w.setFocus();
	this->w.show();
}