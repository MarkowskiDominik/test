#include "kalkulator.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	kalkulator w;
	w.show();
	return a.exec();
}
