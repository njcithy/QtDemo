#include "frmbattery.h"
#include "ui_frmbattery.h"

frmbattery::frmbattery(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::frmbattery)
{
    ui->setupUi(this);
}

frmbattery::~frmbattery()
{
    delete ui;
}

