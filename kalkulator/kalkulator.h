#ifndef KALKULATOR_H
#define KALKULATOR_H

#include <QtWidgets/QMainWindow>
#include "ui_kalkulator.h"

class kalkulator : public QMainWindow
{
	Q_OBJECT

public:
	kalkulator(QWidget *parent = 0);
	~kalkulator();

private:
	Ui::kalkulatorClass ui;
};

#endif // KALKULATOR_H
