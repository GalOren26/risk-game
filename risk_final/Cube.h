#pragma once
#include <QWidget>
#include "ui_menu.h"
#include <string>
#include <iostream>

class Cube {
private:
	QLabel* label;
	static std::string path;
	int rand_value;
public:
	Cube();
	void choosePic(int);
	void setValue(int);
	int getValue() const;

	static void setPath(std::string);

	void setLabel(QLabel*);
	void setPic(std::string);
	void random();
	void hide();
	void show();
	bool operator<(const Cube&) const;
	bool operator>(const Cube&) const;
	bool operator==(const Cube&) const;

};