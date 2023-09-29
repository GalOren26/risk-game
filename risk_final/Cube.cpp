#include "Cube.h"
#include "Vector.h"
std::string Cube::path;
void Cube::choosePic(int num)
{

	QPixmap pic(QString(this->path.c_str()) + QString(num + '0') + ".png");//("Resources/cubes/1.png");
	label->setPixmap(pic);
	label->show();
}
void Cube::setValue(int rand_val)
{
	this->rand_value = rand_val;
}
int Cube::getValue() const
{
	return this->rand_value;
}
Cube::Cube()
{
	this->rand_value = -1;
}

void Cube::setPath(std::string path)
{
	Cube::path = path;
}


void Cube::setLabel(QLabel * label)
{
	this->label = label;
	this->label->setVisible(true);
}

void Cube::setPic(std::string str)
{

	QPixmap pic(str.c_str());//("Resources/cubes/1.png");
	label->setPixmap(pic);

	label->show();
}

void Cube::random()
{
	this->rand_value = std::rand() % 6 + 1;
	this->choosePic(this->rand_value);
}

void Cube::hide()
{
	{
		this->label->setVisible(false);
	}
}

void Cube::show()
{
	this->label->setVisible(true);
}

bool Cube::operator<(const Cube & rhs) const
{
	return this->rand_value < rhs.rand_value;
}

bool Cube::operator>(const Cube & rhs) const
{
	return this->rand_value > rhs.rand_value;
}

bool Cube::operator==(const Cube & rhs) const
{
	return this->rand_value == rhs.rand_value;
}
