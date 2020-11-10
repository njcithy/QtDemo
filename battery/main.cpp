#include "frmbattery.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    frmbattery w;
    w.show();
    return a.exec();
}
