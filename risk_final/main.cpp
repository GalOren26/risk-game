#include "risk.h"
#include "menu.h"
#include <QtWidgets/QApplication>
#include <qdebug.h>

	int main(int argc, char *argv[])
	try {
			{
				QApplication a(argc, argv);
				menu m;
				m.show();

				return a.exec();
			}
	}
	catch (std::exception& e) {
		qDebug("im here");
	}
