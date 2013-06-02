#ifndef STARTWIDGET_H
#define STARTWIDGET_H

#include <QtGui>
#include "ui_startwidget.h"

class StartWidget : public QWidget
{
	Q_OBJECT

public:
    StartWidget(QWidget *parent = 0);

private slots:


signals:
    void exitTriggered();

private:
	Ui::StartWidget ui;
};

#endif
