#pragma once
#include <QWidget>
#include "ui_Mess.h"
#include  <QObject>
//#include "ui_Mess.h"

class Mess : public QWidget {
	Q_OBJECT

public:
	Mess(QWidget * parent = Q_NULLPTR);
	~Mess();
	void setMess(std::string str);
private:
	Ui::mess_gui ui;
	

};