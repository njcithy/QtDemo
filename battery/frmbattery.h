#ifndef FRMBATTERY_H
#define FRMBATTERY_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class frmbattery; }
QT_END_NAMESPACE

class frmbattery : public QWidget
{
    Q_OBJECT

public:
    frmbattery(QWidget *parent = nullptr);
    ~frmbattery();

private:
    Ui::frmbattery *ui;
};
#endif // FRMBATTERY_H
