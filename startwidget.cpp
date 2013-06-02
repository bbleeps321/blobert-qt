#include "startwidget.h"

StartWidget::StartWidget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    connect(ui.exitButton, SIGNAL(clicked()), this, SIGNAL(exitTriggered()));
}

